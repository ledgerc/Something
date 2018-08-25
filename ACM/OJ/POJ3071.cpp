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
const double eps = 1e-4;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

double dp[10][maxn];
double p[maxn][maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==-1)
			break;
		memset(dp,0,sizeof dp);
		for(int i=0; i<(1<<n); i++)
			for(int j=0; j<(1<<n); j++)
				scanf("%lf",&p[i][j]);
		for(int i=0; i<(1<<n); i++)
			dp[0][i]=1.0;
		for(int i=1; i<=n; i++){
			for(int j=0; j<(1<<n); j++){
				for(int k=0; k<(1<<n); k++){
					if(((j>>(i-1))^1)==(k>>(i-1)))
						dp[i][j]+=dp[i-1][k]*dp[i-1][j]*p[j][k];
				}
			}
		}
		int ans=0;
		double tmp=-1;
		for(int i=0; i<(1<<n); i++)
			if(dp[n][i]>tmp){
				tmp=dp[n][i];
				ans=i;
			}
		cout<<ans+1<<endl;
	}
	return 0;
}
