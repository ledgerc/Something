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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int s,n;
const int MAXN = 2100;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
	for(int v=1; v<=vN; v++)
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	return false;
}
int hungary(){
	int res=0;
	memset(linker,-1,sizeof linker);
	for(int u=1; u<=uN; u++){
		memset(used,false,sizeof used);
		if(dfs(u))
			res++;
	}
	return res;
}
void init(){
	memset(g,0,sizeof g);
	for(int i=1; i<=n; i++){
		int tmp=i+s;
		for(int j=1; j<=n; j++)
			if(tmp%j==0)
				g[i][j]=1;
	}
}
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		scanf("%d%d",&s,&n);
		if(s<n)
			swap(s,n);
		uN=vN=n;
		if(n>1000){
			printf("Case #%d: No\n",kase);
			continue;
		}
		init();
		int ans=hungary();
		//cout<<ans<<endl;
		if(ans==n)
			printf("Case #%d: Yes\n",kase);
		else
			printf("Case #%d: No\n",kase);
	}
	return 0;
}
