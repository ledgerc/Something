#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5+7;
int h,w,n;
int ans;
struct Node{
	int l,r;
	int n;
}segTree[maxn*5];
void Build(int i,int l,int r){
	segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].n=w;
    if(l!=r){
    	int mid=(l+r)>>1;
    	Build(i<<1,l,mid);
    	Build(i<<1|1,mid+1,r);
	}
}
void insert(int i,int x){
	if(segTree[i].l==segTree[i].r){
		segTree[i].n-=x;
		ans=segTree[i].l;
		return ;
	}
	if(x<=segTree[2*i].n)
		insert(2*i,x);
	else
		insert(2*i+1,x);
	segTree[i].n=max(segTree[2*i].n,segTree[2*i+1].n);
}
int main(){
	while(~scanf("%d%d%d",&h,&w,&n)){
		if(h>n)
			h=n;
		Build(1,1,h);
		ans=-1;
		for(int i=0; i<n; i++){
			int tmp;
			scanf("%d",&tmp);
			if(segTree[1].n>=tmp)
				insert(1,tmp);
			printf("%d\n",ans);
			ans=-1;
		}
	}
	
	return 0;
}
