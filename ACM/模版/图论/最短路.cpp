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

/*
SPFA 
*/
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
}
bool vis[maxn];//在队列标志
int cnt[maxn];//每个点的入队列次数
int dis[maxn];
bool SPFA(int start,int n){
	memset(vis,false,sizeof vis);
	for(int i=1; i<=n; i++)
		dis[i]=inf;
	vis[start]=true;
	dis[start]=0;
	queue<int> que;
	while(!que.empty())
		que.pop();
	que.push(start);
	memset(cnt,0,sizeof cnt);
	cnt[start]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		vis[u]=false;
		for(int i=0; i<E[u].size(); i++){
			int v=E[u][i].v;
			if(dis[v]>dis[u]+E[u][i].cost){
				dis[v]=dis[u]+E[u][i].cost;
				if(!dis[v]){
					vis[v]=true;
					que.push(v);
					if(++cnt[v]>n)
						return false;
					//cnt[i]为入队列次数，用来判定是否存在负环回路 
				}
			}
		}
	}
	return true;
}




/*
堆 
*/
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
