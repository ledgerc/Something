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

const int MAXN = 510;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
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
	int n,k; cin>>n>>k;
	vN=uN=n;
	memset(g,0,sizeof g);
	for(int i=0; i<k; i++){
		int x,y; cin>>x>>y;
		x--,y--;
		g[x][y]=true;
	}
	int ans=hungary();
	cout<<ans<<endl;
	return 0;
}
