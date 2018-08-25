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

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int T; cin>>T;
	while(T--){
		int l,b; cin>>l>>b;
		int tmp=gcd(l,b);
		l/=tmp; b/=tmp;
		cout<<l*b<<endl;
	}
	return 0;
} 
