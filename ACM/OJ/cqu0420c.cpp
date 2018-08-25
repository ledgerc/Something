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

int f[maxn];
int find(int x){
	if(f[x]==-1)
		return x;
	return f[x]=find(f[x]);
}
void unite(int a,int b){
	int ta=find(a),tb=find(b);
	if(ta!=tb)
		f[ta]=tb;
}
int main(){
	int T; sc(T);
	while(T--){
		int n,m;
		ll cl,cr; scanf("%d%d%lld%lld",&n,&m,&cl,&cr);
		int u,v;
		memset(f,-1,sizeof f);
		for(int i=0; i<m; i++){
			scanf("%d%d",&u,&v);
			unite(u,v);
		}
		if(cl<=cr){
			ll ans=(ll)n*cl;
			cout<<ans<<endl;
			continue;
		}
		set<int> ans;
		for(int i=1; i<=n; i++){
			int tmp=find(i);
			ans.insert(tmp);
		}
		ll cnt=ans.size();
		ll sum=cl*cnt+((ll)n-cnt)*cr;
		cout<<sum<<endl;
		ans.clear();
	}
	return 0;
}
