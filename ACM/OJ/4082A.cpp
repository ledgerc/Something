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

int n,m,k;
int a[maxn];
int main(){
	cin>>n>>m>>k;
	int ans1=inf,ans2=inf;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=m-1; i>0; i--){
		if(a[i]<=k&&a[i]!=0){
			ans1=m-i;
			break;
		}
	}
	for(int i=m+1; i<=n; i++){
		if(a[i]<=k&&a[i]!=0){
			ans2=i-m;
			break;
		}
	}
//	cout<<ans1<<" "<<ans2<<endl;
	cout<<min(ans1,ans2)*10<<endl;
	return 0;
}
