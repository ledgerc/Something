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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
int a[maxn];
int dp[maxn][maxn];
int main(){
	sc(n);
	for(int i=1; i<=n; i++)
		sc(a[i]);
	memset(dp,0,sizeof dp);
	for(int l=2; l<n; l++){
		for(int i=2; i+l<=n+1; i++){
			int j=i+l-1;
			dp[i][j]=inf;
			for(int k=i; k<j; k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
		}
	}
	printf("%d\n",dp[2][n]);
	return 0;
}
