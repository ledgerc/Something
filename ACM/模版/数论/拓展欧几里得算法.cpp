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

//返回d=gcd(a,b);和对应于等式ax+by=d中的x,y
ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(a==0&b==0)
		return -1;
	if(b==0){
		x=1;y=0;
		return a;
	}
	ll d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
//求逆元素 ax=1(mod n)
ll mod_reverse(ll a,ll n){
	ll x,y;
	ll d=extend_gcd(a,n,x,y);
	if(d==1)
		return (x%n+n)%n;
	else
		return -1;
}
