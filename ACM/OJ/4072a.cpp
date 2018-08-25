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

int a[maxn];
int main(){
	int n,m; sc(n); sc(m);
	for(int i=0; i<n; i++)
		sc(a[i]);
	int cnt=0;
	for(int i=0; i<n; i++){
		cnt+=a[i]/m;
		if(a[i]%m!=0)
			cnt++;
	}
	int ans=cnt/2;
	if(cnt%2!=0)
		ans++;
	cout<<ans<<endl;
}
