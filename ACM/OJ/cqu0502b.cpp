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

ll dp[maxn];
ll q[maxn],head,tail;
ll a[maxn];
int n,w;
ll getDP(int i,int j){
	return dp[j]+w+(a[i]-a[j+1])*(a[i]-a[j+1]);
}
ll getUP(int j,int k){
	return (dp[j]+a[j+1]*a[j+1])-(dp[k]+a[k+1]*a[k+1]);
}
ll getDOWN(int j,int k){
	return (ll)2*(a[j+1]-a[k+1]);
}
int main(){
	int T; cin>>T;
	while(T--){
		scanf("%d%d",&n,&w);
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		a[0]=dp[0]=0;
		head=tail=0;
		q[tail++]=0;
		for(int i=1; i<=n; i++){
			while(head<tail && getUP(q[head+1],q[head])<=a[i]*getDOWN(q[head+1],q[head])){
			//	cout<<"---------"<<getUP(q[head+1],q[head])<<" "<<a[i]*getDOWN(q[head],q[head+1])<<endl;
				head++;
			}
            dp[i]=getDP(i,q[head]);
       //     cout<<head<<" "<<tail<<" "<<dp[i]<<endl;
			while(head<tail && getUP(i,q[tail])*getDOWN(q[tail],q[tail-1])<=getUP(q[tail],q[tail-1])*getDOWN(i,q[tail]))
				tail--;
			q[++tail]=i;
		}
		printf("%lld\n",dp[n]);
	}
}
