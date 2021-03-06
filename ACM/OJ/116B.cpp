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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	int n,m; cin>>n>>m;
	set<string> ss;
	for(int i=0; i<n+m; i++){
		string tmp; cin>>tmp;
		ss.insert(tmp);
	}
	int cnt=n+m-ss.size();
	m-=cnt%2;
	if(n>m)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
