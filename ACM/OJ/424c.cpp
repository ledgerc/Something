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
const int maxn =3e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int a[maxn],b[maxn],c[maxn];
int main(){
	memset(b,0,sizeof b);
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
		b[i]=b[i-1]+a[i];
	sort(b+1,b+n+1);
	n=unique(b+1,b+n+1)-b-1;
	for(int i=1; i<=m; i++)
		scanf("%d",&c[i]);
	int ans=n;
	for(int i=1; i<=n; i++){
		int tmp=c[1]-b[i];
		for(int j=1; j<=m; j++){
			if(!binary_search(b+1,b+n+1,c[j]-tmp)){
				ans--;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 
