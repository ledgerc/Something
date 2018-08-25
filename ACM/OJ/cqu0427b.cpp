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
	int n,k,a[maxn];
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int ans=inf,ansid;
	sort(a+1,a+n+1);
	for(int i=k; i<=n; i++){
		int tmp=a[i]-a[i-k+1];
		if(tmp<ans){
			ans=tmp;
		}
	}
	cout<<ans<<endl;
}
