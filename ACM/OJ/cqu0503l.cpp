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
#include<bitset>
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
const int maxn = 1e3+7;
const int maxm = 2e3+7;
const double pi = acos(-1.0);

int T,n,m;
struct Edge{
	int u,v;
}edge[maxm];
bool vis[maxn];
int ans;
void dfs(int cnt,int pos){
	if(cnt>10)
		return;
	for(int i=pos; i<=m; i++){
		if(vis[edge[i].u]||vis[edge[i].v])
			continue;
		vis[edge[i].u]=true;
		dfs(cnt+1,i+1);
		vis[edge[i].u]=false;
		vis[edge[i].v]=true;
		dfs(cnt+1,i+1);
		vis[edge[i].v]=false;
		return;
	}
	ans=min(ans,cnt);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=m; i++)
			scanf("%d%d",&edge[i].u,&edge[i].v);
		memset(vis,false,sizeof vis);
		ans=inf;
		dfs(0,1);
		if(ans==inf)
			printf("Poor lcy\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
