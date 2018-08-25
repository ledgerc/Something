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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		int n; cin>>n;
		int tmp;
		bool flag=false;
		int mx=-1,mxgcd=0;
		for(int i=1; i<=n; i++){
			scanf("%d",&tmp);
			if(tmp==0)
				flag=true;
			mx=max(mx,tmp);
			mxgcd=gcd(mxgcd,tmp);
		}
		double ans=mx/mxgcd-n;
		if(flag)
			ans+=1.0;
		n=mx/mxgcd;
		if(flag)
			n+=1;
		for(int i=0; i<n; i++){
			ans+=(double)n/(n-i);
		}
	//	PR(ans)
		printf("Case #%d: %d\n",kase,(int)(ans));
	}
	return 0;
}
