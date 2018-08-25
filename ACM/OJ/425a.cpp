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
#include<bitset>
#include<stack>
#include<cctype>
#define key_value (ch[ch[root][1]][0])
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
char s[maxn],a[maxn];
bool vis[100];
int main(){
	ll n,k; cin>>n>>k;
	if((n/k)%2==0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}
/*
abc
a*a
4
aaaaaa
adddda
*/
