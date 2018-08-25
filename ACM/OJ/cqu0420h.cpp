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
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

ll n,k;
ll a[maxn],b[maxn];
int id[maxn],cnt[maxn];
ll check(ll mid){
	memset(cnt,0,sizeof cnt);
	int l=0;
	ll cur=0,res=0;
	for(int i=0; i<n; i++){
		cur+=cnt[ id[i] ]++;
		while(cur>mid)
			cur-= -- cnt[ id[ l++ ] ];
		res+=i-l+1;
	}
	return res;
}
int main(){
	int T; sc(T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=0; i<n; i++){
			scanf("%lld",&a[i]); b[i]=a[i];
		}
		sort(b,b+n);
		int m=unique(b,b+n)-b;
		for(int i=0; i<n; i++)
			id[i]=lower_bound(b,b+m,a[i])-b;
		
		ll l=-1,r=n*1LL*(n-1)/2;
		while(l<r){
			ll mid=(l+r)>>1;
			if(check(mid)<k)
				l=mid+1;
			else
				r=mid;
		}
		cout<<r<<endl;
	}
}
