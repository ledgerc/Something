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

//¶Ñ
int n,m,s;
struct edge{
	int to,cost;
};
typedef pair<int ,int> P; 
int v;
vector<edge> g1[maxn],g[maxn];
int d[maxn];
int d1[maxn];
void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d,d+v,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top(); que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0; i<g[v].size(); i++){
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
void dijkstra1(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d1,d1+v,INF);
	d1[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top(); que.pop();
		int v=p.second;
		if(d1[v]<p.first)
			continue;
		for(int i=0; i<g1[v].size(); i++){
			edge e=g1[v][i];
			if(d1[e.to]>d1[v]+e.cost){
				d1[e.to]=d1[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main(){
	int T; cin>>T;
	while(T--){
		int u,v,w; scanf("%d%d%d",&n,&m,&s);
		edge tmp;
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&u,&v,&w);
			tmp.to=v; tmp.cost=w;
			g[u].push_back(tmp);
			tmp.to=u; tmp.cost=w;
			g1[v].push_back(tmp);
		}
		v=n;
		dijkstra(s);
		dijkstra1(s);
		int ans=inf;
		for(int i=1; i<=n; i++){
			cout<<d[i]<<" "<<d1[i]<<endl;
			if(i!=s){
				ans=min(d[i]+d1[i],ans);
			}
		}
	//	cout<<ans<<endl;
	}
	return 0;
}
