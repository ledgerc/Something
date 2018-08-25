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
const int maxn = 5e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[maxn];
int q[maxn],head,tail;
int sum[maxn];
int n,m;
int getDP(int i,int j){
	return dp[j]+m+(sum[i]-sum[j])*(sum[i]-sum[j]);
}
int getUP(int j,int k){
	return dp[j]+sum[j]*sum[j]-(dp[k]+sum[k]*sum[k]);
}
int getDOWN(int j,int k){
	return 2*(sum[j]-sum[k]);
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1; i<=n; i++)
			scanf("%lld",&sum[i]);
		sum[0]=dp[0]=0;
		for(int i=1; i<=n; i++)
		//	sum[i]+=sum[i-1];
		head=tail=0;
		q[tail++]=0;
		for(int i=1; i<=n; i++){
			while(head+1<tail && getUP(q[head+1],q[head])<=sum[i]*getDOWN(q[head+1],q[head]))
				head++;
			dp[i]=getDP(i,q[head]);
			while(head+1<tail && getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1]))
				tail--;
			q[tail++]=i;
		}
		printf("%d\n",dp[n]);
	}
}
