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

struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn];
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
}
bool vis[maxn];
int cnt[maxn];
int dist[maxn];
bool SPFA(int start,int n){
	memset(vis,false,sizeof(vis));
	memset(dist,inf,sizeof dist);
	vis[start]=true;
	dist[start]=0;
	queue<int>que;
	while(!que.empty())
		que.pop();
	que.push(start);
	memset(cnt,0,sizeof(cnt));
	cnt[start]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		vis[u]=false;
		for(int i=0; i<E[u].size(); i++){
			int v=E[u][i].v;
			if(dist[v]>dist[u]+E[u][i].cost){
				dist[v]=dist[u]+E[u][i].cost;
				if(!vis[v]){
					vis[v]=true;
					que.push(v);
					if(++cnt[v]>n)
						return false;
				}
			}
		}
	}
	return true;
} 
