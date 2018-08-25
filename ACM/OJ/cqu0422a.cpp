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
	int n;
	int a[maxn];
	sc(n);
	for(int i=1; i<=n; i++)
		sc(a[i]);
	sort(a+1,a+n+1);
	int sum=0;
	int last;
	sum=1; last=a[1];
	for(int i=2; i<=n; i++){
		if(a[i]<=last+4)
			continue;
		last=a[i];
		sum++;
	}
	cout<<sum<<endl;
}
