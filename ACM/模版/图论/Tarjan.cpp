//Tarjan
//O(N+M)

struct Edge{
	int to,next;
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];//Belong�����ֵ��1~scc 
int Index,top;
int scc;//ǿ��ͨ�����ĸ��� 
bool Instack[maxn];
int num[maxn];//����ǿ��ͨ����������ĸ�����������1~scc ��һ����Ҫ 
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
*  �� ����ͼ�ĸ�����
*  �����ҳ������ţ���ɾ��ÿ��������ӵ���ͨ�顣
*  ��Ҫע���رߵĴ����������þ���棬��ת�ڽӱ����߽�������
*/
const int MAXN = 10010;
const int MAXM = 100010;
struct Edge{
    int to,next;
    bool cut;//�Ƿ�Ϊ�ŵı��
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn];
int Index,top;
bool Instack[maxn];
bool cut[maxn];
int add_block[maxn];//ɾ��һ��������ӵ���ͨ��
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
            //��
            //һ�������(u,v)���ţ����ҽ���(u,v)Ϊ��֦�ߣ�������DFS(u)<Low(v)��
            if(Low[v] > DFN[u]){
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
            //���
            //һ������u�Ǹ�㣬���ҽ�������(1)��(2) (1) uΪ��������u�ж���һ��������
            //(2) u��Ϊ���������������(u,v)Ϊ��֦��(��Ƹ��ӱߣ�
            //��uΪv���������еĸ���)��ʹ��DFS(u)<=Low(v)
            if(u != pre && Low[v] >= DFN[u]){//��������
                cut[u] = true;
                add_block[u]++;
            }
        }
        else if( Low[u] > DFN[v])
             Low[u] = DFN[v];
    }
    //��������֧������1
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
void tarjan(int x)//����ڼ������ڴ����ݹ���ǵ㡣
{
    DFN[x]=LOW[x]=++tot;// �½���ĳ�ʼ����
    stack[++index]=x;//��վ
    visit[x]=1;//��ʾ��ջ��
    for(int i=heads[x];i!=-1;i=edge[i].next)
    {
        if(!DFN[edge[i].v]) {//���û���ʹ�
            tarjan(edge[i].v);//���½������죬��ʼ�ݹ�
            LOW[x]=min(LOW[x],LOW[edge[i].v]);//�ݹ�������Ƚ�˭��˭�Ķ��ӣ����ף��������Ķ�Ӧ��ϵ���漰��ǿ��ͨ����������С�������顣
        }
        else if(visit[edge[i].v ]){  //������ʹ������һ���ջ�
            LOW[x]=min(LOW[x],DFN[edge[i].v]);//�Ƚ�˭��˭�Ķ��ӣ����ס��������Ӷ�Ӧ��ϵ
        }
    }
    if(LOW[x]==DFN[x]) //����������ǿ��ͨ�������������С����
    {
        do{
            printf("%d ",stack[index]);
            visit[stack[index]]=0;
            index--;
        }while(x!=stack[index+1]);//��ջ�����������
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
         if(!DFN[i])  tarjan(i);//�������û�з��ʹ����ʹӴ˵㿪ʼ����ֹͼû����
    return 0;
}
