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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
用dp[i]表示在i位置时，距离游戏结束还要投掷次数的期望。
显然dp[n]为0，需要求的是dp[0]。
对于直接飞过去的点。
例如用数组vis[]来表示，vis[a]=b，表示当到达a点时可以直接飞到b点，
那么显然dp[vis[a]]=dp[a]。

倒着推，dp[i](假设该点不属于可飞行的点)的下面一个状态有6种可能
每种都是1/6的概率。所以for(int x=1;x<=6;x++) dp[i]+=dp[i+x]/6.0;
dp[i]+=1;注意最后加玩每种可能性的期望后要+1，因为这6种可能性加起来只是下一个状态的期望，当前状态是他们的前一个状态，所以期望（直接理解为投掷骰子的次数）要+1。
*/ 
double dp[maxn];
int vis[maxn];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n+m==0)
			break;
		memset(vis,-1,sizeof vis);
		int u,v;
		for(int i=1; i<=m; i++){
			scanf("%d%d",&u,&v);
			vis[u]=v;
		}
		memset(dp,0,sizeof dp);
		for(int i=n-1; i>=0; i--){
			if(vis[i]==-1){
				for(int j=1; j<=6; j++)
					dp[i]+=dp[i+j]/6.0;
				dp[i]+=1;
			}
			else
				dp[i]=dp[vis[i]];
		}
		printf("%.4lf\n",dp[0]);
	}
	return 0;
}
