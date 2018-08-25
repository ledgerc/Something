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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//Dijkstra 单源最短路，邻接矩阵形式
//权值必须非负
int cost[maxn][maxn];//表示边u,v的权值 
int d[maxn];//从点s出发的最短距离 
bool used[maxn];
int V;//顶点数 
void dijkstra(int s){
	for(int i=0; i<=V; i++)
		d[i]=cost[0][i];
	memset(used,false,sizeof used);
	d[s]=0;
	for(int i=0; i<=V; i++){
		int v=-1;
		//从尚未使用的顶点中选择一个距离最小的顶点 
		for(int u=0; u<=V; u++){
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		}
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0; u<=V; u++){
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
}
int main(){
	int n,m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		V=n;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				if(i==j)
					cost[i][j]=0;
				else
					cost[i][j]=inf;
		int u,v,w;
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&u,&v,&w);
			cost[u][v]=min(cost[u][v],w);
		}
		int tmp; cin>>tmp;
		for(int i=0; i<tmp; i++){
			scanf("%d",&v);
			cost[0][v]=0;
		}
		dijkstra(0);
		if(d[s]==inf)
			cout<<"-1"<<endl;
		else
			cout<<d[s]<<endl;
	}
	return 0;
}
