//单点更新+- 查询区间和
int n;
int a[maxn];
struct Node{
	int l,r;
	int sum;
};
struct SegTree{
	Node st[maxn*3];
	void build(int i,int l,int r){
		st[i].l=l;
		st[i].r=r;
		if(l==r){
			st[i].sum=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build((i<<1)|1,mid+1,r);
		push_up(i);
	}
	void update(int i,int k,int add){
		st[i].sum+=add;
		if(st[i].l==st[i].r)
			return;
		int mid=(st[i].l+st[i].r)>>1;
		if(k<=mid)
			update(i<<1,k,add);
		else
			update((i<<1)|1,k,add);
	}
	int query(int i,int l,int r){
		if(st[i].l==l&&st[i].r==r)
			return st[i].sum;
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			return query(i<<1,l,r);
		else if(l>mid)
			return query((i<<1)|1,l,r);
		else
			return query(i<<1,l,mid)+query((i<<1)|1,mid+1,r);
	}
	//回溯更新父节点
	void push_up(int i){
		st[i].sum=st[i<<1].sum+st[i<<1|1].sum;
	}
}st;

//区间更新为同一值 求和 
struct Node{
	int l,r;
	int sum;
	int lazy,tag;
};
int n;
ll a[maxn];
struct SegTree{
	Node st[maxn*3];
	void build(int i,int l,int r){
		st[i].l=l;
		st[i].r=r;
		st[i].lazy=st[i].tag=0;
		if(l==r){
			st[i].sum=1;
			return ;
		}
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build((i<<1)|1,mid+1,r);
		push_up(i);
	}
	void update(int i,int l,int r,int val){
		if(st[i].l==l&&st[i].r==r){
			st[i].lazy=1;
			st[i].tag=val;
			st[i].sum=(r-l+1)*val;
			return ;
		}
		int mid=(st[i].l+st[i].r)>>1;
		if(st[i].lazy==1){
			st[i].lazy=0;
			update(i<<1,st[i].l,mid,st[i].tag);
			update((i<<1)|1,mid+1,st[i].r,st[i].tag);
			st[i].tag=0;
		}
		if(r<=mid)
			update(i<<1,l,r,val);
		else if(l>mid)
			update((i<<1)|1,l,r,val);
		else
			update(i<<1,l,mid,val),update((i<<1)|1,mid+1,r,val);
		push_up(i);
	}
	//回溯更新父节点
	void push_up(int i){
		st[i].sum=st[i<<1].sum+st[i<<1|1].sum;
	}
}st;



struct Node{
	int l,r;
	ll val;
	int tn;
};
int n;
ll a[maxn];
struct SegTree{
	Node st[maxn*3];
	void build(int i,int l,int r){
		st[i].l=l;
		st[i].r=r;
		st[i].val=0;
		st[i].tn=0;
		if(l==r){
			st[i].val=a[l];
			if(st[i].val==1||st[i].val==0)
				st[i].tn=1;
			return ;
		}
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build((i<<1)|1,mid+1,r);
		push_up(i);
	}
	void update(int i,int l,int r){
		if(st[i].tn==1)
			return ;
		if(st[i].l==st[i].r){
			st[i].val=sqrt(st[i].val);
			if(st[i].val==1||st[i].val==0)
				st[i].tn=1;
			return ;
		}
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			update(i<<1,l,r);
		else if(l>mid)
			update((i<<1)|1,l,r);
		else
			update(i<<1,l,mid),update((i<<1)|1,mid+1,r);
		push_up(i);
	}
	ll query(int i,int l,int r){
		if(st[i].l==l&&st[i].r==r)
			return st[i].val;
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			return query(i<<1,l,r);
		else if(l>mid)
			return query((i<<1)|1,l,r);
		else
			return query(i<<1,l,mid)+query((i<<1)|1,mid+1,r);
	}
	//回溯更新父节点
	void push_up(int i){
		st[i].val=st[i<<1].val+st[(i<<1)|1].val;
		st[i].tn=st[i<<1].tn & st[(i<<1)|1].tn;
	}
}st;
int main(){
	int kase=0;
	while(scanf("%d",&n)!=EOF){
		kase++;
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		st.build(1,1,n);
		printf("Case #%d:\n",kase);
		int q; sc(q);
		while(q--){
			ll l,r,x;
			scanf("%lld%lld%lld",&x,&l,&r);
			if(l>r)
				swap(l,r);
			if(r>n)
				r=n;
			if(l<1)
				l=1;
			if(x==0)
				st.update(1,l,r);
			else
				printf("%lld\n",st.query(1,l,r));
		}
		cout<<endl;
	}
	return 0;
}


struct Node{
	int l,r;
	ll val;
	ll lazy;
};
int n;
ll a[maxn];
struct SegTree{
	Node st[maxn*3];
	void build(int i,int l,int r){
		st[i].l=l;
		st[i].r=r;
		st[i].val=0;
		if(l==r){
			st[i].val=a[l];
			st[i].lazy=st[i].val;
			return ;
		}
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build((i<<1)|1,mid+1,r);
		push_up(i);
	}
	void update(int i,int l,int r,ll val){
		if((st[i].lazy&val)==st[i].lazy)
			return;
		if(st[i].l==st[i].r){
			st[i].lazy&=val;
			st[i].val&=val;
			return ;
		}
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			update(i<<1,l,r,val);
		else if(l>mid)
			update((i<<1)|1,l,r,val);
		else
			update(i<<1,l,mid,val),update((i<<1)|1,mid+1,r,val);
		push_up(i);
	}
	ll query(int i,int l,int r){
		if(st[i].l==l&&st[i].r==r)
			return st[i].val;
		int mid=(st[i].l+st[i].r)>>1;
		if(r<=mid)
			return query(i<<1,l,r);
		else if(l>mid)
			return query((i<<1)|1,l,r);
		else
			return min(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
	}
	//回溯更新父节点
	void push_up(int i){
		st[i].val=min(st[i<<1].val,st[(i<<1)|1].val);
		st[i].lazy=st[i<<1].lazy|st[(i<<1)|1].lazy;
	}
}st;
int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		st.build(1,1,n);
		while(q--){
			int t,l,r; ll x;
			scanf("%d%d%d",&t,&l,&r);
			if(t==0)
				cout<<st.query(1,l,r)<<endl;
			else{
				scanf("%lld",&x);
				st.update(1,l,r,x);
			}
		}
	}
	return 0;
}
