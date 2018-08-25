struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
int size[maxn];//保存以x为根的子树节点个数
int dep[maxn]; //保存当前节点的深度
int fa[maxn];  //保存当前节点的父亲
int son[maxn]; //保存重儿子
int top[maxn]; //保存当前节点的所在链的顶端节点
int p[maxn];   //保存树中每个节点剖分后的新编号
int fp[maxn];  //fp和p数组相反
int pos;
void init(){
	tot=0; pos=1;
	memset(head,-1,sizeof head);
	memset(son,-1,sizeof son);
}
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
} 
//记录所有的重边 
void dfs1(int u,int father,int d){
	dep[u]=d;
	fa[u]=father;
	size[u]=1;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=father){
			dfs1(v,u,d+1);
			size[u]+=size[v];
			if(son[u]==-1||size[v]>size[son[u]])
				son[u]=v;
		}
	}
}
//连重边成重链
void dfs2(int u,int tp){
	top[u]=tp;
	p[u]=pos++;
	fp[p[u]]=u;
	if(son[u]==-1)
		return;
	dfs2(son[u],tp);
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u])
			dfs2(v,v);
	}
}

int c[maxn];
int n;
int lowbit(int x){
	return x&(-x);
}
int Sum(int i){
	int res=0;
	while(i>0){
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int val){
	while(i<=n){
		c[i]+=val;
		i+=lowbit(i);
	}
}

void change(int u,int v,int val){
	int f1=top[u],f2=top[v];
	int tmp=0;
	while(f1!=f2){
		if(dep[f1]<dep[f2]){
			swap(f1,f2);
			swap(u,v);
		}
		add(p[f1],val);
		add(p[u]+1,-val);
		u=fa[f1]; f1=top[u];
	} 
	if(dep[u]>dep[v])
		swap(u,v);
	add(p[u],val);
	add(p[v]+1,-val);
}

int a[maxn];
int main(){
	int u,v,m,pp;
	while(scanf("%d%d%d",&n,&m,&pp)!=EOF){
		init();
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		while(m--){
			scanf("%d%d",&u,&v);
			addedge(u,v); addedge(v,u);
		}
		dfs1(1,0,0);
		dfs2(1,1);
		memset(c,0,sizeof c);
		for(int i=1; i<=n; i++){
			add(p[i],a[i]);
			add(p[i]+1,-a[i]);
		}
		char op[20];
		while(pp--){
			scanf("%s",op);
			if(op[0]=='Q'){
				scanf("%d",&u);
				printf("%d\n",Sum(p[u]));
			}
			else{
				int tmp1,tmp2,tmp3;
				scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
				if(op[0]=='D')
					tmp3=-tmp3;
				change(tmp1,tmp2,tmp3);
			}
		}
	}
	return 0;
}







//查询最大值 取反 改单边值 
struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
int size[maxn];//保存以x为根的子树节点个数
int dep[maxn]; //保存当前节点的深度
int fa[maxn];  //保存当前节点的父亲
int son[maxn]; //保存重儿子
int top[maxn]; //保存当前节点的所在链的顶端节点
int p[maxn];   //保存树中每个节点剖分后的新编号
int fp[maxn];  //fp和p数组相反
int pos;
void init(){
	tot=0; pos=1;
	memset(head,-1,sizeof head);
	memset(son,-1,sizeof son);
}
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
} 
//记录所有的重边 
void dfs1(int u,int father,int d){
	dep[u]=d;
	fa[u]=father;
	size[u]=1;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=father){
			dfs1(v,u,d+1);
			size[u]+=size[v];
			if(son[u]==-1||size[v]>size[son[u]])
				son[u]=v;
		}
	}
}
//连重边成重链
void dfs2(int u,int tp){
	top[u]=tp;
	p[u]=pos++;
	fp[p[u]]=u;
	if(son[u]==-1)
		return;
	dfs2(son[u],tp);
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u])
			dfs2(v,v);
	}
}

struct Node{
	int l,r;
	int mx;
	int mn;
	int lazy;
};
int n;
struct SegTree{
	Node st[maxn*3];
	void build(int i,int l,int r){
		st[i].l=l;
		st[i].r=r;
		st[i].mx=st[i].mn=st[i].lazy=0;
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build((i<<1)|1,mid+1,r);
		push_up(i);
	}
	//回溯更新父节点
	void push_up(int i){
		st[i].mx=max(st[i<<1].mx,st[(i<<1)|1].mx);
		st[i].mn=min(st[i<<1].mn,st[(i<<1)|1].mn);
	}
	void push_down(int i){
		if(st[i].l==st[i].r)
			return;
		if(st[i].lazy){
			st[i<<1].mx=-st[i<<1].mx;
			st[i<<1].mn=-st[i<<1].mn;
			swap(st[i<<1].mx,st[i<<1].mn);
			st[(i<<1)|1].mx=-st[(i<<1)|1].mx;
			st[(i<<1)|1].mn=-st[(i<<1)|1].mn;
			swap(st[(i<<1)|1].mx,st[(i<<1)|1].mn);
			st[i<<1].lazy^=1; st[(i<<1)|1].lazy^=1;
			st[i].lazy=0;
		}
	}
	void update(int i,int k,int val){
		if(st[i].l==k&&st[i].r==k){
			st[i].mx=st[i].mn=val;
			st[i].lazy=false;
			return ;
		}
		push_down(i);
		int mid=(st[i].l+st[i].r)>>1;
		if(k<=mid)
			update(i<<1,k,val);
		else
			update((i<<1)|1,k,val);
		push_up(i);
	}
	void update2(int i,int l,int r){
		if(st[i].l==l&&st[i].r==r){
			st[i].mx=-st[i].mx;
			st[i].mn=-st[i].mn;
			swap(st[i].mx,st[i].mn);
			st[i].lazy^=1;
			return;
		}
		push_down(i);
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			update2((i<<1),l,r);
		else if(l>mid)
			update2((i<<1)|1,l,r);
		else{
			update2((i<<1),l,mid);
			update2((i<<1)|1,mid+1,r);
		}
		push_up(i);
	}
	void ng_update(int u,int v){
		int f1=top[u],f2=top[v];
		int tmp=0;
		while(f1!=f2){
			if(dep[f1]<dep[f2]){
				swap(f1,f2);
				swap(u,v);
			}
			update2(1,p[f1],p[u]);
			u=fa[f1]; f1=top[u];
		}
		if(u==v)
			return;
		if(dep[u]>dep[v])
			swap(u,v);
		return update2(1,p[son[u]],p[v]);
	}
	int query(int i,int l,int r){
		if(st[i].l==l&&st[i].r==r)
			return st[i].mx;
		push_down(i);
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			return query(i<<1,l,r);
		else if(l>mid)
			return query((i<<1)|1,l,r);
		else
			return max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
		push_up(i);
	}
	int find(int u,int v){
		int f1=top[u],f2=top[v];
		int tmp=-inf;//!!!
		while(f1!=f2){
			if(dep[f1]<dep[f2]){
				swap(f1,f2);
				swap(u,v);
			}
			tmp=max(tmp,query(1,p[f1],p[u]));
			u=fa[f1]; f1=top[u];
		}
		if(u==v)
			return tmp;
		if(dep[u]>dep[v])
			swap(u,v);
		return max(tmp,query(1,p[son[u]],p[v]));
	}
}st;
int e[maxn][3];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=0; i<n-1; i++){
			scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
			addedge(e[i][0],e[i][1]);
			addedge(e[i][1],e[i][0]);
		}
		dfs1(1,0,0); dfs2(1,1);
		st.build(1,0,pos-1);
		for(int i=0; i<n-1; i++){
			if(dep[e[i][0]]>dep[e[i][1]])
				swap(e[i][0],e[i][1]);
			st.update(1,p[e[i][1]],e[i][2]);
		}
		char op[20];
		int u,v;
		while(scanf("%s",op)==1){
			if(op[0]=='D')
				break;
			scanf("%d%d",&u,&v);
			if(op[0]=='Q')
				printf("%d\n",st.find(u,v));
			else if(op[0]=='C')
				st.update(1,p[e[u-1][1]],v);
			else
				st.ng_update(u,v);
		}
	}
	return 0;
}


//HDU6074 
int n,m,w;
struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
int size[maxn];//保存以x为根的子树节点个数
int dep[maxn]; //保存当前节点的深度
int f[maxn];  //保存当前节点的父亲
int son[maxn]; //保存重儿子
int top[maxn]; //保存当前节点的所在链的顶端节点
int same[maxn],fa[maxn],cnt[maxn];
ll cost[maxn];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
	memset(son,-1,sizeof son);
}
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
} 
//记录所有的重边 
void dfs1(int u){
	size[u]=1;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=f[u]){
			f[v]=u; dep[v]=dep[u]+1;
			dfs1(v);
			size[u]+=size[v];
			if(son[u]==-1||size[v]>size[son[u]])
				son[u]=v;
		}
	}
}
//连重边成重链
void dfs2(int u,int tp){
	top[u]=tp;
	if(son[u]==-1)
		return;
	dfs2(son[u],tp);
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=f[u])
			dfs2(v,v);
	}
}
int lca(int x,int y){
	for(; top[x]!=top[y]; x=f[top[x]])
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int Same(int x){
    if(same[x]==x)
        return x;
    return same[x]=Same(same[x]);
}
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x = find(x); y = find(y);
	if(x==y)
		return;
	fa[x]=y;
	cnt[y]+=cnt[x];
	cost[y]+=cost[x]+w;
}
void go(int x,int y){
	while(true){
		x=Same(x);
		if(dep[x]<=dep[y])
			return;
		merge(x,f[x]);
		same[x]=f[x];
	}
}
void chain(int x,int y){
	int l = lca(x,y);
	go(x,l); go(y,l);
}
struct E{
	int a,b,c,d,w;
}e[maxn];
bool cmp(const E &a,const E &b){
	return a.w<b.w;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1; i<n; i++){
			int u,v; scanf("%d%d",&u,&v);
			addedge(u,v); addedge(v,u);
		}
		dfs1(1);dfs2(1,1);
		for(int i=1; i<=n; i++){
			same[i]=fa[i]=i;
			cnt[i]=1; cost[i]=0;
		}
		for(int i=1; i<=m; i++)
			scanf("%d%d%d%d%d",&e[i].a,&e[i].b,&e[i].c,&e[i].d,&e[i].w);
		sort(e+1,e+m+1,cmp);
		for(int i=1; i<=m; i++){
			w=e[i].w;
			chain(e[i].a,e[i].b);
			chain(e[i].c,e[i].d);
			merge(e[i].a,e[i].c);
		}
		printf("%d %lld\n",cnt[find(1)],cost[find(1)]);
	}
	return 0;
}
