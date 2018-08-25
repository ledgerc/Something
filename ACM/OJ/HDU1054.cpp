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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Node{
	int to,next;
}edge[maxn];
int tot,head[maxn];
int dp[maxn][2];
void init(){
	tot=0;
	memset(dp,0,sizeof dp);
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int u,int pre){
	dp[u][1]=1;
	dp[u][0]=0;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v==pre)
			continue;
		dfs(v,u);
		dp[u][0]+=dp[v][1];
		dp[u][1]+=min(dp[v][0],dp[v][1]);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=0; i<n; i++){
			int u,k,v;
			scanf("%d:(%d)",&u,&k);
			u++;
			for(int j=0; j<k; j++){
				scanf("%d",&v); v++;
				addedge(u,v); addedge(v,u);
			}
		}
		dfs(1,-1);
		printf("%d\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
