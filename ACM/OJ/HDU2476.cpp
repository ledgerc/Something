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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int ans[maxn];
int main(){
	while(scanf("%s%s",s1,s2)!=EOF){
		int len=strlen(s2);
		memset(dp,0,sizeof dp);
		for(int i=0; i<=len; i++)
			dp[i][i]=1;
		for(int j=0; j<len; j++)//尾 
			for(int i=j; i>=0; i--){//头 
				dp[i][j]=dp[i+1][j]+1;
				for(int k=i+1; k<=j; k++){//中间分割点 
					if(s2[i]==s2[k])
						dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
				}
			}
		//ans[i]表示前i+1长度的子串转换成目标串需要的最小次数
		for(int i=0; i<=len; i++)
			ans[i]=dp[0][i];
		for(int i=0; i<len; i++){ 
			if(s1[i]==s2[i])
				ans[i]=ans[i-1];
			else{
				for(int j=0; j<i; j++)
					ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
			}
		}
		cout<<ans[len-1]<<endl;
	}
	return 0;
}
