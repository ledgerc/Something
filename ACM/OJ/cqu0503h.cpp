#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<bitset>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<cctype>
#define PRI(x) cout<<#x<<": "<<x<<endl;
#define sc(x) scanf("%d",&x);
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,k;
struct qnode{
	int v,c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;
	}
};
struct Edge{
	int v,cost;
	int cap;
	Edge(int _v=0,int _cost=0,int _cap=0):v(_v),cost(_cost),cap(_cap){}
};
vector<Edge>E[maxn];
bool vis[maxn];
int dist[maxn];
void Dijkstra(int n,int start,int mxcap){
	memset(vis,false,sizeof(vis));
	for(int i=1; i<=n; i++)
		dist[i]=inf;
	priority_queue<qnode>que;
	while(!que.empty())
		que.pop();
	dist[start]=0;
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty()){
		tmp=que.top();
		que.pop();
		int u=tmp.v;
		if(vis[u])
			continue;
		vis[u]=true;
		for(int i=0; i<E[u].size(); i++){
		//	PRI(E[u][i].cap)
		//	PRI(mxcap)
			if(E[u][i].cap<mxcap)
				continue;
			int v=E[tmp.v][i].v;
			int cost=E[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void addedge(int u,int v,int w,int cap){
	E[u].push_back(Edge(v,w,cap));
} 

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		int mx=-1;
		for(int i=0; i<=n; i++)
			E[i].clear();
		for(int i=0; i<m; i++){
			int u,v,w,cap; scanf("%d%d%d%d",&u,&v,&cap,&w);
			addedge(u,v,w,cap);
			addedge(v,u,w,cap);
			mx=max(mx,cap);
		}
	//	PRI(mx)
		int l=0,r=mx,ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			Dijkstra(n,1,mid);
			if(dist[n]<=k){
				l=mid+1;
				ans=mid;
			}
			else
				r=mid-1;
		}
		if(ans==-1)
			printf("Poor RunningPhoton!\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
