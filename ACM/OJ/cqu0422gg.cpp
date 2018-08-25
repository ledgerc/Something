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
const ll mod = 1e9+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e7+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int a[maxn];
ll b[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		for(int i=n-1; i>0; i--)
			a[i]-=a[i-1];
		int minn=inf;
		for(int i=1; i<n; i++)
			minn=min(minn,a[i]);
		minn--;
		for(int i=1; i<n; i++)
			a[i]-=minn;
		for(int i=1; i<n; i++)
			b[a[i]]=0;
		ll sum=1;
		a[0]=0; b[0]=1;
		for(int i=1; i<n; i++){
			ll tmp=b[a[i]];
			b[a[i]]=sum;
			sum+=b[a[i]]-tmp;
			sum%=mod;
			if(sum<0)
				sum+=mod;
		}
		sum--;
		if(sum<0)
			sum+=mod;
		printf("%lld\n",sum);
	}
	return 0;
}
