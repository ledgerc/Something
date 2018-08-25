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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
const int MAXN = 1e6+7;

struct qnode {  
	ll v;  ll c;
	qnode(ll _v=0,ll _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const  {   return c>r.c;  }
}; 
struct Edge {  
	ll v,cost;
	Edge(ll _v=0,ll _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
ll dist[MAXN];
void Dijkstra(int n,int start){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++) dist[i]=INF;
	priority_queue<qnode>que;
	while(!que.empty()) que.pop();
	dist[start]=0;
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty())  {
		tmp=que.top();   
		que.pop();   
		ll u=tmp.v;   
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<E[u].size();i++){
			ll v=E[tmp.v][i].v;    
			ll cost=E[u][i].cost;    
			if(!vis[v]&&dist[v]>dist[u]+cost)    {     
				dist[v]=dist[u]+cost;     
				que.push(qnode(v,dist[v]));    
			}
		}  
	} 
} 
void addedge(ll u,ll v,ll w) {  E[u].push_back(Edge(v,w)); } 
 
int main(){
	int T; sc(T);
	while(T--){
		ll n,k,m,x,s;
		scanf("%lld%lld%lld%lld%lld",&n,&k,&x,&m,&s);
		for(int i=0; i<=n; i++)
			E[i].clear();
		for(ll i=1; i<=k; i++)
			for(ll j=1; j<=k; j++){
				if(i==j)
					continue;
				addedge(i,j,x);
			}
		ll u,v,w;
		for(int i=0; i<m; i++){
			scanf("%lld%lld%lld",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		Dijkstra(n,s);
		for(int i=1; i<n; i++)
			cout<<dist[i]<<" ";
		cout<<dist[n]<<endl;
	}
}
