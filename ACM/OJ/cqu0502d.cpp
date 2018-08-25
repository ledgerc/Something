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
const int maxn = 3e3;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[maxn][2*maxn+7];
int n;
int ta[maxn+7],tb[maxn+7];
int main(){
	int T; cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d%d",&ta[i],&tb[i]);
		memset(dp,inf,sizeof dp);
		dp[0][maxn]=0;
		for(int i=1; i<=n; i++){
			for(int j=-maxn; j<=maxn; j++){
				if(dp[i-1][j+maxn]==inf)
					continue;
				if(j<0){
					dp[i][j+ta[i]+maxn]=min(dp[i][j+ta[i]+maxn],dp[i-1][j+maxn]+max(0,j+ta[i]));
					//put it on b
					dp[i][-tb[i]+maxn]=min(dp[i][-tb[i]+maxn],dp[i-1][j+maxn]+tb[i]);
				}
				else{
					dp[i][ta[i]+maxn]=min(dp[i][ta[i]+maxn],dp[i-1][j+maxn]+ta[i]);
					//put it on b
					dp[i][j-tb[i]+maxn]=min(dp[i][j-tb[i]+maxn],dp[i-1][j+maxn]+max(0,tb[i]-j));
				}
			}
		}
		int ans=inf;
		for(int i=-maxn; i<=maxn; i++)
			if(dp[n][i+maxn]!=inf){
			//	PR(dp[n][i])
				ans=min(ans,dp[n][i+maxn]);
			}
	//	PR(ans)
		printf("%d\n",ans);
	}
	return 0;
}
