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
const int maxn = 4e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int q[maxn],head,tail;
ll sum[maxn];
ll a[maxn];
ll dp[maxn];
/*
dp[i]= min{dp[j]+(sum[i]-sum[j])-a[j+1](i-j)}    k<=j<i-t+1.
dp[j] -sum[j] + a[j+1](j) - a[j+1]*i
dp[k] -sum[k] + a[k+1](k) - a[k+1]*i
(dp[j]-sum[j]+a[j+1]*(j)) - (dp[k]-sum[k]+a[k+1]*(k))
------------------------------------------------------<=i
					a[j+1]-a[k+1]
*/
ll getDP(int i,int j){
	return dp[j]+(sum[i]-sum[j])-a[j+1]*(i-j);
}
ll getUP(int j,int k){
	return (dp[j]-sum[j]+a[j+1]*(j)) - (dp[k]-sum[k]+a[k+1]*(k));
}
ll getDOWN(int j,int k){
	return a[j+1]-a[k+1];
}
int main(){
	int n,t;
	while(scanf("%d%d",&n,&t)!=EOF){
		sum[0]=a[0]=dp[0]=0;
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++)
			sum[i]=sum[i-1]+a[i];
		head=tail=0;
		q[tail++]=0;
		for(int i=1; i<=n; i++){
			while(head+1<tail && getUP(q[head+1],q[head])<=getDOWN(q[head+1],q[head])*i)
				head++;
			dp[i]=getDP(i,q[head]);
			int j=i-t+1;
			if(j<t)
				continue;
			while(head+1<tail && getUP(j,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(j,q[tail-1]))
				tail--;
			q[tail++]=j;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
