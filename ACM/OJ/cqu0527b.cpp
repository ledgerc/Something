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

int dp[20][200][200];
int l,r,k;
int bit[20];
int dfs(int pos,int sum,int mod,bool flag){
	if(pos==-1){
		if((sum%k==0)&&(mod%k==0))
			return 1;
		return 0;
	}
	if(!flag&&dp[pos][sum][mod]!=-1)
		return dp[pos][sum][mod];
	int end=flag?bit[pos]:9;
	
	int res=0;
	for(int i=0; i<=end; i++){
		res+=dfs(pos-1,sum+i,(mod*10+i)%k,flag&&i==end);	
	}
	if(!flag)
		dp[pos][sum][mod]=res;
	return res;
}
int calc(int n){
	int pos=0;
	while(n){
		bit[pos++]=n%10;
		n/=10;
	}
	return dfs(pos-1,0,0,1);
}
int main(){
	int T; scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		memset(dp,-1,sizeof dp);
		scanf("%d%d%d",&l,&r,&k);
		printf("Case %d: %d\n",kase,calc(r)-calc(l-1));
	}
	return 0;
}
