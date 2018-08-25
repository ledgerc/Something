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
/*
数位DP，因为K<=5，我们最多需要保存下来当前位的前4位就足够了。
因为dp[pos][p1][p2][p3][p4]表示，现在枚举取第pos位，pos位之前的四位分别为p1,p2,p3,p4,p4是pos的上一位。
那么p1~p4的范围就是0~9，但是数是没有前导0的，
而且k可能为2,3,4，不需要保存到前4位，
所以我们令p = 10来表示这一位不需要保存，
也许可能是前导0，也许是不需要保存。
那么dfs函数可以写成 dfs(int pos,int p1,int p2,int p3,int p4,bool flag)
flag表示pos位能否取到全部的数位(0~9)还是会受到前面最高位的影响只能取一部分。
那么统计下一位的时候就可以分为两种情况：
1、pos位之前都取的0，而pos位也取0，一直都是前导零。
2、pos位取的i去和p判断一下有没有重复（根据k来判断需要比较几个p）,
假设这种情况，K = 3,而我们现在正在取第二位，i会和p4和p3去比较一下，
但是只有p4是我们取过的值，不过p3此时是10，所以也是可以向下统计的。
*/
ll L,R;
int K;
ll dp[20][11][11][11][11];
int bit[20];
//根据K来判断需要和哪些p做比较
bool check(int a,int b,int c,int d,int now){
	if(K==2)
		return now!=d;
	else if(K==3)
		return now!=d&&now!=c;
	else if(K==4)
		return now!=d&&now!=c&&now!=b;
	else
		return now!=d&&now!=c&&now!=b&&now!=a;
}
ll dfs(int pos,int p1,int p2,int p3,int p4,bool flag){
	if(pos==0)//全部取完，若p4还是10，说明全部取了0，即全部为前导零
		return p4!=10;
	if(!flag&&dp[pos][p1][p2][p3][p4]!=-1)
		return dp[pos][p1][p2][p3][p4];
	int end=flag?bit[pos]:9;
	ll ans=0;
	for(int i=0; i<=end; i++){
		if(i==0&&p4==10)//pos位及其之前全部为0
			ans+=dfs(pos-1,10,10,10,10,flag&&i==end);
		else
			if(check(p1,p2,p3,p4,i))
				ans+=dfs(pos-1,p2,p3,p4,i,flag&&i==end);
	}
	if(!flag)
		dp[pos][p1][p2][p3][p4]=ans;
	return ans;
}
ll calc(ll x){
	if(x<=0)
		return 0;
	int len=0;
	while(x){
		bit[++len]=x%10;
		x/=10;
	}
	return dfs(len,10,10,10,10,1);
}
int main(){
	while(scanf("%lld%lld%lld",&L,&R,&K)!=EOF){
		memset(dp,-1,sizeof dp);
		printf("%lld\n",calc(R)-calc(L-1));
	}
	return 0;
}
