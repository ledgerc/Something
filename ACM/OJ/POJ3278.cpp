#include<stdio.h>
#include<string.h>
#define mem(a) memset(a,0,sizeof(a))
int vis[200005],q[200005],d[200005];
int n,k;
void bfs(int x)
{
    mem(vis);mem(q);mem(d);
    vis[x]=1;
    int front=0,rear=0;//frontָ������ף�rearָ�����β��
    q[rear++]=x;//β������һ��
    while(front<rear)
    {
        x=q[front++];//ȡ�������׵�Ԫ��
        if(x==k)return ;//����ҵ��˾ͷ���
        if(!vis[x-1]&&x>0){vis[x-1]=1;q[rear++]=x-1;d[x-1]=d[x]+1;}//���x-1û���߹�������ڶ��е�β��
        if(!vis[x+1]&&x<100000){vis[x+1]=1;q[rear++]=x+1;d[x+1]=d[x]+1;}//����������x+1
        if(!vis[x*2]&&x<=50000){vis[x*2]=1;q[rear++]=2*x;d[x*2]=d[x]+1;}//һ��x*2
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        bfs(n);
        printf("%d\n",d[k]);
    }
    return 0;
}
