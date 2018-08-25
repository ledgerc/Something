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

//二分图多重匹配
const int MAXN = 100010;
const int MAXM = 11;
int uN,vN;
int g[MAXN][MAXM];
int linker[MAXM][MAXN];
bool used[MAXM];
int num[MAXM];//
bool dfs(int u){
	for(int v=0; v<vN; v++){
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v][0]<num[v]){
				linker[v][++linker[v][0]]=u;
				return true;
			}
			for(int i=1; i<=num[0]; i++)
				if(dfs(linker[v][i])){
					linker[v][i]=u;
					return true;
				}
		}
	}
	return false;
}
bool hungary(){
	int res=0;
	for(int i=0; i<vN; i++)
		linker[i][0]=0;
	for(int u=0; u<uN; u++){
		memset(used,false,sizeof used);
		if(dfs(u)==false)
			return false;
	}
	return true;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(g,0,sizeof g);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&g[i][j]);
		for(int i=0; i<m; i++)
			scanf("%d",&num[i]);
		uN=n,vN=m;
		if(hungary())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
