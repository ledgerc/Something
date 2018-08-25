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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

string s;
int a[maxn];
int main(){
	cin>>s;
	memset(a,0,sizeof a);
	for(int i=0; i<s.size(); i++)
		a[s[i]]++;
	int ans=inf;
	ans=min(ans,a['B']);
	ans=min(ans,a['u']/2);
	ans=min(ans,a['l']);
	ans=min(ans,a['b']);
	ans=min(ans,a['a']/2);
	ans=min(ans,a['s']);
	ans=min(ans,a['r']);
	cout<<ans<<endl;;
}
