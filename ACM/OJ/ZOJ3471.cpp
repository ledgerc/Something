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
const int maxn = 1e2+7;
const int maxm = 1<<11;
const double pi = acos(-1.0);

int a[maxn][maxn];
int dp[maxm];
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		memset(dp,0,sizeof dp);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&a[i][j]);
		int full=1<<n;
		for(int s=0; s<full; s++){
			for(int i=0; i<n; i++){
				if(s&(1<<i))
					continue;
				for(int j=0; j<n; j++){
					if(i==j||(s&(1<<j)))
						continue;
					int newstate=s+(1<<j);
					dp[newstate]=max(dp[newstate],dp[s]+a[i][j]);
				}
			}
		}
		int ans=0;
		for(int i=0; i<full; i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
	return 0;
}
