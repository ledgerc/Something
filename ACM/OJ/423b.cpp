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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


int main(){
	int n,m;
	char mp[maxn][maxn];
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%s",mp[i]+1);
	int l=inf,r=-inf,up=inf,down=-inf;
	int cnt=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			if(mp[i][j]=='B'){
				l=min(j,l); r=max(j,r);
				up=min(i,up); down=max(i,down);
				cnt++;
			}
		}
	if(cnt==0){
		printf("1\n");
		return 0;
	}
	int len=max(r-l+1,down-up+1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if (j+len-1>=r&&j<=l&&i+len-1>=down&&i<=up&&i+len-1<=n&&j+len-1<=m){
				printf("%d\n",len*len-cnt);
				return 0;
			}
	printf("-1\n");
	return 0;
}
