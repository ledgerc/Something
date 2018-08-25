#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
map<int,int> mp;
/*
数组下标从1到n，询问[l,r]最小值
*/
int a[maxn];
int b[maxn];
int dp2[maxn][32];
void ini(int n){
    for(int i=1;i<=n;i++)dp2[i][0]=a[i];
    for(int j=1;j<30;j++){
        for(int i=n;i>=1;i--){
            if(i+(1<<j-1)<=n)
            dp2[i][j]=max(dp2[i][j-1],dp2[i+(1<<j-1)][j-1]);
        }
    }
}
int rmq2(int l,int r){
    int k=0;
    while(1<<k+1<=r-l+1)k++;
    return max(dp2[l][k],dp2[r-(1<<k)+1][k]);
}
int sol(int l,int r){
    if(l>r)return -1;
    return rmq2(l,r);
}

int main()
{
    int n,m;
    while(~scanf("%d",&n)){
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            mp[b[i]]=i;
            scanf("%d",&a[i]);
        }
        ini(n);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            if(l==r){puts("true");continue;}
            int tl=l,tr=r;
            int len=r-l+1;
            l=mp[l];
            r=mp[r];
            if(l==0&&r==0){
                puts("maybe");
            }
            else if(l==0){
                l=lower_bound(b+1,b+1+n,tl)-(b+1)+1;
                if(sol(l,r-1)>=a[r])puts("false");
                else puts("maybe");
            }
            else if(r==0){
                r=lower_bound(b+1,b+1+n,tr)-(b+1)+1;
                if(sol(l+1,r-1)>=a[l])puts("false");
                else puts("maybe");
            }
            else if(a[r]>a[l]){
                puts("false");
            }
            else if(sol(l+1,r-1)>=a[r])puts("false");
            else if(r-l+1!=len)puts("maybe");
            else puts("true");
        }
    }
    return 0;
}
