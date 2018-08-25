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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[maxn][2],val[maxn];
int in[maxn];
struct Node{
	int to,next;
}edge[maxn*2];
int tot,head[maxn];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
	memset(in,0,sizeof in);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int dfs(int u){
	dp[u][0]=0;
	dp[u][1]=val[u];
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		dfs(v);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	return max(dp[u][0],dp[u][1]);
}
int main(){
	int n,u,v;
	while(scanf("%d",&n)!=EOF){	
		init();
		for(int i=1; i<=n; i++)
			scanf("%d",&val[i]);
		while(scanf("%d%d",&v,&u)&&(u+v)){
			addedge(u,v);
			in[v]++;
		}
		int ans=0;
		for(int i=1; i<=n; i++)
			if(!in[i])
				ans+=dfs(i);
		cout<<ans<<endl;
	}
	return 0;
}
