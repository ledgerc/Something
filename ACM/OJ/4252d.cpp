#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 4e5+7;
const int maxm = 4e6+7;
const double pi = acos(-1.0);

struct Edge{
	int u,v,w,next;
};
struct LCA{
	int dp[2*maxn][50];
	int tot,head[maxn];
	Edge edge[maxn*2];
	void addedge(int u,int v,int w,int &cnt){
		edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w;
		edge[cnt].next=head[u]; head[u]=cnt++;
	}
	//深度 距离 
	int d[maxn],dis[maxn];
	//欧拉序列，就是dfs遍历的顺序，长度为2*n-1,下标从1开始
	//表示点i在ver中第一次出现的位置(节点i的dfs序)
	int ver[2*maxn],first[maxn];
	bool vis[maxn];
	void init(){
		tot=0; dis[1]=0;
		memset(head,-1,sizeof head);
		memset(vis,false,sizeof vis);
	}
	void dfs(int u,int dep,int pre){
		vis[u]=true;
		ver[++tot]=u;
		first[u]=tot;
		d[tot]=dep;
		for(int i=head[u]; i!=-1; i=edge[i].next){
			int v = edge[i].v,w = edge[i].w;
			if(vis[v])
				continue;
			dis[v]=dis[u]+w;
			dfs(v,dep+1,u);
			ver[++tot]=u;
			d[tot]=dep;
		}
	}
	void ST(int n){
		for(int i=1; i<=n; i++)
			dp[i][0]=i;
		for(int j=1; (1<<j)<=n; j++)
			for(int i=1; i+(1<<j)-1<=n; i++){
				int a=dp[i][j - 1],b=dp[i+(1<<(j-1))][j-1];
				dp[i][j]=d[a]<d[b]?a:b;
			}
	}
	int RMQ(int l,int r){
		int k=0;
		while((1<<(k+1))<=r-l+1)
			k++;
        int a=dp[l][k],b=dp[r-(1<<k)+1][k];
        return d[a]<d[b]?a:b;
	}
	int Lca(int u,int v){
		int x = first[u], y = first[v];
		if(x>y)
			swap(x,y);
		return ver[RMQ(x,y)];
	}
}lca;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	int tot=0;
	lca.init(); 
	for(int i=2; i<=n; i++){
		int tmp; scanf("%d",&tmp);
		lca.addedge(i,tmp,1,tot); lca.addedge(tmp,i,1,tot);
	}
	lca.dfs(1,-1,-1); lca.ST(2*n-1);
	while(m--){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		int tmp1 = lca.dis[a] + lca.dis[b] - 2*lca.dis[lca.Lca(a,b)];
		int tmp2 = lca.dis[a] + lca.dis[c] - 2*lca.dis[lca.Lca(a,c)];
		int tmp3 = lca.dis[b] + lca.dis[c] - 2*lca.dis[lca.Lca(b,c)];
	//	pr(tmp1) pr(tmp2) prln(tmp3)
		int ans=-1;
		ans = max(ans,tmp1+tmp2-tmp3);
		ans = max(ans,tmp1+tmp3-tmp2);
		ans = max(ans,tmp2+tmp3-tmp1);
		printf("%d\n",ans/2+1);
	}
}
