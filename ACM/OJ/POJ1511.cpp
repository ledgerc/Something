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
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
SPFA 
*/
struct Edge{
	int v;
	ll cost;
	Edge(int _v=0,ll _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
vector<Edge> E2[maxn];
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
}
void addedge2(int u,int v,int w){
	E2[u].push_back(Edge(v,w));
}
bool vis[maxn];//在队列标志
ll d[maxn];
bool SPFA(int s,int n){
	queue<int> q;
	q.push(s);
	for(int i=0; i<=n; i++)
		d[i]=inf;
	d[1]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0; i<E[u].size(); i++){
			int v=E[u][i].v,w=E[u][i].cost;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push(v);
			}
		}
	}
}
bool SPFA2(int s,int n){
	queue<int> q;
	q.push(s);
	for(int i=1; i<=n; i++)
		d[i]=inf;
	d[1]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0; i<E2[u].size(); i++){
			int v=E2[u][i].v,w=E2[u][i].cost;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push(v);
			}
		}
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		int u,v,w;
		memset(E,0,sizeof E);
		memset(E2,0,sizeof E2);
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge2(v,u,w);
		}
		ll ans=0;
		SPFA(1,n);
		for(int i=1; i<=n; i++)
			ans+=(ll)d[i];
		SPFA2(1,n);
		for(int i=1; i<=n; i++)
			ans+=(ll)d[i];
		cout<<ans<<endl;
	}
	return 0;
}
