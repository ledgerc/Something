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

ll last(ll x){
	ll ans=0;
	ll cnt=0;
	while(x>0){
		if(x%2==0){
			ans+=pow(2,cnt);
		}
		cnt++;
		x>>=1;
	}
	return ans;
}
int main(){
	int T; sc(T);
	while(T--){
		ll x; scanf("%lld",&x);
		cout<<last(x)<<endl;
	}
	return 0;
}
