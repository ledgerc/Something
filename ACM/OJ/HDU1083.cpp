#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std; 
const int MAXN = 310;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];
bool used[MAXN];
int n;
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
int color[MAXN];
bool dcolor(int u){
	for(int i=1; i<=n; i++){
		if(g[u][i]){
			if(!color[i]){
				color[i]=-color[u];
				if(!dcolor(i))
					return false;
			}
			else if(color[i]==color[u])
				return false;
		}
	}
	return true;
}
bool judge(){
	memset(color,0,sizeof color);
	for(int i=1; i<=n; i++)
		if(color[i]==0){
			color[i]=1;
			if(!dcolor(i))
				return false;
		}
	return true;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&uN,&vN);
		memset(g,0,sizeof g);
		int v;
		for(int u=1; u<=uN; u++){
			scanf("%d",&n);
			while(n--){
				scanf("%d",&v);
				g[u][v]=1;
			}
		}
		if(uN==hungary())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
