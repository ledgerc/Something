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
#define PR(x) cout<<#x<<": "<<x<<endl;
#define sc(x) scanf("%d",&x);
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int a[maxn];
int dp[maxn][maxn];
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		int n; sc(n);
		for(int i=1; i<=n; i++)
			sc(a[i]);
		for(int i=0; i<=n; i++)
			dp[i][i]=1;
		for(int i=n; i>=1; i--){//从后往前推 
			for(int j=i+1; j<=n; j++){
				dp[i][j]=dp[i+1][j]+1;
				for(int k=i+1; k<=n; k++)
					if(a[i]==a[k])
						dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
			}
		}
		printf("Case %d: %d\n",kase,dp[1][n]);
	}
	return 0;
}
