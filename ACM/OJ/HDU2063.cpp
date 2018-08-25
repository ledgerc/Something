#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std; 
const int MAXN = 510;
int uN,vN;//u,v����Ŀ��ʹ��ǰ����븳ֵ
int g[MAXN][MAXN];//�ڽӾ���
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
	for(int v=0; v<vN; v++)
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
	for(int u=0; u<uN; u++){
		memset(used,false,sizeof used);
		if(dfs(u))
			res++;
	}
	return res;
}
int main(){
	int k;
	while(scanf("%d",&k)&&k){
		scanf("%d%d",&uN,&vN);
		memset(g,0,sizeof g);
		int u,v;
		while(k--){
			scanf("%d%d",&u,&v);
			g[--u][--v]=1;
		}
		printf("\n");
		printf("%d\n",hungary());
	}
	return 0;
}
