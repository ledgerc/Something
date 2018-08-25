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

const int MAXN = 50010;
int Sum;
struct Node{
    int l,r;
    int sum;
}segTree[MAXN*3];
int a[MAXN];
void add(int i,int t,ll s){
	segTree[i].sum+=s;
	if(segTree[i].l==segTree[i].r)
		return;
	int mid=((segTree[i].l+segTree[i].r)>>1);
    if(t<=mid)
		add(i<<1,t,s);
    else
		add((i<<1)|1,t,s);
}
void Build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        segTree[i].sum=a[l];
        return;
    } 
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
    segTree[i].sum=segTree[i<<1].sum+segTree[i<<1|1].sum;  
}
ll Query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r)
        return segTree[i].sum;;
    int mid=(segTree[i].l+segTree[i].r)>>1;
    ll ans=0;
    if(r<=mid)
		ans=Query(i<<1,l,r);
    else if(l>mid)
		ans=Query(i<<1|1,l,r);
    else
        ans=Query(i<<1,l,mid)+Query(i<<1|1,mid+1,r);
    return ans;
}
int main(){
	int T; scanf("%d",&T);
	int n,x,y; char str[20];
	for(int kase=1; kase<=T; kase++){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)	
			scanf("%d",&a[i]);
		Build(1,1,n);
		printf("Case %d:\n",kase);
		while(scanf("%s",str)){
			if(strcmp(str,"End")==0)
				break;
			scanf("%d%d",&x,&y);
			if(strcmp(str,"Add")==0)
				add(1,x,y);
            else if(strcmp(str,"Sub")==0)
				add(1,x,-y);
            else
            	printf("%d\n",Query(1,x,y));
		}
	}
} 
