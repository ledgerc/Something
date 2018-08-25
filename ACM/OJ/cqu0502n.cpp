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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


ll dp[20][maxn][maxn];
int bit[20];
int dfs(int pos,int odd,int even,int f){
	if(pos==-1){
		cout<<odd<<" : "<<even<<endl;
		if((odd%2==0)&&(even%2!=0))
			return 1;
		return 0;
	}
	if(!f&&dp[pos][odd][even]!=-1)
		return dp[pos][odd][even];
	int end=f?bit[pos]:9;
	int res=0;
	for (int i=0; i<=end; ++i){
		if(i%2==0)
			res+=dfs(pos-1,odd,even+1,f&&i==end);
		else
			res+=dfs(pos-1,odd+1,even,f&&i==end);
	}
	if(!f)
		dp[pos][odd][even]=res;
	return res;
}
int calc(ll x){
	int pos=0;
	while(x){
		bit[pos++]=x%10;
		x/=10;
	} 
	if(bit[pos-1]%2!=0&&pos>1)
		return dfs(pos-1,1,0,1);
	else if(bit[pos-1]%2==0&&pos>1)
		return dfs(pos-1,0,1,1);
	else
		return dfs(pos-1,0,0,1);
}
int main(){
//	int T; cin>>T;
	ll l,r;
	memset(dp,-1,sizeof dp);
	while(scanf("%d",&r)){
		
		PR(calc(r))
		cout<<"---------------------"<<endl;
	//	PR(calc(l-1))
	//	printf("%d\n",calc(r)-calc(l-1));
	}
	return 0;
}
