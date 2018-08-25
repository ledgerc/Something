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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	map<ll,ll> mp;
	set<ll> s;
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		ll sum=0; mp.clear(); s.clear();
		for(int i=0; i<n; i++){
			ll tmp; scanf("%lld",&tmp);
			mp[tmp]++;
			s.insert(tmp);
		}
		set<ll>::iterator it;
		for(it=s.begin(); it!=s.end(); it++)
			sum+=mp[*it]*(mp[*it]-1);
		cout<<sum<<"\n";
	}
	return 0;
}
