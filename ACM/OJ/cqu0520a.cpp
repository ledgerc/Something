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
const int maxm = 1e6+7;
const double pi = acos(-1.0);

ll a[maxn];
ll dp[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		ll sum=0;
		a[0]=inf;
		for(int i=1; i<=n; i++){
			if(a[i]>=a[i-1])
				dp[i]=dp[i-1]+1;
			else
				dp[i]=1;
			sum+=dp[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
