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
const int maxn = 6e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Node{
	ll p,cost,len,type;
	bool operator < (const Node& a) const {
		if(p==a.p)	return type<a.type;
		return p<a.p;
	}
}a[maxn];
int main(){
	int n,x; scanf("%d%d",&n,&x);
	int cnt=0;
	for(int i=0; i<n; i++){
		int l,r,cost; scanf("%d%d%d",&l,&r,&cost);
		a[cnt].p=l; a[cnt].len=r-l+1; a[cnt].cost=cost; a[cnt].type=-1; cnt++;
		a[cnt].p=r; a[cnt].len=r-l+1; a[cnt].cost=cost; a[cnt].type=1; cnt++;
	}
	ll best[maxn];
	memset(best,INF,sizeof best);
	sort(a,a+cnt);
	ll ans=INF;
	for(int i=0; i<cnt; i++){
		if(a[i].type==-1){
			if(a[i].len<x)
				ans = min(ans,(ll)a[i].cost+best[x-a[i].len]);
		}
		else{
			best[a[i].len]=min(best[a[i].len],a[i].cost);
		}
	}
	if(ans>=INF)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
}
