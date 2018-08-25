#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int g[maxn][maxn];
int flow[maxn][maxn];
int path[maxn];
int a[maxn];
int n;
int maxflow(){
	queue<int> q;
	memset(flow,0,sizeof flow);
	int max_flow=0;
	while(1){
		memset(a,0,sizeof a);
		a[1]=inf;
		while(!q.empty())
			q.pop();
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v=1; v<=n; v++)
				if(!a[v]&&flow[u][v]<g[u][v]){
					path[v]=u;
					a[v]=min(a[u],g[u][v]-flow[u][v]);
					q.push(v);
				}
		}
		if(a[2]==0)
			break;
		for(int u=2; u!=1; u=path[u]){
			flow[path[u]][u]+=a[2];
            flow[u][path[u]]-=a[2];
		}
		max_flow+=a[2];
	}
	return max_flow;
}

const int MAXM = 550;
int x[MAXM],y[MAXM];
int m;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0)
			break;
		memset(g,0,sizeof g);
		for(int i=0; i<m; i++){
			scanf("%d%d",&x[i],&y[i]);
            scanf("%d",&g[x[i]][y[i]]);
            g[y[i]][x[i]]=g[x[i]][y[i]];
		}
		maxflow();
		for(int i=0; i<m; i++){
            if((!a[x[i]]&&a[y[i]]) || (a[x[i]]&&!a[y[i]]) )
                 printf("%d %d\n", x[i], y[i]);
        }
        printf("\n");
	}
	return 0;
}
