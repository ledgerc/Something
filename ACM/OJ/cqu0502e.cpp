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
const int maxn = 1e2+7;
const int maxm = 5e5+1-1;
const double pi = acos(-1.0);

int a[maxn];
int dp[2][maxm];
int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		int mx=0;
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i]);
			mx+=a[i];
		}
		memset(dp,-inf,sizeof dp);
		dp[0][0]=0;
		int pre=0,now=1;
		for(int i=1; i<=n; i++){
			memset(dp[now],-inf,sizeof dp[now]);
			for(int j=0; j<=mx; j++){
				dp[now][j]=max(dp[now][j],dp[pre][j]);
				if(j+a[i]<=maxm)
					dp[now][j+a[i]]=max(dp[now][j+a[i]],dp[pre][j]+a[i]);
				if(j>=a[i])
					dp[now][j-a[i]]=max(dp[now][j-a[i]],dp[pre][j]+a[i]);
				else
					dp[now][a[i]-j]=max(dp[now][a[i]-j],dp[pre][j]+a[i]);
			}
			swap(now,pre);
		}
		if(dp[pre][0]<=0&&dp[now][0]<=0)
			cout<<"GG"<<endl;
		else{
			int ans=max(dp[pre][0],dp[now][0]);
			cout<<ans/2<<endl;
		}
	}
	return 0;
}
