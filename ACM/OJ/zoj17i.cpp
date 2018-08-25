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
	int T; scanf("%d",&T);
	while(T--){
		ll sum1=0,sum2=0;
		int tmp1,tmp2;
		int n; scanf("%d",&n);
		while(n--){
			scanf("%d%d",&tmp1,&tmp2);
			if(tmp1>=tmp2){
				sum1+=tmp1;
				sum2+=tmp2;
			}
		}
		ll ans=sum1*sum1-sum1*sum2-sum2*sum2;
		cout<<ans<<endl;
	}
}
