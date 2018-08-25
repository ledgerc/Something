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
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,a[maxn];
set<int> s[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	sort(a+1,a+n+1);
	int pos=0;
	ll ans=n;
	for(int i=1; i<=n; i++){
		int num=a[i];
		auto it=s[a[i]].lower_bound(pos);
		if(it==s[num].end()){
			ans+=n-(i-1);
		//	pr(num) prln(i)
			pos=0;
			it=s[num].lower_bound(pos);
		}
		pos=*it;
		s[num].erase(it);
	}
	cout<<ans<<endl;
	return 0;
}
