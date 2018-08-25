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

int a[maxn];
int b[maxn];
int n,m,l,r,x;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	for(int i=0; i<m; i++){
		scanf("%d%d%d",&l,&r,&x);
		sort(b+l,b+r+1);
		if(b[x]==a[x])
			printf("Yes\n");
		else
			printf("No\n");
		for(int i=1; i<=r; i++)
			b[i]=a[i];
	}
}
