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


vector<vector<int> > adj;//原图 
vector<vector<int> > radj;//逆图 
vector<vector<int> > dag;//缩点后的逆向DAG图 
int n,cnt;
int id[maxn],st[maxn],ind[maxn];//强连通分量 访问顺序 入度 
bool vis[maxn];

void dfs(int u){
    vis[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    	if(!vis[adj[u][i]])
    		dfs(adj[u][i]);
    st[cnt++]=u;
}
void rdfs(int u){
    vis[u]=true;
    id[u]=cnt;
    for(int i=0; i<radj[u].size(); i++)
		if(!vis[radj[u][i]])
    		rdfs(radj[u][i]);
}
void korasaju(){
    int i;
    memset(vis,false,sizeof(vis));
    for(cnt=0,i=0; i<2*n; i++)
    	if(!vis[i])
			dfs(i);
    memset(id,0,sizeof(id));
    memset(vis,false,sizeof(vis));
    for(cnt=0,i=2*n-1;i>=0;i--)
    	if(!vis[st[i]]){
        	cnt++;
    		rdfs(st[i]);
    	}
}
bool solvable(){
	for(int i=0; i<n; i++)
		if(id[2*i]==id[2*i+1])
			return false;
	return true;
}
struct Node{
	int s,t;
}node[maxn];
int main(){
	int N;
	while(scanf("%d%d",&N,&n)!=EOF){
		int u,v;
		for(int i=0; i<n; i++){
			scanf("%d%d",&u,&v);
			if(u>v)
				swap(u,v);
			node[i].s=u; node[i].t=v;
		}
        adj.assign(2*n,vector<int>());
        radj.assign(2*n,vector<int>());
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++){
				if((node[i].s<node[j].s&&node[j].s<node[i].t&&node[i].t<node[j].t)
				||(node[j].s<node[i].s&&node[i].s<node[j].t&&node[j].t<node[i].t)){
					adj[2*i].push_back(2*j+1);
                	adj[2*j+1].push_back(2*i);
                	adj[2*i+1].push_back(2*j);
                	adj[2*j].push_back(2*i+1);
                	radj[2*j+1].push_back(2*i);
                	radj[2*i].push_back(2*j+1);
                	radj[2*j].push_back(2*i+1);
                	radj[2*i+1].push_back(2*j);
				}
			}
		korasaju();
		if(solvable())
			printf("panda is telling the truth...\n");
		else
			printf("the evil panda is lying again\n");
	}
	return 0;
}
