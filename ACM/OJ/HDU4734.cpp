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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[20][200000];

int bit[20];

int dfs(int pos,int num,bool flag){
	//表示求长度为len，不超过num的所有符合条件的值。其中flag是用来控制边界的。
	if(pos==-1)
		return num>=0;
	if(num<0)
		return 0;
	if(!flag&&dp[pos][num]!=-1)
		return dp[pos][num];
	int ans=0;
	int end=flag?bit[pos]:9;
	for(int i=0; i<=end; i++)
		ans+=dfs(pos-1,num - i*(1<<pos),flag && i==end);
	if(!flag)
		dp[pos][num]=ans;
	return ans;
}
int f(int x){
	int ret=0,len=0;
	while(x){
		ret+=(x%10)*(1<<len);
		len++;
		x/=10;
	}
	return ret;
}
int a,b;
int calc(){
	int len=0;
	while(b){
		bit[len++]=b%10;
		b/=10;
	}
	return dfs(len-1,f(a),1);
}
int main(){
	int T; cin>>T;
	memset(dp,-1,sizeof dp);
	for(int kase=1; kase<=T; kase++){
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",kase,calc());
	}
	return 0;
}
