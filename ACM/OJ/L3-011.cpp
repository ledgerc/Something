#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const int mod = 1e9+7;
const double eps = 1e-8;

char name[233][10];
int dis[3][233];
int pre[233];
int cnt[233];
bool vis[233];
int mp[233][233];
int val[233];
map <string,int> Mp;
const int s = 0,d = 1;
int n,tp;
void Dijkstra(){
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(pre,-1,sizeof(pre));
	memset(dis[0],INF,sizeof(dis[0]));
	memset(dis[1],0,sizeof(dis[1]));
	memset(dis[2],0,sizeof(dis[2]));
	dis[0][0] = 0;
	dis[1][0] = 1;
	cnt[0] = 1;

	int u;
	while(1){
		u = -1;
		for(int v = 0; v < n; ++v){
			if((!vis[v]) && (u == -1 || dis[0][v] < dis[0][u] || (dis[0][v] == dis[0][u] && dis[1][v] > dis[1][u]) || (dis[0][v] == dis[0][u]
								&& dis[1][v] == dis[1][u] && dis[2][v] > dis[2][u]))) u = v;
		}

		if(u == d) return;
		vis[u] = 1;

		for(int v = 0; v < n; ++v){
			if(vis[v]) continue;
			if(dis[0][v] > dis[0][u]+mp[u][v]){
				dis[0][v] = dis[0][u] + mp[u][v];
				dis[1][v] = dis[1][u] + 1;
				dis[2][v] = dis[2][u] + val[v];
				pre[v] = u;
				cnt[v] = cnt[u];
			}
			else if(dis[0][v] == dis[0][u]+mp[u][v] && dis[1][v] < dis[1][u]+1){
				dis[0][v] = dis[0][u] + mp[u][v];
				dis[1][v] = dis[1][u] + 1;
				dis[2][v] = dis[2][u] + val[v];
				pre[v] = u;
				cnt[v] += cnt[u];
			}
			else if(dis[0][v] == dis[0][u]+mp[u][v] && dis[1][v] == dis[1][u]+1 && dis[2][v] < dis[2][u]+val[v]){
				dis[0][v] = dis[0][u] + mp[u][v];
				dis[1][v] = dis[1][u] + 1;
				dis[2][v] = dis[2][u] + val[v];
				pre[v] = u;
				cnt[v] += cnt[u];
			}
			else if(dis[0][v] == dis[0][u]+mp[u][v]) cnt[v] += cnt[u];
		}
	}
}
void prt(int u){
	if(pre[u] == -1)
		printf("%s",name[u]);
	else{
		prt(pre[u]);
		printf("->%s",name[u]);
	}
}
int main(){
	int m;
	char u[10];
	char v[10];
	scanf("%d%d%s%s",&n,&m,name[0],name[1]);
	Mp[name[0]] = 0;
	Mp[name[1]] = 1;
	tp = 2;
	val[0] = 0;
	for(int i=1; i<n; ++i){
		scanf("%s",u);
		if(Mp.count(u))
			scanf("%d",&val[Mp[u]]);
		else{
			Mp[u] = tp;
			strcpy(name[tp],u);
			scanf("%d",&val[tp++]);
		}
	}
	int w,uu,vv;
	memset(mp,INF,sizeof(mp));
	while(m--){
		scanf("%s%s%d",u,v,&w);
		uu = Mp[u];
		vv = Mp[v];
		if(w < mp[uu][vv]) mp[uu][vv] = mp[vv][uu] = w;
	}
	Dijkstra();
	prt(1);
	puts("");
	printf("%d %d %d\n",cnt[1],dis[0][1],dis[2][1]);
	return 0;
}
