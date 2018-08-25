#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int N=2e3+20;
int ans,n,x[N],y[N],a,b;
void check(int i,int a,int b)
{
	int res=x[i]*y[i];
	for(int j=1;j<=n;j++)
	{
		if(i==j)	continue;
		if(x[j]<=a&&y[j]<=b)
			ans=max(ans,res+x[j]*y[j]);
		if(x[j]<=b&&y[j]<=a)
			ans=max(ans,res+x[j]*y[j]);
	}
}
int main()
{
	while(cin>>n>>a>>b)
	{
		for(int i=1;i<=n;i++)
			cin>>x[i]>>y[i];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]<=a&&y[i]<=b)
			{
				check(i,a-x[i],b);
				check(i,a,b-y[i]);
			}
			if(x[i]<=b&&y[i]<=a)
			{
				check(i,a-y[i],b);
				check(i,a,b-x[i]);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
