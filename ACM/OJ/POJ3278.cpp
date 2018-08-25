#include<stdio.h>
#include<string.h>
#define mem(a) memset(a,0,sizeof(a))
int vis[200005],q[200005],d[200005];
int n,k;
void bfs(int x)
{
    mem(vis);mem(q);mem(d);
    vis[x]=1;
    int front=0,rear=0;//front指向队列首，rear指向队列尾部
    q[rear++]=x;//尾部加入一个
    while(front<rear)
    {
        x=q[front++];//取出队列首的元素
        if(x==k)return ;//如果找到了就返回
        if(!vis[x-1]&&x>0){vis[x-1]=1;q[rear++]=x-1;d[x-1]=d[x]+1;}//如果x-1没有走过，则加在队列的尾部
        if(!vis[x+1]&&x<100000){vis[x+1]=1;q[rear++]=x+1;d[x+1]=d[x]+1;}//与上面相似x+1
        if(!vis[x*2]&&x<=50000){vis[x*2]=1;q[rear++]=2*x;d[x*2]=d[x]+1;}//一样x*2
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
