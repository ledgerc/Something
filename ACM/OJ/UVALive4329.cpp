#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <map>  
#include <queue>  
#include <stack>  
using namespace std;  
  
#define lowbit(x) (x&(-x))  
#define LL long long  
const int maxn=1e5+10;  
int c[maxn];  
int a[maxn],f[2][maxn];  
void add(int x,int val)//b[x]+=val  
{  
    while(x<maxn)  
    {  
        c[x]+=val;  
        x+=lowbit(x);  
    }  
}  
int sum(int x)//b[1]+b[2]+...b[x]  
{  
    int ans=0;  
    while(x>0)  
    {  
        ans+=c[x];  
        x-=lowbit(x);  
    }  
    return ans;  
}  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        int i,j,k,n;  
        scanf("%d",&n);  
        for(i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        memset(c,0,sizeof(c));  
        for(i=0;i<n;i++)  
        {  
            f[0][i]=sum(a[i]);  
            add(a[i],1);   
        }  
        memset(c,0,sizeof(c));  
        for(i=n-1;i>=0;i--)  
        {  
            f[1][i]=sum(a[i]);  
            add(a[i],1);  
        }  
        LL ans=0;  
        for(i=0;i<n;i++)  
        {  
            ans+=(LL)f[0][i]*(n-i-1-f[1][i]);  
            ans+=(LL)(i-f[0][i])*f[1][i];  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
} 
