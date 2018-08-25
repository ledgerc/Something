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
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//dp[n]表示只剩下n以后的石头 能得多少分 ans=dp[1] 对于两个人都适用
int main(){
	int T; cin>>T;
	while(T--){
		int n;ll a[maxn];
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		ll sum[maxn],dp[maxn];
		memset(sum,0,sizeof sum);
		memset(dp,0,sizeof dp);
		for(int i=n; i>=1; i--)
			sum[i]=sum[i+1]+a[i];

		dp[n]=sum[n];
		dp[n-1]=sum[n-1];
		dp[n-2]=sum[n-2];

		for(int i=n-3; i>0; i--){
			//两级反转?
			ll tmp1=sum[i]-dp[i+1];
			ll tmp2=sum[i]-dp[i+2];
			ll tmp3=sum[i]-dp[i+3];
			
		//	PR(tmp1);
		//	PR(tmp2);
		//	PR(tmp3);
			dp[i]=max(tmp1,max(tmp2,tmp3));
		}
		
	//	cout<<endl;
	//	for(int i=1; i<=n; i++)
	//		cout<<dp[i]<<" ";
	//	cout<<endl;
		cout<<dp[1]<<endl;
	}
}
/*
1
5
999 1 1 1 0
*/
