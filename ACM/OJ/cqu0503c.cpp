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
const int maxn = 5e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int T,n,m;
bool mp[maxn][maxn];
vector<int> e[maxn];
int color[maxn];
void addedge(int u,int v){
	e[u].push_back(v);
}
bool dfs(int v,int c){
	color[v]=c;
	for(int i=0; i<e[v].size(); i++){
		if(color[e[v][i]]==c)
			return false;
		if(color[e[v][i]]==0 && !dfs(e[v][i],-c))
			return false;
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(mp,false,sizeof mp);
		memset(color,0,sizeof color);
		for(int i=1; i<=n; i++)
			mp[i][i]=true;
		for(int i=0; i<=n; i++)
			e[i].clear();
		for(int i=0; i<m; i++){
			int u,v; scanf("%d%d",&u,&v);
			mp[u][v]=mp[v][u]=true;
		}
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++){
				if(!mp[i][j]&&i!=j){
					addedge(i,j);
				}
			}
		bool flag=true;
		for(int i=1; i<=n; i++)
			if(color[i]==0&&e[i].size()!=0){
				if(!dfs(i,1)){
					flag=false;
					break;
				}
			}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j)
					continue;
				if(mp[i][j]&&color[i]*color[j]<0){
						flag=false;
				}
				if(!mp[i][j]&&color[i]*color[j]>=0){
					flag=false;
				}
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
