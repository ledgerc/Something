#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4+7;
const int maxm = 1e5+7;
const double pi = acos(-1.0);

int T,n,m;
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
vector<int> e[maxn];
int in[maxn];
int cnt[maxn];
bool vis[maxn];
int sum;
void init(int n){
	tot=0;
	memset(head,-1,sizeof head);
	memset(in,0,sizeof in);
	memset(cnt,0,sizeof cnt);
	for(int i=0; i<=n; i++)
		e[i].clear();
}
void dfs(int u){
	vis[u]=true;
	sum+=num[u];
	for(int i=0; i<e[u].size(); i++)
		if(!vis[e[u][i]])
			dfs(e[u][i]);
}
int main(){
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=0; i<m; i++){
			int u,v; scanf("%d%d",&u,&v);
			addedge(u+1,v+1);
		}
		solve(n);
		
		for(int u=1; u<=n; u++){
			for(int i=head[u]; i!=-1; i=edge[i].next){
				int v=edge[i].to;
				if(Belong[u]!=Belong[v]){
					e[Belong[v]].push_back(Belong[u]);
					in[Belong[u]]++;
				}
			}
		}
		int mx=-1;
		for(int i=1; i<=scc; i++){
			if(in[i]==0){
				memset(vis,false,sizeof vis);
				sum=0;
				dfs(i);
				cnt[i]=sum;
				mx=max(mx,sum);
			}
		}
		//for(int i=1; i<=scc; i++)
		//	PR(cnt[i])
		bool flag=false;
		printf("Case %d: %d\n",kase,mx-1);
		for(int i=1; i<=n; i++){
			if(cnt[Belong[i]]==mx){
				if(!flag){
					printf("%d",i-1);
					flag=true;
				}
				else
					printf(" %d",i-1);
			}
		}
		printf("\n");
	}
	return 0;
}
