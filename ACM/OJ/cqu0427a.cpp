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
	ll n,m; cin>>n>>m;
	if(n==1&&m==1){
		cout<<"0"<<endl;
	}
	else if(m==1){
		cout<<n-1<<endl;
	}
	else if(n==1){
		cout<<m-1<<endl;
	}
	else{
		ll ans=n*m-1;
		cout<<ans<<endl;	
	}
	return 0;
}
