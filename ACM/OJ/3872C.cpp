#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
using namespace std;
const int maxn=100005;
struct node
{
    int t;
    int k;
    int d;
}Q[maxn];
int num[105];
int main()
{
    int N,q;
    scanf("%d%d",&N,&q);
    memset(num,0,sizeof(num));
    for(int i=0;i<q;i++)
        scanf("%d%d%d",&Q[i].t,&Q[i].k,&Q[i].d);
    for(int i=0;i<q;i++)
    {
        int flag_num=0;
        for(int j=1;j<=N&&flag_num<Q[i].k;j++)
            if(num[j]<Q[i].t)
                flag_num++;
        if(flag_num==Q[i].k)
        {
            long long int result=0;
            for(int j=1;j<=N&&flag_num>0;j++)
            {
                if(num[j]<Q[i].t)
                {
                    num[j]=Q[i].t+Q[i].d-1;
                    flag_num--;
                    result+=j;
                }
            }
            printf("%I64d\n",result);
        }
        else
            printf("-1\n");
    }
    return 0;
}
