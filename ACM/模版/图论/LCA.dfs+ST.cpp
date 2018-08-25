/*
HDU 5296
*/
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
set<int> s; set<int>::iterator it;
bool vis[maxn];//判断点是否在集合中
int calc(int u){
	if(s.empty())
		return 0;
	it=s.upper_bound(u);
	int x,y;//x,y分别是比dfs序为u的点大的最小点和比它小的最大点
	if(it==s.end()||it==s.begin()){
		x = lca.ver[*s.rbegin()];
		y = lca.ver[*s.begin()];
	}
	else{
		x = lca.ver[*it];
		it--;
		y = lca.ver[*it];
	}
	u = lca.ver[u];
	return lca.dis[u] - lca.dis[lca.Lca(x,u)] - lca.dis[lca.Lca(y,u)] + lca.dis[lca.Lca(x,y)];
}
int main(){
	int T; scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		int n,m; scanf("%d%d",&n,&m);
		memset(vis,false,sizeof vis);
		s.clear(); lca.init(); int cnt=0;
		for(int i=1; i<n; i++){
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			lca.addedge(u,v,w,cnt);
			lca.addedge(v,u,w,cnt);
		}
		lca.dfs(1,-1,-1); lca.ST(2*n-1);
		printf("Case #%d:\n",kase);
		int op,u,ans=0;
		while(m--){
			scanf("%d%d",&op,&u);
			if(op==1){
				if(!vis[u]){
					vis[u]=true;
					ans += calc(lca.first[u]);
					s.insert(lca.first[u]);
				}
			}
			else{
				if(vis[u]){
					vis[u]=false;
					s.erase(lca.first[u]);
					ans-=calc(lca.first[u]);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
