#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll __int64 
struct node
{
    int a,b;
}seg[200005];
int f[100005];
int num[100005];
bool cmp(node a,node b)
{
    if(a.b==b.b)
        return a.a<b.a;
    return a.b<b.b;
}
int main()
{
    int t,n,m,i,j,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;++i)
        {
            f[i]=1;
            num[i]=0;
        }
        for(i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            ++num[a];
            ++num[b];
            if(a<b)
            {
                seg[i].a=a;
                seg[i].b=b;
            }
            else 
            {
                seg[i].a=b;
                seg[i].b=a;
            }
        }
        sort(seg,seg+m,cmp);
        ll ans=-1;
        for(i=0;i<m;++i)
        {
            f[seg[i].b]=max(f[seg[i].b],f[seg[i].a]+1);
            ans=max(ans,(ll)f[seg[i].b]*num[seg[i].b]);         
        }
        for(i=0;i<n;i++)
        {
            ans=max(ans,(ll)num[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
