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

int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int pre[maxn][maxn];
void P(int i,int j){
	if(i==0&&j==0)
		return ;
	if(pre[i][j]==1)
		P(i,j-1),printf("%c",s2[j]);
	else if(pre[i][j]==3)
		P(i-1,j),printf("%c",s1[i]);
	else
		P(i-1,j-1),printf("%c",s1[i]);
}
int main(){
	while(scanf("%s%s",s1,s2)!=EOF){
		int len1=strlen(s1),len2=strlen(s2);
		for(int i=len1; i>0; i--)
			s1[i]=s1[i-1];
		for(int i=len2; i>0; i--)
			s2[i]=s2[i-1];
		memset(dp,0,sizeof dp);
		memset(pre,0,sizeof pre);
		for(int i=0; i<=len1; i++)
			pre[i][0]=3;
		for(int i=0; i<=len2; i++)
			pre[0][i]=1;
		for(int i=1; i<=len1; i++)
			for(int j=1; j<=len2; j++)
				if(s1[i]==s2[j]){
					dp[i][j]=dp[i-1][j-1]+1;
					pre[i][j]=2;
				}
				else if(dp[i][j-1]>dp[i-1][j]){
					dp[i][j]=dp[i][j-1];
					pre[i][j]=1;
				}
				else{
					dp[i][j]=dp[i-1][j];
					pre[i][j]=3;	
				}
		P(len1,len2);
		cout<<endl;
	}
	return 0;
}
