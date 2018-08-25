#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
const int MAXN = 5010;
const int MAXM = 20010;
struct Edge{
    int to,next;
    bool cut;//是否为桥的标记
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int block;
bool Instack[MAXN];
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
    for(int i = head[u];i != -1;i = edge[i].next){
        v = edge[i].to;
        if(v == pre)
			continue;
        if( !DFN[v] ){
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
        }
        else if( Low[u] > DFN[v])
             Low[u] = DFN[v];
    }
    if(Low[u]==DFN[u]){
    	block++;
    	do{
    		v=Stack[--top];
    		Instack[v]=false;
    		Belong[v]=block;
		}while(v!=u);
	}
}
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
int du[MAXN];
void solve(int n){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index = top = block = 0;
    Tarjan(1,0);
    int ans=0;
    for(int i=1; i<=n; i++)
    	for(int j=head[i]; j!=-1; j=edge[j].next)
    		if(edge[j].cut)
    			du[Belong[i]]++;
    for(int i=1; i<=block; i++)
    	if(du[i]==1)
    		ans++;
    printf("%d\n",(ans+1)/2);
}
int main(){
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)==2){
    	init();
    	while(m--){
    		scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u); 
		}
		solve(n);
	}
	return 0;
}
