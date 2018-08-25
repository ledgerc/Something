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

ll n,k,a,b;
bool check(ll k,ll a,ll b){
	k-=a+b;
	if(k%3)
		return false;
	k/=3;
	if(k<0||k+a<0||k+b<0)
		return false;
	return k<=n&&k+a<=n&&k+b<=n;
}
int main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>k>>a>>b;
		if(n%3!=0){
			cout<<"no"<<endl;
			continue;
		}
		n/=3;
		if(check(k,a,a+b)||check(k,a,a-b)||check(k,-a,b-a)||check(k,-a,-a-b))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
