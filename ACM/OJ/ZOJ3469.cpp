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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Node{
	int x,val;
}s[maxn];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int sum[maxn],dp[maxn][maxn][2];
int main(){
	int N,V,X;
	while(scanf("%d%d%d",&N,&V,&X)!=EOF){
		for(int i=1; i<=N; i++){
			sc(s[i].x); sc(s[i].val);
		}
		s[N+1].x=X; s[N+1].val=0;
		N++;
		sort(s+1,s+1+N,cmp);
		memset(dp,inf,sizeof dp);
		sum[0]=0;
		for(int i=1; i<=N; i++){
			sum[i]=sum[i-1]+s[i].val;
			if(s[i].x==X&&s[i].val==0)
				dp[i][i][0]=dp[i][i][1]=0;
		}
		for(int l=2; l<=N; l++){
			for(int i=1; i+l<=N+1; i++){
				int j=i+l-1;
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(s[i+1].x-s[i].x)*(sum[i]+sum[N]-sum[j]));
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(s[j].x-s[i].x)*(sum[i]+sum[N]-sum[j]));
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(s[j].x-s[i].x)*(sum[i-1]+sum[N]-sum[j-1]));
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(s[j].x-s[j-1].x)*(sum[i-1]+sum[N]-sum[j-1]));
			}
		}
		printf("%d\n",min(dp[1][N][0],dp[1][N][1])*V);
	}
}
