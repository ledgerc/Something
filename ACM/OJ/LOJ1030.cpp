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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
1*n的方格 掷骰子 每到一个新的格子收集格子里的黄金
到第n格停止  问停止时所得到的金子的期望值

dp[i]表示到第i格时收拾金子的期望
dp[i]=1/6*(dp[i-k]) 1<=k<=6
*/
int main(){
	int T; sc(T);
	double dp[maxn]; int a[maxn];
	for(int kase=1; kase<=T; kase++){
		int n; sc(n);
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++)
			scanf("%lf",&dp[i]);
		
		for(int i=n-1; i>=0; i--){
			for(int j=1; j<=6&&i+j<=n; j++){
				dp[i]+=dp[i+j]/(n-i>6?6:n-i);
			}
		}
		printf("Case %d: %.6f\n",kase,dp[1]);
	}
}
