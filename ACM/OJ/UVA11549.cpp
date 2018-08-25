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
#include<sstream>
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
int next(int n,int k){
	stringstream ss;
	ss<<(long long)k*k;
	string s=ss.str();
	if(s.length()>n)
		s=s.substr(0,n);
	int ans;
	stringstream ss2(s);
	ss2>>ans;
	return ans;
}
int main(){
	int T; cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		int ans=k;
		int k1=k,k2=k;
		//Floyd
		do{
			k1=next(n,k1);
			k2=next(n,k2);
			if(k2>ans)
				ans=k2;
			k2=next(n,k2);
			if(k2>ans)
				ans=k2;
		}while(k1!=k2);
		cout<<ans<<endl;
	}
	return 0;
}
