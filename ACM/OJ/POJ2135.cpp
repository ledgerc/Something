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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//Dinic
//���ڱ�ʾ�ߵĽṹ��(�յ㡢�����������) 
struct edge{
	int to,cap,rev;
};
vector<edge> G[maxn];//ͼ����ӱ��ʾ
int level[maxn];//���㵽Դ��ľ����� 
int iter[maxn];//��ǰ��������֮ǰ�ı��Ѿ�û������ 
void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
//ͨ��BFS�����Դ������ľ����� 
void bfs(int s){
	memset(level,-1,sizeof level);
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front(); que.pop();
		for(int i=0; i<G[v].size(); i++){
			edge&e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
//ͨ��DFSѰ������· 
int dfs(int v,int t,int f){
	if(v==t)
		return f;
	for(int &i=iter[v]; i<G[v].size(); i++){
		edge&e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
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
//����s��t������� 
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)
			return flow;
		memset(iter,0,sizeof iter);
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	int u,v,cap;
	for(int i=0; i<m; i++){
		cin>>u>>v>>cap;
		add_edge(u,v,cap);
		add_edge(v,u,cap);
	}
	int ans=max_flow(1,n);
	cout<<ans<<endl;
	return 0;
}
