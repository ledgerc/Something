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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


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
