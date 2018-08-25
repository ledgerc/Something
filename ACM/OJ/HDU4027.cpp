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
const int maxn = 5000100;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Node{
	int l,r;
	ll sum;
}segTree[maxn*3];
void Build(int i,int l,int r){
	segTree[i].l=l;
	segTree[i].r=r;
	if(l==r){
		scanf("%lld",&segTree[i].sum);
		return ;
	}
	int mid=((l+r)>>1);
	Build(i<<1,l,mid);
	Build((i<<1)|1,mid+1,r);
	segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
void Query(int i,int l,int r){
	if(segTree[i].l==l&&segTree[i].r==r&&segTree[i].sum==r-l+1)
		return;
	if(segTree[i].l==segTree[i].r){
        segTree[i].sum=sqrt(segTree[i].sum*1.0);
        return;
    }
    int mid=((segTree[i].l+segTree[i].r)>>1);
    if(r<=mid)
		Query(i<<1,l,r);
    else if(l>mid)
		Query((i<<1)|1,l,r);
    else{
        Query(i<<1,l,mid);
        Query((i<<1)|1,mid+1,r);
    }
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
ll Sum(int i,int l,int r){
	if(segTree[i].l==l&&segTree[i].r==r)
		return segTree[i].sum;
	int mid=((segTree[i].l+segTree[i].r)/2);
	ll ans=0;
	if(r<=mid)
		ans=Sum(i<<1,l,r);
    else if(l>mid)
		ans=Sum((i<<1)|1,l,r);
    else
        ans=Sum(i<<1,l,mid)+Sum((i<<1)|1,mid+1,r);
    return ans;
}
int main(){
	int n,m,kase=1;
	int T,x,y;
	while(scanf("%d",&n)!=EOF){
		Build(1,1,n);
		scanf("%d",&m);
		printf("Case #%d:\n",kase++);
		while(m--){
			scanf("%d%d%d",&T,&x,&y);
			if(x>y)
				swap(x,y);
			if(T==0)
				Query(1,x,y);
			else
				printf("%lld\n",Sum(1,x,y));
		}
		printf("\n");
	}
	return 0;
}
