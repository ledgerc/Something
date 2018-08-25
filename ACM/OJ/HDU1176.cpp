#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1e5+7;
int a[maxn][12];
int dp[maxn][12];
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		int x,t,maxt=-1;
		for(int i=0; i<n; i++){
			scanf("%d%d",&x,&t);
			a[t][x]++;
			maxt=max(maxt,t);
		}
		dp[1][4]=a[1][4],dp[1][5]=a[1][5],dp[1][6]=a[1][6];
		for(int i=2; i<=maxt; i++){
			for(int j=0; j<11; j++){
				dp[i][j]=dp[i-1][j];
				if(j>0)
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
				if(j<10)
					dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
				dp[i][j]+=a[i][j];
			}
		}
		
		
		int ans=-1;
		for(int i=0; i<11; i++)
			ans=max(ans,dp[maxt][i]);
		printf("%d\n",ans);
	}
	return 0;
}
