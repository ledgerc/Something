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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main(){
	int n,m;
	while(scanf("%s%s",s1,s2)!=EOF){
		memset(dp,0,sizeof dp);
		int len1=strlen(s1),len2=strlen(s2);
		for(int i=0; i<len1; i++)
			for(int j=0; j<len2; j++)
				if(s1[i]==s2[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
		printf("%d\n",dp[len1][len2]);
	}
}
