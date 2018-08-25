/*
判断是不是仙人掌图 HDU3594 
性质1: 仙人掌图的DFS树没有横向边
性质2: low(v) <= dfn(u) v是u的儿子 
性质3: 设某个点 u 有 au 个儿子的low值小于dfn(u),同时u自己有bu条逆向边 则au+bu<2 
*/
int n,index;
bool flag; 
struct Edge{
	int to,next;
}edge[maxn];
int tot,head[maxn];
int vis[maxn];
int cnt[maxn],dfn[maxn],low[maxn];
//cnt表示经过的环数目 
//dfn表示的是其在树中的深度，low表示其经过移动可达到的最大高度（最小深度）
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
}
void dfs(int u){
	int v;
	if(!flag)
		return;
	dfn[u]=low[u]=++index;
	vis[u]=1;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v = edge[i].to;
		if(vis[v]==2){//出现了横向边
			flag=false;
			return;
		}
		if(!vis[v]){
			dfs(v);
			//如果其子节点所能达到的最大高度小于父节点，那么子节点一定不能达到父节点，所以不是连通图
			if(low[v]>dfn[u]){
				flag=false;
				return;
			}
			if(low[v]<dfn[u]){
				++cnt[u];//经过u的环+1
				if(low[v]<low[u])//更新所能达到的最大高度。
					low[u]=low[v];
			}
		}
		else if(low[v]<dfn[u]){
			++cnt[u];//经过u的环+1
			if(low[v]<low[u])//更新所能达到的最大高度。
				low[u]=low[v];
		}
		if(cnt[u]>1){//性质3
			flag=false;
			return;
		}
	}
	vis[u]=2;//以u为根节点 的子树访问完毕，如果再有访问的话就是横向边.
}
void init(){
	tot=0;
	memset(head,-1,sizeof head);
	memset(cnt,0,sizeof cnt);
	memset(vis,false,sizeof vis);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		int u,v;
		while(scanf("%d%d",&u,&v)){
			if(u==0&&v==0)
				break;
			addedge(u+1,v+1);
		}
		flag=true;
		index=0;
		dfs(1);
		if(!flag||index<n)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}






int n,m,cnt,ind,ans;
int last[maxn],deep[maxn],f[maxn];//f是其到子节点中最大路径长度
int low[maxn],dfn[maxn],fa[maxn];
int a[maxn<<1],q[maxn<<1],l,r;
struct edge{int to,next;}e[maxn<<3];
void insert(int u,int v){
   e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
   e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void dp(int root,int x){
	int tot=deep[x]-deep[root]+1;
	for(int i=x;i!=root;i=fa[i]) a[tot--]=f[i];
	a[tot]=f[root];
	tot=deep[x]-deep[root]+1;
	for(int i=1;i<=tot;++i) a[i+tot]=a[i];//二倍的原因是单调队列简化需要（这个操作我不太会)
	//感觉很有道理的样子
	q[1]=1;l=r=1;
	for(int i=2;i<=2*tot;++i){  //单调队列
    	while(l<=r&&i-q[l]>tot/2) ++l;//题干要求最短路，大于tot/2的要删掉
    	ans=max(ans,a[i]+i+a[q[l]]-q[l]) ;//i-q[l]是在主路径上i到q[l]的最短距离，再加上各自的子树中的f
    	while(l<=r&&a[q[r]]-q[r]<=a[i]-i) --r;  //观察通项就可以的出这个了
    	q[++r]=i;
	}
	for(int i=2;i<=tot;++i)
	f[root]=max(f[root],a[i]+min(i-1,tot-i+1)); //有环的子节点要特殊更新一下
}
void dfs(int x){
	low[x]=dfn[x]=++ind;
	for(int i=last[x];i;i=e[i].next)
	if(e[i].to!=fa[x]){
   		if(!dfn[e[i].to]){
    		fa[e[i].to]=x;
    		deep[e[i].to]=deep[x]+1;
    		dfs(e[i].to);
    		low[x]=min(low[x],low[e[i].to]);
		}
   		else
		   	low[x]=min(low[x],dfn[e[i].to]);
   		if(dfn[x]<low[e[i].to]){
			ans=max(ans,f[x]+f[e[i].to]+1);
			f[x]=max(f[x],f[e[i].to]+1);
   		}
	}
	for(int i=last[x];i;i=e[i].next)//处理成环的子树
		if(fa[e[i].to]!=x&&dfn[x]<dfn[e[i].to])
	dp(x,e[i].to);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int k,a,b;
		scanf("%d%d",&k,&a);
		for(int i=2;i<=k;i++){
    		scanf("%d",&b);
			insert(a,b);a=b;
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}



//HDU6041
//
int n,m,k;
int tot,head[maxn];
struct Edge{
	int to,next,cost;
}edge[maxn];
void addedge(int u,int v,int cost){
	edge[tot].to=v; edge[tot].cost=cost;
	edge[tot].next=head[u]; head[u]=tot++;
}
struct Node{
	int val,id1,id2;
	Node(int val,int id1,int id2):val(val),id1(id1),id2(id2){}
	bool operator < ( const Node & a ) const{
		return val<a.val;
	}
};
int dfn[maxn],low[maxn],index;
bool vis[maxn];
stack<int> st;
int a[maxn],b[maxn],vec[maxn];
void init(){
	index=0,tot=0; a[0]=0;
	memset(vis,false,sizeof vis);
	memset(head,-1,sizeof head);
}
void unite(int *a,int *b){
	priority_queue<Node> que;
	for(int i=1; i<=b[0]; i++)
		que.push(Node(a[1]+b[i],1,i));
	vec[0]=0;
	while(vec[0]<k&&!que.empty()){
		Node now=que.top(); que.pop();
		vec[++vec[0]]=now.val;
		if(now.id1+1<=a[0]){
			now.id1++;
			que.push(Node(a[now.id1]+b[now.id2],now.id1,now.id2));
		}
	}
	for(int i=0; i<=vec[0]; i++)
		a[i]=vec[i];
}
void Tarjan(int u,int pre){
	dfn[u]=low[u]=index++;
	vis[u]=true;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v = edge[i].to;
		if(v==pre) continue;
		if(!vis[v]){
			st.push(i);
			Tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){//u是割点
				b[0]=0;
				int tmp;
				do{
					tmp=st.top(); st.pop();
					b[++b[0]]=edge[tmp].cost;
				}while(tmp!=i);
				if(b[0]>1)//找到环
					unite(a,b);
			}
		}
		if(vis[v]&&dfn[v]<dfn[u]){//防止一个边被加入多次
			st.push(i);
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	int kase=1;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		int sum=0;
		for(int i=0; i<m; i++){
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w); addedge(v,u,w);
			sum+=w;
		}
		scanf("%d",&k);
		a[++a[0]]=0;
		Tarjan(1,-1);
		unsigned ans=0;
		for(int i=1; i<=a[0]; i++)
			ans+=(i*(sum-a[i]));
		printf("Case #%d: %u\n",kase++,ans);
	}
	return 0;
}
