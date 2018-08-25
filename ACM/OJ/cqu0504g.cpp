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
const int maxn = 3e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

ll dp[maxn][maxn];
int main(){
	int n,k,q;
	cin>>q;
	dp[1][1]=1;
	for(int i=2; i<=3000; i++)
		for(int k=1; k<=i; k++)
			dp[i][k]=(dp[i-1][k]*2*k+dp[i-1][k-1]*(i-2*(k-1)))%mod;
	
	while(q--){
		cin>>n>>k;
		ll ans=0;
		for(int i=1; i<=n-k; i++)
			ans=(ans+dp[n][i])%mod;
		cout<<ans<<endl;
	}
	return 0;
}
