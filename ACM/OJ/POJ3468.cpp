/*
POJ 3468 A Simple Problem with Integers
��Ŀ��˼��
����Q������A1,A2,```,AQ,�Լ����ܶ�ν�����������������
1����ĳ������Ai```Aj��������n��n�ɱ䣩
2����ĳ������Ai```Aj��� 
*/
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=100000;
int num[MAXN];
struct Node
{
    int l,r;//��������Ҷ˵�
long long nSum;//�����ϵĺ�
long long Inc;//�����������ۼ� 
}segTree[MAXN*3];
void Build(int i,int l,int r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].Inc=0;
    if(l==r)
    {
        segTree[i].nSum=num[l];
        return;
    }    
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
    segTree[i].nSum=segTree[i<<1].nSum+segTree[i<<1|1].nSum;
} 
void Add(int i,int a,int b,long long c)//�ڽ��i�����䣨a,b��������c
{
    if(segTree[i].l==a&&segTree[i].r==b)
    {
        segTree[i].Inc+=c;
        return;
    }
    segTree[i].nSum+=c*(b-a+1);
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(b<=mid)  Add(i<<1,a,b,c);
    else if(a>mid)  Add(i<<1|1,a,b,c);
    else
    {
        Add(i<<1,a,mid,c);
        Add(i<<1|1,mid+1,b,c);
    }        
}  
long long Query(int i,int a,int b)//��ѯa-b���ܺ�
{
    if(segTree[i].l==a&&segTree[i].r==b)
    {
        return segTree[i].nSum+(b-a+1)*segTree[i].Inc;
    }  
    segTree[i].nSum+=(segTree[i].r-segTree[i].l+1)*segTree[i].Inc;
    int mid=(segTree[i].l+segTree[i].r)>>1;
    Add(i<<1,segTree[i].l,mid,segTree[i].Inc);
    Add(i<<1|1,mid+1,segTree[i].r,segTree[i].Inc);
    segTree[i].Inc=0;
    if(b<=mid)  return Query(i<<1,a,b);
    else if(a>mid)  return Query(i<<1|1,a,b);
    else return Query(i<<1,a,mid)+Query(i<<1|1,mid+1,b);
}  
int main()
{
    int n,q;
    int i;
    int a,b,c;
    char ch;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(i=1;i<=n;i++)  scanf("%d",&num[i]);
        Build(1,1,n);
        for(i=1;i<=q;i++)
        {
            cin>>ch;
            if(ch=='C')
            {
                scanf("%d%d%d",&a,&b,&c);
                Add(1,a,b,c);
            }    
            else
            {
                scanf("%d%d",&a,&b);
                printf("%I64d\n",Query(1,a,b));
            }    
        }    
    } 
    return 0;   
}
