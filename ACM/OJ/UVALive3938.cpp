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

const int MAXN = 2e5+7;
int sum;
struct Node{
    int l,r;
    int Sum;
}segTree[MAXN*3];
int a[MAXN];
void Build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        segTree[i].Sum=a[l];
        return;
    } 
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
    segTree[i].Sum=segTree[i<<1].Sum+segTree[i<<1|1].Sum;  
}
void Query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r){
        sum+=segTree[i].Sum;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid)
		Query(i<<1,l,r);
    else if(l>mid)
		Query(i<<1|1,l,r);
    else{
        Query(i<<1,l,mid);
        Query(i<<1|1,mid+1,r);
    }      
}
int main(){
    int n,m,kase=1;
	while(scanf("%d%d",&n,&m)!=EOF){
    	for(int i=1; i<=n; i++)
    		cin>>a[i];
    	Build(1,1,n);
    	int l,r;
    	for(int i=0; i<m; i++){
    		scanf("%d%d",&l,&r);
    		int sum=0;
    		Query(1,l,r);
		}
	} 
} 
