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
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],tot;
void addedge(int u,int v,int w){
	edge[tot].to=v; edge[tot].w=w; edge[tot].next=head[u];
	head[u]=tot++;
}

int n,k,ans,root,num;
//子树的规模  子节点中最大的size 
int size[maxn],mx[maxn],mi,dis[maxn];
int vis[maxn];//顶点是否被作为重心删除的标志 
//计算子树的大小 
void dfssize(int u,int fa){
	size[u]=1;
	mx[u]=0;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa&&!vis[v]){
			dfssize(v,u);
			size[u]+=size[v];
			if(size[v]>mx[u])
				mx[u]=size[v];
		}
	}
}
//查找重心 
void dfsroot(int r,int u,int fa){
	if(size[r]-size[u]>mx[u])
		mx[u]=size[r]-size[u];
	if(mx[u]<mi)
		mi=mx[u],root=u;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa&&!vis[v])
			dfsroot(r,v,u);
	}
}
//计算子树中所有顶点到中心的距离 
void dfsdis(int u,int d,int fa){
	dis[num++]=d;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa&&!vis[v])
			dfsdis(v,d+edge[i].w,u);
	}
}
//统计不超过k的顶点对的个数 
int calc(int u,int d){
	int ret=0;
	num=0;
	dfsdis(u,d,0);
	sort(dis,dis+num);
	int i=0,j=num-1;
	while(i<j){
		if(dis[i]+dis[j]<k)
			i++;
		else if(dis[i]+dis[j]>k)
			j--;
		else{
			if(dis[i]==dis[j]){
				ret+=(j-i)*(j-i+1)/2;
				break;
			}
			int st=i,ed=j;
			while(dis[st]==dis[i]) st++;
			while(dis[ed]==dis[j]) ed--;
			ret+=(st-i)*(j-ed);
			i=st,j=ed;
		} 
	}
	return ret;
	return ret;
}
//对于顶点u所在的子树，查找重心并分割求解 
void dfs(int u){
	mi=n;
	dfssize(u,0);
	dfsroot(u,u,0);
	ans+=calc(root,0);
	vis[root]=1;
	for(int i=head[root]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]){
			ans-=calc(v,edge[i].w);
			dfs(v);
		}
	}
}
void init(){
	memset(head,-1,sizeof head);
	memset(vis,false,sizeof vis);
	tot=ans=0;
}
void solve(){
	memset(vis,false,sizeof vis);
	ans=0;
	dfs(1);
	if(ans>0)
		printf("AYE\n");
	else
		printf("NAY\n");
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		if(!n) break;
		init(); int u,v,w;
		for(int i=1; i<=n; i++){
			while(scanf("%d",&v)&&v){
				scanf("%d",&w);
				addedge(i,v,w);
				addedge(v,i,w);
			}
		}
		while(scanf("%d",&k)!=EOF&&k)
			solve();
		printf(".\n");
	}
	return 0;
	return 0;
}
