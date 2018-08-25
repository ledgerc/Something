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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	ll k,n,m;
	cin>>k>>n>>m;
	ll ans=n/k+m/k;
	if(ans==0)
		cout<<"-1"<<endl;
	else{
		if(n/k==0&&m%k)
			cout<<"-1"<<endl;
		else if(m/k==0&&n%k)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
