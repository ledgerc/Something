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

int n;
int a[maxn];
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		double v=a[n]-a[n-1];
		int sum=0;
		for(int i=n-1; i>=1; i--){
			for(int j=(a[i]-a[i-1])/v; ; j++){
				double y=(a[i]-a[i-1])*1.0/j;
				if(y<=v){
					sum+=j;
					v=y;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",kase,sum+1);
	}
	return 0;
} 
