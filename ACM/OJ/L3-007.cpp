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
const int maxn = 5e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m;
bool vis[maxn];
int dis[maxn],tim[maxn],w[maxn][maxn],e[maxn][maxn];
int timepre[maxn],weight[maxn];
vector<int> timepath,dispath,tmppath,dispre[maxn];
int st,fin,minnode=inf;
void dfstimepath(int v){
	timepath.push_back(v);
	if(v==st)
		return;
	else
		dfstimepath(timepre[v]);
}
void dfsdispath(int v){
	tmppath.push_back(v);
    if(v==st){
        if(tmppath.size()<minnode){
            minnode=tmppath.size();
            dispath=tmppath;
        }
        tmppath.pop_back();
        return ;
    }
    for(int i=0; i<dispre[v].size(); i++)
        dfsdispath(dispre[v][i]);
    tmppath.pop_back();
}
int main(){
	memset(dis,inf,sizeof dis);
	memset(tim,inf,sizeof tim);
	memset(w,inf,sizeof w);
	memset(e,inf,sizeof e);
	memset(weight,inf,sizeof weight);
	scanf("%d%d",&n,&m);
	int u,v,flag,len,t;
	for(int i=0; i<m; i++){
		scanf("%d%d%d%d%d",&u,&v,&flag,&len,&t);
		e[u][v]=len; w[u][v]=t;
		if(flag!=1){
			e[v][u]=len; w[v][u]=t;
		}
	}
	scanf("%d%d",&st,&fin);
	tim[st]=0;
	for(int i=0; i<=n; i++)
		timepre[i]=i;
	memset(vis,false,sizeof vis);
	for(int i=0; i<n; i++){
		int u=-1,minn=inf;
		for(int j=0; j<n; j++){
			if(!vis[j]&&tim[j]<minn){
				u=j;
				minn=tim[j];
			}
		}
		if(u==-1)
			break;
		vis[u]=true;
		for(int v=0; v<n; v++){
			if(!vis[v]&&w[u][v]!=inf){
				if(w[u][v]+tim[u]<tim[v]){
					tim[v]=w[u][v]+tim[u];
					timepre[v]=u;
					weight[v]=weight[u]+e[u][v];
				}
				else if(w[u][v]+tim[u]==tim[v]&&weight[v]>weight[u]+e[u][v]){
					weight[v]=weight[u]+e[u][v];
					timepre[v]=u;
				}
			}
		}
	}
	dfstimepath(fin);
	
	memset(vis,false,sizeof vis);
	dis[st]=0;
	for(int i=0; i<n; i++){
		int u=-1,minn=inf;
		for(int j=0; j<n; j++){
			if(!vis[j]&&dis[j]<minn){
				u=j;
				minn=dis[j];
			}
		}
		if(u==-1)
			break;
		vis[u]=true;
		for(int v=0; v<n; v++){
			if(!vis[v]&&e[u][v]!=inf){
				if(e[u][v]+dis[u]<dis[v]){
					dis[v]=dis[u]+e[u][v];
					dispre[v].clear();
					dispre[v].push_back(u);
				}
				else if(e[u][v]+dis[u]==dis[v])
					dispre[v].push_back(u);
			}
		}
	}
	dfsdispath(fin);
	
	printf("Time = %d",tim[fin]);
	if(dispath==timepath){
		printf("; Distance = %d: ",dis[fin]);
	}
	else{
		printf(": ");
		for(int i=timepath.size()-1; i>=0; i--){
			printf("%d",timepath[i]);
			if(i!=0)
				printf(" => ");
		}
		printf("\n");
		printf("Distance = %d: ",dis[fin]);
	}
	for(int i=dispath.size()-1; i>=0; i--){
		printf("%d",dispath[i]);
		if(i!=0)
			printf(" => ");
	}
	return 0;
}
