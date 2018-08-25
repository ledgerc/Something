#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int MAXN = 8010;
struct Node{
	int l,r;
	int color;
}segTree[MAXN*3];
int color[MAXN];
int temp;
void Build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].color=-1;//-1��ʾû����ɫ 
    if(l+1==r)
		return;
    int mid=((l+r)>>1);
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid,r);
}
void insert(int i,int l,int r,int c)
{
    if(l==r)return;
    if(segTree[i].color==c)return;
    if(l<=segTree[i].l&&r>=segTree[i].r)
    {
        segTree[i].color=c;
        return;
    }
    if(segTree[i].color>=0)//������ɫ�����¸��� 
    {
        segTree[i<<1].color=segTree[i].color;
        segTree[(i<<1)|1].color=segTree[i].color;
        segTree[i].color=-2;//��ʾ�ж�����ɫ 
    }
    int mid=((segTree[i].l+segTree[i].r)>>1);
    if(r<=mid) insert(i<<1,l,r,c);
    else if(l>=mid) insert((i<<1)|1,l,r,c);
    else
    {
        insert(i<<1,l,mid,c);
        insert((i<<1)|1,mid,r,c);
    }
    segTree[i].color=-2;
}
void Count(int i)//ͳ����ɫ�Ķ��� 
{
    if(segTree[i].color==-1)
    {
        temp=-1;
        return;
    }
    if(segTree[i].color!=-2)
    {
        if(segTree[i].color!=temp)//temp�����ǰһ�ε���ɫ 
        {
            color[segTree[i].color]++;
            temp=segTree[i].color;
        }
        return;
    }
    if(segTree[i].l+1!=segTree[i].r)
    {
        Count(i<<1);
        Count((i<<1)|1);
    }
}
int main()
{
    int n,a,b,c;
    int Max;
    while(scanf("%d",&n)!=EOF)
    {
        Build(1,0,8000);
        Max=0;
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&c);
            insert(1,a,b,c);
            if(c>Max)Max=c;
        }
        temp=-1;
        memset(color,0,sizeof(color));
        Count(1);
        for(int i=0;i<=Max;i++)
        {
            if(color[i])printf("%d %d\n",i,color[i]);
        }
        printf("\n");
    }
    return 0;
}
