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
const int MAXN = 150;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
	int v;
	for(v=0; v<vN; v++){
		if(g[u][v]&&!used[v]){		
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}
int hungary(){
	int res=0;
	int u;
	memset(linker,-1,sizeof linker);
	for(u=0; u<uN; u++){
		memset(used,0,sizeof used);
		if(dfs(u))
			res++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int T; cin>>T;
	int k,n,u,v;
	while(T--){
		cin>>n>>k;
		memset(g,0,sizeof g);
		while(k--){
			cin>>u>>v;
			u--,v--;
			g[u][v]=1;
		}
		uN=vN=n;
		printf("%d\n",n-hungary());
	}
	return 0;
}
