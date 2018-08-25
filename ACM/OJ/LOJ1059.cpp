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
const double pi = acos(-1.0);

const int maxn = 2e4+7;//最大点数 
const int maxm = 2e6+7;//最大边数 
int F[maxn];//并查集 
struct Edge{
	int u,v,w;
}edge[maxm];//存储边的信息 起点/终点/权值 
int tol;//边数，加边前赋值为0
void addedge(int u,int v,int w){
	edge[tol].u=u;
	edge[tol].v=v;
	edge[tol++].w=w;
}
bool cmp(Edge a,Edge b){
	if(a.w==b.w)
		return a.u<b.u;
	else
		return a.w<b.w;
}
int find(int x){
	if(F[x]==-1)
		return x;
	else
		return F[x]=find(F[x]);
}
int cnt1;
int Kruskal(int n){//传入点数，返回最小生成树的权值，如果不连通返回-1 
	memset(F,-1,sizeof F);
	sort(edge,edge+tol,cmp);
	int cnt=0;//计算加入的边数 
	int ans=0;
	for(int i=0; i<tol; i++){
		int u=edge[i].u; int v=edge[i].v; int w=edge[i].w;
		int t1=find(u); int t2=find(v);
		if(t1!=t2){
			ans+=w;
			F[t1]=t2;
			cnt++;
			if(edge[i].u==0)
				cnt1++;
			if(cnt==n)
				break;
		}
	}
	if(cnt<n-1)
		return -1;//不连通 
	else
		return ans;
}
int n,m,a;
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		scanf("%d%d%d",&n,&m,&a);
		tol=0; cnt1=0;
		for(int i=1; i<=n; i++)
			addedge(0,i,a);
		for(int i=0; i<m; i++){
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		int ans=Kruskal(n);
		printf("Case %d: %d %d\n",kase,ans,cnt1);
	}
	return 0;
}
