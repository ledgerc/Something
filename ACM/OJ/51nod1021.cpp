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
const int maxn = 2e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[maxn][maxn],sum[maxn];
int a[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		memset(sum,0,sizeof sum);
		for(int i=1; i<=n; i++){
			sum[i]=sum[i-1]+a[i];
		}
		for(int len=1; len<n; len++){
			for(int i=1; i<=n&&i+len<=n; i++){
				dp[i][i+len]=inf;
				for(int k=i; k<=i+len; k++){
					dp[i][i+len]=min(dp[i][i+len],dp[i][k]+dp[k+1][i+len]+sum[i+len]-sum[i-1]);
				}
			}
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}
