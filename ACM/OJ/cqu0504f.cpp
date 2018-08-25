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
const int maxn = 3e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
ll ans;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
}
ll w[maxn];
ll dmax[maxn],dmin[maxn];
ll ddmax[maxn],ddmin[maxn];
ll umax[maxn],umin[maxn];
void dfs(int u,int pre){
	dmax[u]=dmin[u]=w[u];
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v==pre)
			continue;
		dfs(v,u);
		dmax[u]=max(dmax[u],dmax[u]+dmax[v]);
		dmin[u]=min(dmin[u],dmin[u]+dmin[v]);
	}
}
void dfs2(int u,int pre){
	ddmax[u]=dmax[u]; ddmin[u]=dmin[u];
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v==pre)
			continue;
		umax[v]=0;
		if(umax[u]>0)
			umax[v]+=umax[u];
		umax[v]+=dmax[u];
		if(dmax[v]>0)
			umax[v]-=dmax[v];
		
		umin[v]=0;
		if(umin[u]<0)
			umin[v]+=umin[u];
		umin[v]+=dmin[u];
		if(dmin[v]<0)
			umin[v]-=dmin[v];
		
		dfs2(v,u);

		ddmax[u]=max(ddmax[u],ddmax[v]);
		ddmin[u]=min(ddmin[u],ddmin[v]);
	}
}
void dfs3(int u,int pre){
	if(u!=pre)
		ans=max(ans,max(umin[u]*ddmin[u],umax[u]*ddmax[u]));
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v==pre)
			continue;
		dfs3(v,u);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		init(); ans=-INF;
		for(int i=1; i<=n; i++)
			scanf("%lld",&w[i]);
		for(int i=1; i<n; i++){
			int u,v; scanf("%d%d",&u,&v);
			addedge(u,v); addedge(v,u);
		}
		dfs(1,-1);
		dfs2(1,-1);
		dfs3(1,-1);
		printf("%lld\n",ans);
	}
	return 0;
}
