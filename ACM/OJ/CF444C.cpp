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
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int MAXN = 100100;
int n,m;
struct Node{
    int l,r,mark;
    ll sum,col;
}segTree[MAXN*4];
void Build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        segTree[i].mark=l;
        return;
    } 
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i*2+1,mid+1,r);
}
void clear(int i,int x){
	if(segTree[i].mark){
		segTree[i].col+=abs(segTree[i].mark-x);
		segTree[i].sum+=((ll)segTree[i].r-segTree[i].l+1)*(ll)abs(segTree[i].mark-x);
		segTree[i].mark=x;
	}
	else{
		if(segTree[i].l==segTree[i].r)
			return ;
		clear(i<<1,x);
		clear(i*2+1,x);
		segTree[i].sum=segTree[i<<1].sum+segTree[i*2+1].sum+((ll)segTree[i].r-segTree[i].l+1)*segTree[i].col;
	}
}
void update(int i,int l,int r,ll x){
	if(segTree[i].l>=l&&segTree[i].r<=r){
		clear(i,x);
		segTree[i].mark=x;
		return ;
	}
	int mid=(segTree[i].l+segTree[i].r)>>1;
	if(segTree[i].mark){
		segTree[i<<1].mark=segTree[i*2+1].mark=segTree[i].mark;
		segTree[i].mark=0;
	}
	if(l<=mid)
		update(i<<1,l,r,x);
	if(r>mid)
		update(i*2+1,l,r,x);
	segTree[i].sum=segTree[i<<1].sum+segTree[i*2+1].sum+((ll)segTree[i].r-segTree[i].l+1)*(ll)segTree[i].col;
}
ll sum(int i,int ql,int qr){
    if(segTree[i].l>=ql&&segTree[i].r<=qr)
        return segTree[i].sum;
    
    int mid=(segTree[i].l+segTree[i].r)>>1;
    ll l=0,r=0;
   	if(ql<=mid)
		l=sum(i<<1,ql,qr);
    if(qr>mid)
		r=sum(i*2+1,ql,qr);
	return l+r+max(0,min(segTree[i].r,qr)-max(segTree[i].l,ql)+1)*(long long)segTree[i].col;
}
int main(){
	scanf("%d%d",&n,&m);
	Build(1,1,n);
	while(m--){
		int op,l,r,color;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&l,&r,&color);
			update(1,l,r,color);
		}
		else if(op==2){
			scanf("%d%d",&l,&r);
			ll tmp=sum(1,l,r);
			printf("%lld\n",tmp);
		}
	}
	return 0;
} 
