#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


int main(){
	int T; scanf("%d",&T);
	while(T--){
		ll a,b; scanf("%lld%lld",&a,&b);
		ll temp = (double) a*b;
		ll tmp = pow(temp,1.0/3);
		while(tmp*tmp*tmp<temp)
			tmp++;
		if(tmp*tmp*tmp==temp&&a%tmp==0&&b%tmp==0)
			puts("Yes");
		else
			puts("No"); 
	}
	return 0;
}
