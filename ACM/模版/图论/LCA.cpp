//倍增 
//POJ1330
const int DEG = 20;
struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int fa[maxn][DEG];//fa[i][j]表示结点i的第2^j个祖先
int deg[maxn];//深度数组 
void bfs(int root){
	queue<int> que;
	deg[root]=0;
	fa[root][0]=root;
	que.push(root);
	while(!que.empty()){
		int tmp=que.front(); que.pop();
		for(int i=1; i<DEG; i++)
			fa[tmp][i]=fa[fa[tmp][i-1]][i-1];
		for(int i=head[tmp]; i!=-1; i=edge[i].next){
			int v=edge[i].to;
			if(v==fa[tmp][0])
				continue;
			deg[v]=deg[tmp]+1;
			fa[v][0]=tmp;
			que.push(v);
		}
	}
}
int LCA(int u,int v){
	if(deg[u]>deg[v])
		swap(u,v);
	int hu=deg[u],hv=deg[v];
	int tu=u,tv=v;
	//让u和v上升到同一高度 
	for(int det=hv-hu,i=0; det; det>>=1,i++)
		if(deg&1)
			tv=fa[tv][i];
	if(tu==tv)
		return tu;
	//二分搜索LCA 
	for(int i=DEG-1; i>=0; i--){
		if(fa[tu][i]==fa[tv][i])
			continue;
		tu=fa[tu][i];
		tv=fa[tv][i];
	}
	return fa[tu][0];
}
bool flag[maxn];
int main(){
	int T;
	int n,u,v;
	while(T--){
		cin>>n; init();
		memset(flag,false,sizeof flag);
		for(int i=1; i<n; i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);addedge(v,u);
			flag[v]=true;
		}
		int root;
		for(int i=1; i<=n; i++)
			if(!flag[i]){
				root=i;
				break;
			}
		BFS(root);
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}







 
/*
* POJ 1470
* 给出一颗有向树，Q个查询
* 输出查询结果中每个点出现次数
*/
/*
* LCA离线算法，Tarjan
*复杂度O(n+Q);
*/
//
int F[maxn];
int find(int x){
	if(F[x]==-1)
		return x;
	return F[x]=find(F[x]);
}
void unite(int u,int v){
	int tmp1=find(u),tmp2=find(v);
	if(tmp1!=tmp2);
		F[tmp1]=tmp2;
}

bool vis[maxn];
int ancestor[maxn];
struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}

struct Query{
	int q,next;
	int index;
}query[maxm*2];
int answer[maxm];
int h[maxm];
int tt,Q;

void addquery(int u,int v,int index){
	query[tt].q=v;
	query[tt].next=h[u];
	query[tt].index=index;
	h[u]=tt++;
	query[tt].q=u;
	query[tt].next=h[v];
	query[tt].index=index;
	h[v]=tt++;
}
void init(){
	tot=0;
	memset(head,-1,sizeof head);
	tt=0;
	memset(h,-1,sizeof h);
	memset(vis,false,sizeof vis);
	memset(F,-1,sizeof F);
	memset(ancestor,0,sizeof ancestor);
}

void LCA(int u){
	ancestor[u]=u;
	vis[u]=true;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(vis[v])
			continue;
		LCA(v);
		unite(u,v);
		ancestor[find(u)]=u;
	}
	for(int i=h[u]; i!=-1; i=query[i].next){
		int v=query[i].q;
		if(vis[u])
			answer[query[i].index]=ancestor[find(v)];
	}
}

bool flag[maxn];
int Count_num[maxn];
int main(){
	int n; int u,v,k;
	while(scanf("%d",&n)!=EOF){
		init();
		memset(flag,false,sizeof flag);
		for(int i=1; i<=n; i++){
			scanf("%d:(%d)",&u,&k);
			while(k--){
				scanf("%d",&v);
				flag[v] = true;
				addedge(u,v);
				addedge(v,u);
			}
		}
		cin>>Q;
		for(int i=0; i<Q; i++){
			char c; cin>>c;
			scanf("%d %d)",&u,&v);
			addquery(u,v,i);
		}
		int root;
		for(int i=1; i<=n; i++)
			if(!flag[i]){
				root=i;
				break;
			}
		LCA(root);
		memset(Count_num,0,sizeof Count_num);
		for(int i = 0;i < Q;i++)
			Count_num[answer[i]]++;
		for(int i = 1;i <= n;i++)
			if(Count_num[i] > 0)
				printf("%d:%d\n",i,Count_num[i]);
	}
	return 0;
}


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
	/*	for(int i=1; i<2*n; i++)
			cout<<lca.ver[i]<<" ";
		cout<<endl;
		for(int i=1; i<=n; i++)
			cout<<lca.first[i]<<" ";
		cout<<endl;
		for(int i=1; i<=n; i++)
			cout<<lca.dis[i]<<" ";
		cout<<endl;*/
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
