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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 21;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char mp[maxn][maxn];
bool vis[maxn];
int n;
bool dp[maxn][1<<maxn];
int ans[maxn];
bool dfs(int cur,int step,int st){
	ans[step]=cur;
	if(step==n){
		if(mp[cur][1]=='W'||mp[1][cur]=='L'){
			cout<<ans[1];
			for(int i=2; i<=n; i++)
				cout<<" "<<ans[i];
			cout<<endl;
			return true;
		} 
	}
	int x=1;
	for(int i=2; i<=n; i++){
		x<<=1;
		int nowst=st|(1<<i);
		if(!vis[i]&&!dp[i][nowst]&&(mp[cur][i]=='W'||mp[i][cur]=='L')){
			vis[i]=1;
			if(dfs(i,step+1,nowst))
				return 1;
			vis[i]=0;
		}
		if(!vis[i])
			dp[i][nowst]=true;
	}
	return false;
}
int main(){
	memset(dp,false,sizeof dp);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%s",mp[i]+1);
	vis[1]=true;
	if(!dfs(1,1,1))
		cout<<"No Solution"<<endl;
	return 0;
}
