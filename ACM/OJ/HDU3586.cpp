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
const int inf = 1000010;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Node{
	int to,next;
	int w;
}edge[maxn*2];
int head[maxn];
int tol;
void add(int u,int v,int w){
	edge[tol].to=u;
    edge[tol].next=head[v];
    edge[tol].w=w;
    head[v]=tol++;
    edge[tol].to=v;
    edge[tol].next=head[u];
    edge[tol].w=w;
    head[u]=tol++;
}
void init(){
	tol=0;
	memset(head,-1,sizeof head);
}
int dp[maxn];
void dfs(int u,int pre,int limit){
	int flag=false;
	dp[u]=0;
	for(int i=head[u]; ~i; i=edge[i].next){
		int v=edge[i].to;
		if(v==pre)
			continue;
		flag=true;
		dfs(v,u,limit);
		if(edge[i].w<=limit)
			dp[u]+=min(dp[v],edge[i].w);
		else
			dp[u]+=dp[v];
	}
	if(!flag)
		dp[u]=inf;
}
int main(){
	int n,m;
	int u,v,w;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0)
			break;
		init();
		int l=1,r=-1;
		for(int i=1; i<n; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			r=max(r,w);
		}
		int ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			dfs(1,-1,mid);
			if(dp[1]<=m){
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
