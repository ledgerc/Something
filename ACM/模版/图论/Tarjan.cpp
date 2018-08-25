//Tarjan
//O(N+M)

struct Edge{
	int to,next;
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];//Belong数组的值是1~scc 
int Index,top;
int scc;//强连通分量的个数 
bool Instack[maxn];
int num[maxn];//各个强连通分量包含点的个数，数组编号1~scc 不一定需要 
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void Tarjan(int u){
	int v;
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=true;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		v=edge[i].to;
		if(!DFN[v]){
			Tarjan(v);
			if(Low[u]>Low[v])
				Low[u]=Low[v]; 
		}
		else if(Instack[v]&&Low[u]>DFN[v])
			Low[u]=DFN[v];
	}
	if(Low[u]==DFN[u]){
		scc++;
		do{
			v=Stack[--top];
			Instack[v]=false;
			Belong[v]=scc;
			num[scc]++;
		}
		while(v!=u);
	}
}
void solve(int N){
	memset(DFN,0,sizeof DFN);
	memset(Instack,false,sizeof Instack);
	memset(num,0,sizeof num);
	Index=scc=top=0;
	for(int i=1; i<=N; i++)
		if(!DFN[i])
			Tarjan(i);
}
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}






//UVA315
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
/*
*  求 无向图的割点和桥
*  可以找出割点和桥，求删掉每个点后增加的连通块。
*  需要注意重边的处理，可以先用矩阵存，再转邻接表，或者进行判重
*/
const int MAXN = 10010;
const int MAXM = 100010;
struct Edge{
    int to,next;
    bool cut;//是否为桥的标记
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn];
int Index,top;
bool Instack[maxn];
bool cut[maxn];
int add_block[maxn];//删除一个点后增加的连通块
int bridge;
void addedge(int u,int v){
    edge[tot].to = v;edge[tot].next = head[u];edge[tot].cut = false;
    head[u] = tot++;
}
void Tarjan(int u,int pre){
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    for(int i = head[u];i != -1;i = edge[i].next){
        v = edge[i].to;
        if(v == pre)continue;
        if( !DFN[v] ){
            son++;
            Tarjan(v,u);
            if(Low[u] > Low[v])
				Low[u] = Low[v];
            //桥
            //一条无向边(u,v)是桥，当且仅当(u,v)为树枝边，且满足DFS(u)<Low(v)。
            if(Low[v] > DFN[u]){
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
            //割点
            //一个顶点u是割点，当且仅当满足(1)或(2) (1) u为树根，且u有多于一个子树。
            //(2) u不为树根，且满足存在(u,v)为树枝边(或称父子边，
            //即u为v在搜索树中的父亲)，使得DFS(u)<=Low(v)
            if(u != pre && Low[v] >= DFN[u]){//不是树根
                cut[u] = true;
                add_block[u]++;
            }
        }
        else if( Low[u] > DFN[v])
             Low[u] = DFN[v];
    }
    //树根，分支数大于1
    if(u == pre && son > 1)
		cut[u] = true;
    if(u == pre)
		add_block[u] = son - 1;
    Instack[u] = false;
    top--;
}
void solve(int N){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(add_block,0,sizeof(add_block));
    memset(cut,false,sizeof(cut));
    Index = top = 0;
    bridge = 0;
    for(int i = 1;i <= N;i++)
       if(!DFN[i])
          Tarjan(i,i);
    int ans = 0;
    for(int i = 1;i <= N;i++)
       if(cut[i])
          ans++;
    printf("%d\n",ans);
}
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
int g[110][110];
char buf[1010];
int main(){
    int n;
    while(scanf("%d",&n)==1 && n){
        gets(buf);
        memset(g,0,sizeof(g));
        while(gets(buf)){
            if(strcmp(buf,"0")==0)break;
            char *p = strtok(buf," ");
            int u;
            sscanf(p,"%d",&u);
            p = strtok(NULL," ");
            int v;
            while(p){
                sscanf(p,"%d",&v);
                p = strtok(NULL," ");
                g[u][v]=g[v][u]=1;
            }
        }
        init();
        for(int i = 1;i <= n;i++)
           for(int j = i+1;j <= n;j++)
              	if(g[i][j]){
                  addedge(i,j);
                  addedge(j,i);
            	}
        solve(n);
    }
    return 0;
}



struct node {
    int v,next;
}edge[1001];
int DFN[1001],LOW[1001];
int stack[1001],heads[1001],visit[1001],cnt,tot,index;
void add(int x,int y)
{
    edge[++cnt].next=heads[x];
    edge[cnt].v = y;
    heads[x]=cnt;
    return ;    
}
void tarjan(int x)//代表第几个点在处理。递归的是点。
{
    DFN[x]=LOW[x]=++tot;// 新进点的初始化。
    stack[++index]=x;//进站
    visit[x]=1;//表示在栈里
    for(int i=heads[x];i!=-1;i=edge[i].next)
    {
        if(!DFN[edge[i].v]) {//如果没访问过
            tarjan(edge[i].v);//往下进行延伸，开始递归
            LOW[x]=min(LOW[x],LOW[edge[i].v]);//递归出来，比较谁是谁的儿子／父亲，就是树的对应关系，涉及到强连通分量子树最小根的事情。
        }
        else if(visit[edge[i].v ]){  //如果访问过，并且还在栈里。
            LOW[x]=min(LOW[x],DFN[edge[i].v]);//比较谁是谁的儿子／父亲。就是链接对应关系
        }
    }
    if(LOW[x]==DFN[x]) //发现是整个强连通分量子树里的最小根。
    {
        do{
            printf("%d ",stack[index]);
            visit[stack[index]]=0;
            index--;
        }while(x!=stack[index+1]);//出栈，并且输出。
        printf("\n");
    }
    return ;
}
int main()
{
    memset(heads,-1,sizeof(heads));
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++)
         if(!DFN[i])  tarjan(i);//当这个点没有访问过，就从此点开始。防止图没走完
    return 0;
}
