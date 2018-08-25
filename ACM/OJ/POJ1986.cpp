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
#include<stack>
#include<cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Edge{
	int u,v,w;
	int next;
}edge[maxn];
int tot,head[maxn];
void addedge(int u,int v,int w){
	edge[tot].u=u; edge[tot].v=v; edge[tot].w=w;
	edge[tot].next=head[u]; head[u]=tot++;
}
bool vis[maxn];
int vs[2*maxn];//dfs访问节点的顺序 
int dep[2*maxn];//dfs访问节点的顺序(vs)对应的深度 
int first[maxn];//每个节点第一次访问的编号 
int dis[maxn];//每个节点到根的距离
int tol;
void dfs(int u,int depth){
	vis[u]=true;
	vs[++tol]=u; first[u]=tol; dep[tol]=depth;
	for(int i=head[u]; i!=-1; i=edge[i].next){
	//	cout<<"-1-1"<<endl;
		if(!vis[edge[i].v]){
			int v=edge[i].v,w=edge[i].w;
			dis[v]=dis[u]+w;
			dfs(v,depth+1);
			vs[++tol]=u;
			dep[tol]=depth;
		}
	}
}
int dp[2*maxn][25];
void ST(int n){
	for(int i=1; i<=n; i++)
		dp[i][0]=i;
	for(int j=1; (1<<j)<=n; j++)
		for(int i=1; i+(1<<j)-1<=n; i++){
			int a=dp[i][j-1],b=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=dep[a]<dep[b]?a:b;
		}
}
int RMQ(int l,int r){
	int k=0;
	while((1<<(k+1))<=r-l+1)
		k++;
	int a=dp[l][k],b=dp[r-(1<<k)+1][k];
	return dep[a]<dep[b]?a:b;
}
int LCA(int u,int v){
	int tmp1=first[u],tmp2=first[v];
	if(tmp1>tmp2)
		swap(tmp1,tmp2);
	int res=RMQ(tmp1,tmp2);
	return vs[res];
}
void init(){
	memset(head,-1,sizeof head);
	memset(vis,false,sizeof vis);
	tot=tol=0;
}
int main(){
	int n,m;
	int s[10]; 
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		int u,v,w;
		while(m--){
			scanf("%d%d%d%s",&u,&v,&w,s);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dis[1]=0;
		dfs(1,1);
		ST(tol);
		int q; cin>>q;
		while(q--){
			scanf("%d%d",&u,&v);
			int lca=LCA(u,v);
			printf("%d\n",dis[u]+dis[v]-2*dis[lca]);
		}
	}
	return 0;
	return 0;
} 
