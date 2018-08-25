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
int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int pow(int a,int b){
    ll ans=1;
    a%=mod;
    while(b){
        if(b&1)
			ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main(){
	int a,p;
	cin>>a>>mod;
	int ans=0;
	for(int i=1; i<=a; i++){
		ans+=pow(i,a);
		ans%=mod;
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
