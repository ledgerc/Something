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

const int MAXN = 600010;
int Sum;
struct Node{
    int l,r;
    int nMax;
}segTree[MAXN*3];
int a[MAXN];
void Build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        segTree[i].nMax=a[l];
        return;
    } 
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
    segTree[i].nMax=max(segTree[i<<1].nMax,segTree[i<<1|1].nMax);
}
void change(int i,int t,int s){
	if(segTree[i].l==t&&segTree[i].r==t){
		segTree[i].nMax=s;
		return;
	}
	int mid=((segTree[i].l+segTree[i].r)>>1);
    if(t<=mid)
		change(i<<1,t,s);
    else
		change((i<<1)|1,t,s);
	segTree[i].nMax=max(segTree[i<<1].nMax,segTree[i<<1|1].nMax);
}
int Query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r)
        return segTree[i].nMax;
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid)
		return Query(i<<1,l,r);
    else if(l>mid)
		return Query(i<<1|1,l,r);
	else 
		return max(Query(i<<1,l,mid),Query(i<<1|1,mid+1,r));
}
int main(){
	int n,m,x,y; char c[2];
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1; i<=n; i++)	
			scanf("%d",&a[i]);
		Build(1,1,n);
		for(int i=0; i<m; i++){
			scanf("%s%d%d",c,&x,&y);
			if(c[0]=='U'){
				change(1,x,y);
			}
			else if(c[0]=='Q'){
				printf("%d\n",Query(1,x,y));
			}
			
		}
	}
	return 0;
}
