#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=100010;
struct Node{
    int l,r;
    int lazy,tag;
    int sum;
}segTree[MAXN*3];
void Build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].lazy=0;
    segTree[i].tag=0;
    if(l==r){
        segTree[i].sum=1;
        return;
    }
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid+1,r);
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
void update(int i,int l,int r,int v){
    if(segTree[i].l==l&&segTree[i].r==r){//³É¶Î¸üÐÂ
        segTree[i].lazy=1;
        segTree[i].tag=v;
        segTree[i].sum=(r-l+1)*v;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(segTree[i].lazy==1){
        segTree[i].lazy=0;
        update(i<<1,segTree[i].l,mid,segTree[i].tag);
        update((i<<1)|1,mid+1,segTree[i].r,segTree[i].tag);
        segTree[i].tag=0;
    }
    if(r<=mid)
		update(i<<1,l,r,v);
    else if(l>mid)
		update((i<<1)|1,l,r,v);
    else{
        update(i<<1,l,mid,v);
        update((i<<1)|1,mid+1,r,v);
    }
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
int main(){
    int x,y,z;
    int n;
    int m;
    int T;
    scanf("%d",&T);
    int iCase=0;
    while(T--){
        iCase++;
        scanf("%d%d",&n,&m);
        Build(1,1,n);
        while(m--){
            scanf("%d%d%d",&x,&y,&z);
            update(1,x,y,z);
        }
        printf("Case %d: The total value of the hook is %d.\n",iCase,segTree[1].sum);
    }
    return 0;
}
