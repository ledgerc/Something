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
const int maxn = 40+7;
const int maxm = 4e2+7;
const double pi = acos(-1.0);

int dp[maxn][maxn][maxn][maxn];
int a[maxm];
int b[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		memset(b,0,sizeof b);
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=0; i<m; i++){
			int tmp; scanf("%d",&tmp);
			b[tmp]++;
		}
		dp[0][0][0][0]=a[1];
		for(int i=0; i<=b[1]; i++)
		for(int j=0; j<=b[2]; j++)
		for(int k=0; k<=b[3]; k++)
		for(int l=0; l<=b[4]; l++){
			if(i>0)
				dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+a[i+j*2+k*3+l*4+1]);
			if(j>0)
				dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+a[i+j*2+k*3+l*4+1]);
			if(k>0)
				dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+a[i+j*2+k*3+l*4+1]);
			if(l>0)
				dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+a[i+j*2+k*3+l*4+1]);
		}
		printf("%d\n",dp[b[1]][b[2]][b[3]][b[4]]);
	}
	return 0;
}
