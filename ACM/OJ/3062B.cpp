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
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
int c[maxn];
int l,r,x;
int ans;
void dfs(int id,int mx,int mn,int sum){
	if(id==n+1)
		return ;
	if(sum<=r&&sum>=l&&x<=mx-mn&&id==n)
		ans++;
	dfs(id+1,max(mx,c[id]),min(mn,c[id]),sum+c[id]);
	dfs(id+1,mx,mn,sum);
	return ;
}
int main(){
	cin>>n>>l>>r>>x;
	for(int i=0; i<n; i++)
		cin>>c[i];
	ans=0;
	dfs(0,0,inf,0);
	cout<<ans<<endl;
	return 0;
}
