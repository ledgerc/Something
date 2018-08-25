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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


char s[maxn];
int dp[maxn][maxn];
bool check(char a,char b){
	if(a=='('&&b==')')
		return true;
	if(a=='['&&b==']')
		return true;
	return false;
}
int main(){
	while(scanf("%s",s)!=EOF){
		memset(dp,0,sizeof dp);
		if(s[0]=='e')
			break;
		int len=strlen(s);
		for(int k=1; k<=len; k++){//表示区间长度，从0-len更新
			for(int i=0,j=k; j<len; i++,j++){
				if(check(s[i],s[j]))
					dp[i][j]=dp[i+1][j-1]+2;
				for(int tmp=i; tmp<j; tmp++)//区间最值合并
					dp[i][j]=max(dp[i][j],dp[i][tmp]+dp[tmp+1][j]);
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}
