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
const int maxm = 1e2+7;
const double pi = acos(-1.0);

int dp[maxm][maxn];
int a[maxn],m[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		int n,k; scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&m[i]);
		memset(dp,-1,sizeof dp);
		dp[0][0]=0;
		for(int i=1; i<=n; i++){
			for(int j=0; j<=k; j++){
				if(dp[i-1][j]>=0)
					dp[i][j]=m[i];
			}
			for(int j=0; j<=k-a[i]; j++)
				if(dp[i][j]>0)
					dp[i][j+a[i]]=max(dp[i][j+a[i]],dp[i][j]-1);
		}
		if(dp[n][k]>=0)
			printf("yes\n");
		else
			printf("no\n");
	}
}
