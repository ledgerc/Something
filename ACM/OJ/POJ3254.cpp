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
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,a[15];
int dp[13][(1<<12)+10];

bool check(int x,int flag){
	if((a[x]&flag)!=flag)
		return 0;
	if((flag&(flag<<1))!=0||(flag&(flag>>1))!=0)
		return 0;
	return 1;
} 
void solve(){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	int max=1<<m;
	for(int i=1; i<=n; i++){
		for(int j=0; j<max; j++){
			if(check(i,j)==0)
				continue;
			for(int k=0; k<max; k++){
				if((j&k)!=0)
					continue;
				dp[i][j]=dp[i][j]+dp[i-1][k];
				dp[i][j]%=mod;
			}
		}
	}
	int res=0;
	for(int i=0; i<max; i++){
		res+=dp[n][i];
		res%=mod;
	}
	printf("%d\n",res);
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1; i<=n; i++){
			a[i]=0;
			for(int j=1; j<=m; j++){
				int tmp; cin>>tmp;
				a[i]=(a[i]<<1)+tmp;
			}
		}
		solve();
	}
	return 0;
}
