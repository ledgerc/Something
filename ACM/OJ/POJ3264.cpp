#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAXN 200005
#define INF 10000000
int nMax,nMin;//记录最大最小值 
struct Node
{
    int l,r;//区间的左右端点 
    int nMin,nMax;//区间的最小值和最大值 
}segTree[MAXN*3];
int a[MAXN];
void Build(int i,int l,int r)//在结点i上建立区间为(l,r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r)//叶子结点 
    {
        segTree[i].nMin=segTree[i].nMax=a[l];
        return;
    } 
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
    segTree[i].nMin=min(segTree[i<<1].nMin,segTree[i<<1|1].nMin);
    segTree[i].nMax=max(segTree[i<<1].nMax,segTree[i<<1|1].nMax);   
}
void Query(int i,int l,int r)//查询结点i上l-r的最大值和最小值
{
    if(segTree[i].nMax<=nMax&&segTree[i].nMin>=nMin)  return;
    if(segTree[i].l==l&&segTree[i].r==r)
    {
        nMax=max(segTree[i].nMax,nMax);
        nMin=min(segTree[i].nMin,nMin);
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid)   Query(i<<1,l,r);
    else if(l>mid)  Query(i<<1|1,l,r);
    else
    {
        Query(i<<1,l,mid);
        Query(i<<1|1,mid+1,r);
    }      
}
int main()
{
    int n,q;
    int l,r;
    int i;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(i=1;i<=n;i++)
          scanf("%d",&a[i]);
        Build(1,1,n);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&l,&r);
            nMax=-INF;nMin=INF;
            Query(1,l,r);
            printf("%d\n",nMax-nMin);
        }    
    }  
    return 0;  
}
