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
typedef pair<int,ll> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 3e2+7;
const int maxm = 2e5+7;
const double pi = acos(-1.0);

struct Node{
	ll a,b,t;
}a[maxn];
P q[maxm];
int head,tail;
ll dp[2][maxm];
int main(){
	int T; cin>>T;
	while(T--){
		ll n,m,d; scanf("%lld%lld%lld",&n,&m,&d);
		for(int i=1; i<=m; i++)
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].t);
		int pre=0,now=1;
		memset(dp,-inf,sizeof dp);
		for(int i=1; i<=n; i++)
			dp[pre][i]=a[1].b-abs(a[1].a-i);
		for(int i=2; i<=m; i++){
			head=tail=0;
			int len=d*(a[i].t-a[i-1].t);
			for(int j=1; j<=n; j++){
				ll nowf=dp[pre][j];
				while(head<tail && q[tail-1].second<nowf)
					tail--;
				while(head<tail && q[head].first<j-len)
					head++;
				q[tail++]=P(j,nowf);
				dp[now][j]=q[head].second+a[i].b-abs(a[i].a-j);
			}
			head=tail=0;
			for(int j=n; j>=1; j--){
				ll nowf=dp[pre][j];
				while(head<tail && q[tail-1].second<nowf)
					tail--;
				while(head<tail && q[head].first>j+len)
					head++;
				q[tail++]=P(j,nowf);
				dp[now][j]=max(dp[now][j],q[head].second+a[i].b-abs(a[i].a-j));
			}
			swap(now,pre);
		}
		ll ans=-inf;
		for(int i=1; i<=n; i++)
			ans=max(ans,dp[pre][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
