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

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int T; cin>>T;
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		set<int> s;
		ll cnt1=0,cnt2=0;
		if(n>1){
			cnt1++;
			s.insert(n);
		}
		if(m>1){
			cnt2++;
			s.insert(m);
		}
		for(int i=1; i<=sqrt(n); i++){
			if(n%i==0){
				s.insert(i);
				cnt1++;
			}
		}
		for(int i=1; i<=sqrt(m); i++){
			if(m%i==0){
				s.insert(i);
				cnt2++;
			}
		}
		ll tmp1=cnt1+cnt2-s.size();
		ll tmp2=cnt1*cnt2;
		ll tmp=gcd(tmp1,tmp2);
		cout<<tmp1/tmp<<"/"<<tmp2/tmp<<endl;
	}
}
