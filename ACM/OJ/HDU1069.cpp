#include<algorithm>  
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;  
struct node{  
    int a,b,c;  
}s[1000];     
bool cmp(node x,node y)   //�Ӵ�С����  
{  
    return x.a!=y.a ? x.a>y.a : x.b<y.b ;  
}  
int main()  
{  
    int T=0,ans,n,m,ta,tb,tc,i,j,min,dp[1000];  
    while(scanf("%d",&n)&&n)  
    {  
        m=0;  
        for(i=0;i<n;i++)  
        {  
            scanf("%d %d %d",&ta,&tb,&tc);  
            s[m].a=s[m+1].b=s[m+2].c=s[m+3].a=s[m+4].b=s[m+5].c=ta;   //ÿһ��a,b,c������6�����  
            s[m+1].a=s[m+2].b=s[m+3].c=s[m+4].c=s[m+5].a=s[m].b=tb;  
            s[m+2].a=s[m+3].b=s[m+4].a=s[m+5].b=s[m].c=s[m+1].c=tc;  
            m+=6;  
        }  
        sort(s,s+m,cmp);  
        memset(dp,0,sizeof(dp));  
        ans=0;  
        for(i=0;i<m;i++)    //�����ϵ�ǰ�ĳ�������Դﵽ�����߶�  
        {  
            min=0;  
            for(j=0;j<i;j++)    //��ǰ�ĳ�������Լӵ�֮ǰ�ĳ�������   
            {  
                if(s[i].b<s[j].b && min<dp[j])  
                {  
                    min=dp[j];  
                }  
            }  
            dp[i]=min+s[i].c;  
            if(ans<dp[i])  
            {  
                ans=dp[i];  
            }  
        }  
        printf("Case %d: maximum height = %d\n",++T,ans);  
    }  
    return 0;  
}
