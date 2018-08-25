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

//定义状态dp[i][j] : 当前i节点及其子树下最多选择j个城市的最大值为dp[i][j];

/*
1. 判断当前节点P有没有孩子，如果有则令当前节点为P重复(1)操作，如果没有则到(2)操作； 
2. 将当前节点P的状态更新到期父节点上， 
更新操作为dp[P'father][i] = max(dp[P'father][i], dp[P'father][j]+dp[P][k])    (j + k = i ,j>0,k>0,2<=i<=max_cost,对于每一个i遍历每一种(j,k)组合) 
这里的dp[P'father][j] j个城市一定是没有包括P城市的其他j个城市的最大值  
直到遍历到root节点即可(dp[0][i]) 
3.输出dp[0][max_cost] 
max_cost 为题目中所给出的最多取几个城市
*/
vector<int> list[maxn];
int dp[maxn][maxn];
int n,m;

void dfs(int u){
	for(int i=0; i<list[u].size(); i++){
		int v=list[u][i];
		if(list[v].size()>0)
			dfs(v);
		for(int j=m; j>1; j--){
			for(int k=1; k<j; k++)
				dp[u][j]=max(dp[u][j],dp[u][k]+dp[v][j-k]);
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0)
			break;
		m++;
		memset(dp,0,sizeof dp);
		for(int i=0; i<=n; i++)
			list[i].clear();
		for(int i=1; i<=n; i++){
			int u,v; cin>>u>>v;
			list[u].push_back(i);
			for(int j=1; j<=m; j++)
				dp[i][j]=v;
		}
		dfs(0);
		cout<<dp[0][m]<<endl;
	}
	return 0;
}
