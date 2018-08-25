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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	int n; cin>>n;
	int m[100],r=0; char a,b;
	memset(m,0,sizeof m);
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		m[a-97]++;
		if(m[b-65]==0)
			r++;
		else
			m[b-65]--;
	}
	cout<<r<<endl;
	return 0;
}
