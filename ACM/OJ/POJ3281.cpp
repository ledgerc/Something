//Ford-Flukerson 
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX_N = 2e2+7;
const int MAX_F = 2e2+7;
const int MAX_D = 2e2+7;
const int MAX_V = 4e2+7;
const int INF = 0x3f3f3f3f;
int N,F,D;
bool likeF[MAX_N][MAX_F];
bool likeD[MAX_N][MAX_D];	
//用于表示边的结构体(终点、容量、反向边) 
struct edge{
	int to,cap,rev;
};
vector<edge> G[MAX_V];//图的领接表表示 
bool used[MAX_V];//DFS中用到的访问标记 
void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
//DFS寻找增广路 
int dfs(int v,int t,int f){
	if(v==t)
		return f;
	used[v]=true;
	for(int i=0; i<G[v].size(); i++){
		edge &e=G[v][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//求解s到t的最大流 
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		memset(used,0,sizeof used);
		int f=dfs(s,t,INF);
		if(f==0)
			return flow;
		flow+=f;
	}
}
void solve(){
	int s=N*2+F+D,t=s+1;
	
	for(int i=0; i<F; i++)
		add_edge(s,N*2+i,1);
	for(int i=0; i<D; i++)
		add_edge(N*2+F+i,t,1);

	for(int i=0; i<N; i++){
		add_edge(i,N+i,1);
		for(int j=0; j<F; j++)
			if(likeF[i][j])
				add_edge(N*2+j,i,1);
		for(int j=0; j<D; j++)
			if(likeD[i][j])
				add_edge(N+i,N*2+F+j,1);
	}
	printf("%d\n",max_flow(s,t));
}
int main(){
	ios::sync_with_stdio(false);
	cin>>N>>F>>D;
	memset(likeF,false,sizeof likeF);
	memset(likeD,false,sizeof likeD);
	for(int i=0; i<N; i++){
		int Fnum,Dnum; cin>>Fnum>>Dnum;
		for(int j=0; j<Fnum; j++){
			int tmp; cin>>tmp; tmp--;
			likeF[i][tmp]=true;
		}
		for(int j=0; j<Dnum; j++){
			int tmp; cin>>tmp; tmp--;
			likeD[i][tmp]=true;
		}
	}
	solve();
	return 0;
} 
