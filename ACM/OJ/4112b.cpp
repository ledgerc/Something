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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	char s[maxn]; scanf("%s",s);
	int t=0,ans=0;
	int len=strlen(s);
	for(int i=len-1; i>=0; i--){
		if(s[i]=='b')
			t=(t+1)%mod;
		else{
			ans+=t; ans%=mod;
			t*=2; t%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
