//区间静态第K大 
int n,m,q;
int a[maxn],t[maxn];
int tot,T[maxm],lson[maxm],rson[maxm],c[maxm];
void init_hash(){
	for(int i=1; i<=n; i++) t[i]=a[i];
	sort(t+1,t+n+1);
	m=unique(t+1,t+n+1)-t-1;
}
int hsh(int x){
	return lower_bound(t+1,t+m+1,x)-t;
}
int build(int l,int r){
	int root=tot++;
	c[root]=0;
	if(l!=r){
		int mid=l+r>>1;
		lson[root]=build(l,mid);
		rson[root]=build(mid+1,r);
	}
	return root;
}
int update(int root,int pos,int val){
	int newroot=tot++; int tmp=newroot;
	c[newroot]=c[root]+val;
	int l=1,r=m;
	while(l<r){
		int mid=l+r>>1;
		if(pos<=mid){
			lson[newroot]=tot++; rson[newroot]=rson[root];
			newroot=lson[newroot]; root=lson[root];
			r=mid;
		}
		else{
			rson[newroot]=tot++; lson[newroot]=lson[root];
			newroot=rson[newroot]; root=rson[root];
			l=mid+1; 
		}
		c[newroot]=c[root]+val;
	}
	return tmp;
}
int query(int lroot,int rroot,int k){
	int l=1,r=m;
	while(l<r){
		int mid=l+r>>1;
		if(c[lson[lroot]]-c[lson[rroot]]>=k){
			r=mid;
			lroot=lson[lroot]; rroot=lson[rroot];
		}
		else{
			l=mid+1;
			k-=c[lson[lroot]]-c[lson[rroot]];
			lroot=rson[lroot]; rroot=rson[rroot];
		}
	}
	return l;
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		tot=0;
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		init_hash();
		T[n+1]=build(1,m);
		for(int i=n; i; i--){
			int pos=hsh(a[i]);
			T[i]=update(T[i+1],pos,1);
		}
		while(q--){
			int l,r,k; scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",t[query(T[l],T[r+1],k)]);
		}
	}
	return 0;
}


//求树上u到v的最大点值
//区分一下关于路径的主席树还是关于子树的主席树;
//关于子树dfs节点依次关于 前一个dfs的节点 建 
//关于路径dfs节点关于 父亲 节点建 
int n,m,q;
int a[maxn],t[maxn];
int tot,T[maxm],lson[maxm],rson[maxm],c[maxm];
void init_hash(){
	for(int i=1; i<=n; i++) t[i]=a[i];
	sort(t+1,t+n+1);
	m=unique(t+1,t+n+1)-t-1;
}
int hsh(int x){
	return lower_bound(t+1,t+m+1,x)-t;
}
int build(int l,int r){
	int root=tot++;
	c[root]=0;
	if(l!=r){
		int mid=l+r>>1;
		lson[root]=build(l,mid);
		rson[root]=build(mid+1,r);
	}
	return root;
}
int update(int root,int pos,int val){
	int newroot=tot++; int tmp=newroot;
	c[newroot]=c[root]+val;
	int l=1,r=m;
	while(l<r){
		int mid=l+r>>1;
		if(pos<=mid){
			lson[newroot]=tot++; rson[newroot]=rson[root];
			newroot=lson[newroot]; root=lson[root];
			r=mid;
		}
		else{
			rson[newroot]=tot++; lson[newroot]=lson[root];
			newroot=rson[newroot]; root=rson[root];
			l=mid+1; 
		}
		c[newroot]=c[root]+val;
	}
	return tmp;
}
int query(int l_root,int r_root,int _lca,int k){
	int lca_root = T[_lca]; int pos = hsh(a[_lca]);
	int l=1,r=m;
	while(l<r){
		int mid=l+r>>1;
		int tmp = c[lson[l_root]]+c[lson[r_root]]-2*c[lson[lca_root]]+(pos>=l&&pos<=mid);
		if(tmp>=k){
			l_root=lson[l_root]; r_root=lson[r_root]; lca_root=lson[lca_root];
			r=mid;
		}
		else{
			k-=tmp;
			l_root=rson[l_root]; r_root=rson[r_root]; lca_root=rson[lca_root];
			l=mid+1;
		}
	}
	return l;
}

struct Edge{
	int u,v,w,next;
};
struct LCA{
	int dp[2*maxn][50];
	int tot,head[maxn];
	Edge edge[maxn*2];
	void addedge(int u,int v,int &cnt){
		edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=1;
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
			if(vis[v]) continue;
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
void dfs_build(int u,int pre){
	int pos=hsh(a[u]);
	T[u]=update(T[pre],pos,1);
	for(int i=lca.head[u]; i!=-1; i=lca.edge[i].next){
		int v=lca.edge[i].v;
		if(v==pre) continue;
		dfs_build(v,u);
	}
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		tot=0; init_hash(); lca.init(); int cnt=0;
		for(int i=1; i<n; i++){
			int u,v; scanf("%d%d",&u,&v);
			lca.addedge(u,v,cnt); lca.addedge(v,u,cnt);
		}
		lca.dfs(1,-1,1); lca.ST(2*n-1);
		T[n+1]=build(1,m);
		dfs_build(1,n+1);
		while(q--){
			int u,v,k; scanf("%d%d%d",&u,&v,&k);
			printf("%d\n",t[query(T[u],T[v],lca.Lca(u,v),k)]);
		}
	}
	return 0;
}


//区间加 区间查询
int tot,T[maxn],lson[maxn],rson[maxn];
ll add[maxn],sum[maxn];
int build(int l,int r){
	int root=tot++;
	add[root]=0;
	if(l==r){
		scanf("%lld",&sum[root]);
		return root;
	}
	int mid=l+r>>1;
	lson[root]=build(l,mid);
	rson[root]=build(mid+1,r);
	sum[root]=sum[lson[root]]+sum[rson[root]];
	return root;
}
//l-r 当前节点区间 L-R 更新区间 
int update(int root,int l,int r,int L,int R,ll val){
	int newroot=tot++;
	sum[newroot]=sum[root],add[newroot]=add[root];
	lson[newroot]=lson[root],rson[newroot]=rson[root];
	if(L<=l&&R>=r){
		sum[newroot]+=(ll)(r-l+1)*val;
		add[newroot]+=val;
		return newroot;
	}
	int mid=l+r>>1;
	if(L<=mid)
		lson[newroot]=update(lson[root],l,mid,L,R,val);
	if(R>mid)
		rson[newroot]=update(rson[root],mid+1,r,L,R,val);
	sum[newroot]=sum[lson[newroot]]+sum[rson[newroot]]+(ll)(r-l+1)*add[newroot];
	return newroot;
}
//L-R 查询区间 l-r 当前结点区间 
ll query(int root,int l,int r,int L,int R){
	if(L<=l&&R>=r) return sum[root];
	ll res=0;
	if(l<=L){
		if(r>=R)
			res+=(ll)(R-L+1)*add[root];
		else
			res+=(ll)(r-L+1)*add[root];
	}
	else
		res+=(ll)(R-l+1)*add[root];
	int mid=l+r>>1;
	if(L<=mid)
		res+=query(lson[root],l,mid,L,R);
	if(R>mid)
		res+=query(rson[root],mid+1,r,L,R);
	return res;
}
int main(){
	int n,m,now; char op[10];
	while(scanf("%d%d",&n,&m)!=EOF){
		tot=now=1; T[now]=build(1,n);
		while(m--){
			scanf("%s",op);
			if(op[0]=='C'){
				int l,r; ll val; scanf("%d%d%lld",&l,&r,&val);
				T[now+1]=update(T[now],1,n,l,r,val);
				now++;
			}
			else if(op[0]=='Q'){
				int l,r; scanf("%d%d",&l,&r);
				printf("%lld\n",query(T[now],1,n,l,r));
			}
			else if(op[0]=='H'){
				int l,r,t; scanf("%d%d%d",&l,&r,&t);
				printf("%lld\n",query(T[t+1],1,n,l,r));
			}
			else{
				scanf("%d",&now); now++;
			}
		}
	}
}
