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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

long long dp[maxn];  
int a[maxn];  
int mark[maxn];
int main()  
{  
    int n,i,j;  
    while(scanf("%d",&n)!=EOF)  
    {  
    	int b[maxn];
    	for(int i=1; i<=n; i++)
    		scanf("%d",&b[i]);
    	for(int i=1; i<=n-1; i++)
    		a[i]=b[i+1]-b[i];
    	n--;
        memset(dp,0,sizeof(dp));  
        memset(mark,0,sizeof(mark));  
        dp[0]=1;  
        for(i=1;i<=n;++i)  
        {  
            if(mark[a[i]]==0)  
                dp[i]=(dp[i-1]*2)%mod;  
            else  
                dp[i]=(2*dp[i-1]-dp[mark[a[i]]-1]+mod)%mod;  
            mark[a[i]]=i;  
        }  
        for(int i=1; i<=n; i++)
        	cout<<a[i]<<" ";
        cout<<endl;
    	for(int i=1; i<=n; i++)
    		cout<<dp[i]<<" ";
    	cout<<endl;
    //    printf("%lld\n",dp[n]-1);  
    }  
    return 0;   
} 
