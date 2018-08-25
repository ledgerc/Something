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

ll dp[maxn];
int main(){
	int n,x; scanf("%d%d",&n,&x);
	for(int i=1; i<maxn; i++)
		dp[i]=-INF;
	dp[0]=0;
	for(int i=0; i<n; i++){
		int m,w; scanf("%d%d",&w,&m);
		for(int j=x; j>=m; j--)
			dp[j]=max(dp[j],dp[j-m]+w);
	}
	if(dp[x]<0)
		printf("Got caught!\n");
	else
		printf("%lld\n",dp[x]);
	return 0;
}
