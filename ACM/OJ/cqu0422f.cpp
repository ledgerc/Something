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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

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
