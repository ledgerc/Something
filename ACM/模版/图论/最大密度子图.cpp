/*
无边权： 
把原图中的无向边转换成两条有向边，容量为1。
设一源点，连接所有点，容量为U（取m）。
设一汇点，所有点连接汇点，容量为 U+2g-dv 。
二分枚举最大密度g，其中dv为v的度。
判断(U*n-MaxFlow)/2.>=0。
最后跳出的L就是最大密度。
拿这个L再重新建图，求最大流。
然后从s出发bfs或者dfs，走残留容量大于0的边，所有能到达的点就是答案。
*/
int n,m,s,t,cnt,sum,degree[maxn];
bool vis[maxn]; 
struct Node{
	int x,y;
}p[maxn];
//Dinic
//用于表示边的结构体(终点、容量、反向边) 
struct edge{
	int to,rev;
	double cap;
	edge(int to,double cap,int rev) :to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];//图的领接表表示
int level[maxn];//顶点到源点的距离标号 
int iter[maxn];//当前弧，在其之前的边已经没有用了 
void add_edge(int from,int to,double cap){
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size()-1));
}
//通过BFS计算从源点出发的距离标号 
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
//通过DFS寻找增广路 
double dfs(int v,int t,double f){
	if(v==t)
		return f;
	for(int &i=iter[v]; i<G[v].size(); i++){
		edge&e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
			double d=dfs(e.to,t,min(f,e.cap));
			if(d>eps){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//求解从s到t的最大流 
double max_flow(int s,int t){
	double flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)
			return flow;
		memset(iter,0,sizeof iter);
		double f;
		while((f=dfs(s,t,inf))>0){
			flow+=f;
		}
	}
}
void init(double mid){
	for(int i=0; i<maxn; i++)
		G[i].clear();
	for(int i=1; i<=n; i++){
		add_edge(s,i,m);
		add_edge(i,t,m+2*mid-degree[i]);
	}
	for(int i=0; i<m; i++){
		add_edge(p[i].x,p[i].y,1.0);
		add_edge(p[i].y,p[i].x,1.0);
	}
}
void dfs(int v){
	cnt++;
	vis[v]=true;
	vector<edge> gv=G[v];
	for (vector<edge>::iterator it = gv.begin(); it != gv.end(); ++it){
		const edge &e = *it;
		if (e.cap > eps && !vis[e.to])
			dfs(e.to);
	}
}
int main(){
	memset(vis,false,sizeof vis);
	memset(degree,0,sizeof degree);
	scanf("%d%d",&n,&m);
	if(m==0){
		printf("1.00000\n");
		return 0;
	}
	s=0,t=n+1;
	for(int i=0; i<m; i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		degree[p[i].x]++; degree[p[i].y]++;
	}
	double l=0,r=m,mid,hg;
	const double epss=(1.0/n/n);
	while(r-l>=epss){
		mid=(l+r)/2; init(mid);
		hg=(n*m-max_flow(s,t))/2;
		if(hg>eps) l=mid;
		else r=mid;
	}
	init(l); max_flow(s,t);
	cnt=0; dfs(0);
	int sum=0;
	for(int i=0; i<m; i++){
		if(vis[p[i].x]&&vis[p[i].y])
			sum++;
	}
	double ans=double(sum)/(cnt-1);
	printf("%.5f\n",ans);
	return 0;
}





























#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
#define bug cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps = 1e-8;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
无边权： 
把原图中的无向边转换成两条有向边，容量为1。
设一源点，连接所有点，容量为U（取m）。
设一汇点，所有点连接汇点，容量为 U+2g-dv 。
二分枚举最大密度g，其中dv为v的度。
判断(U*n-MaxFlow)/2.>=0。
最后跳出的L就是最大密度。
拿这个L再重新建图，求最大流。
然后从s出发bfs或者dfs，走残留容量大于0的边，所有能到达的点就是答案。
*/
int n,m,s,t,cnt,sum,U,degree[maxn];
bool vis[maxn]; 
struct Node{
	int x,y,w;
}p[maxn];
//Dinic
//用于表示边的结构体(终点、容量、反向边) 
struct edge{
	int to,rev;
	double cap;
	edge(int to,double cap,int rev) :to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];//图的领接表表示
int level[maxn];//顶点到源点的距离标号 
int iter[maxn];//当前弧，在其之前的边已经没有用了 
void add_edge(int from,int to,double cap){
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size()-1));
}
//通过BFS计算从源点出发的距离标号 
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
//通过DFS寻找增广路 
double dfs(int v,int t,double f){
	if(v==t)
		return f;
	for(int &i=iter[v]; i<G[v].size(); i++){
		edge&e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
			double d=dfs(e.to,t,min(f,e.cap));
			if(d>eps){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//求解从s到t的最大流 
double max_flow(int s,int t){
	double flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)
			return flow;
		memset(iter,0,sizeof iter);
		double f;
		while((f=dfs(s,t,inf))>0){
			flow+=f;
		}
	}
}
void init(double mid){
	for(int i=0; i<maxn; i++)
		G[i].clear();
	for(int i=1; i<=n; i++){
		add_edge(s,i,U);
		add_edge(i,t,U+2*mid-degree[i]);
	}
	for(int i=0; i<m; i++){
		add_edge(p[i].x,p[i].y,p[i].w);
		add_edge(p[i].y,p[i].x,p[i].w);
	}
}
void dfs(int v){
	cnt++;
	vis[v]=true;
	vector<edge> gv=G[v];
	for (vector<edge>::iterator it = gv.begin(); it != gv.end(); ++it){
		const edge &e = *it;
		if (e.cap > eps && !vis[e.to])
			dfs(e.to);
	}
}
int main(){
	memset(vis,false,sizeof vis);
	memset(degree,0,sizeof degree);
	scanf("%d%d",&n,&m);
	if(m==0){
		printf("1\n1\n");
		return 0;
	}
	s=0,t=n+1,U=0;
	for(int i=0; i<m; i++){
		scanf("%d%d",&p[i].x,&p[i].y); p[i].w=1;
		degree[p[i].x]+=p[i].w; degree[p[i].y]+=p[i].w;
		U+=p[i].w;
	}
	double l=0,r=m,mid,hg;
	const double epss=(1.0/n/n);
	while(r-l>=epss){
		mid=(l+r)/2; init(mid);
		hg=(n*m-max_flow(s,t))/2;
		if(hg>eps) l=mid;
		else r=mid;
	}
	init(l); max_flow(s,t);
	cnt=0; dfs(0);
	printf("%d\n",cnt-1);
	for(int i=1; i<=n; i++)
		if(vis[i]) printf("%d\n",i);
	return 0;
}
/*
5 6
1 5
5 4
4 2
2 5
1 2
3 1
*/
