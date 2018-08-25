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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


struct qnode{
	int v;
	int c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
bool vis[maxn];
int dist[maxn];
void Dijkstra(int n,int start){//点的编号从1开始
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
			int v=E[tmp.v][i].v;
			int cost=E[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
}
int main(){
	int u,v,w,n=-1;
	while(scanf("%d%d%d",&u,&v,&w)!=EOF){
		n=max(n,u); n=max(n,v);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	Dijkstra(n,1);
	int mxid,mx=-1;
	for(int i=1; i<=n; i++){
		if(mx<dist[i]){
			mxid=i;
			mx=dist[i];
		}
	}
	Dijkstra(n,mxid);
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=max(ans,dist[i]);
	printf("%d\n",ans);
	return 0;
}
