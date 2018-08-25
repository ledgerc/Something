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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


int n;
int dp[maxn][2],f[maxn];
bool vis[maxn];
void treedp(int root){
	vis[root]=true;
	for(int i=1; i<=n; i++){
		if(!vis[i]&&f[i]==root){
			treedp(i);
			dp[root][1]+=dp[i][0];
			dp[root][0]+=max(dp[i][1],dp[i][0]);
		}
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof dp);
		memset(f,0,sizeof f);
		memset(vis,0,sizeof vis);
		for(int i=1; i<=n; i++)
			scanf("%d",&dp[i][1]);
		int root=0;
		bool flag=1;
		int tmp1,tmp2;
		while(scanf("%d %d",&tmp1,&tmp2),tmp1||tmp2){
			f[tmp1]=tmp2;
			if(root==tmp1)
				root=tmp2;
		}
		while(f[root])
			root=f[root];
		treedp(root);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}
	return 0;
}
