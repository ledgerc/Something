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
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int ans=a[0]-a[1];
		int maxai=a[0];
		for(int j=1; j<n; j++){
			ans=max(ans,maxai-a[j]);
			maxai=max(a[j],maxai);
		}
		printf("%d\n",ans);
	}
	return 0;
}
