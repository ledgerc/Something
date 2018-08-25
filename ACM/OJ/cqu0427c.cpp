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

int main(){
	int T; cin>>T;
	while(T--){
		ll a[maxn];
		memset(a,0,sizeof a);
		ll n,k; cin>>n>>k;
		int tmp=n/k; tmp*=k;
		for(ll i=0; i<k; i++)
			a[i]+=n/k;
		for(ll i=tmp+1; i<=n; i++)
			a[i%k]++;
		
		ll sum=0;
		sum+=a[0]*(a[0]-1)/2;
		if(k%2==0){
			sum+=a[k/2]*(a[k/2]-1)/2;
		}
		if(k%2==0){
			for(ll i=1; i<k/2; i++)
				sum+=a[i]*a[k-i];
		}
		else{
			for(ll i=1; i<=k/2; i++)
				sum+=a[i]*a[k-i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
