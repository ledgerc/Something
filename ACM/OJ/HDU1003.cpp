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

int a[maxn],sum[maxn],s[maxn];
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		int n; cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		int ans=0; sum[0]=a[0];
		s[0]=0;
		for(int i=1; i<n; i++){
			if(sum[i-1]>=0){
				sum[i]=sum[i-1]+a[i];
				s[i]=s[i-1];
			}
			else{
				sum[i]=a[i];
				s[i]=i;
			}
			if(sum[ans]<sum[i])
				ans=i;
		}
		printf("Case %d:\n%d %d %d\n",kase,sum[ans],s[ans]+1,ans+1);
		if(kase!=T)
			puts("");
	}
	return 0;
}
