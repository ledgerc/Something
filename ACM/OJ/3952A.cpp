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
int n,m,k;
int main(){
	cin>>n>>m>>k;
	memset(a,0,sizeof a);
	for(int i=0; i<1e4+7; i++){
		int tmp=i*m;
		if(tmp>k)
			break;
		a[tmp]++;
	}
	for(int i=0; i<1e4+7; i++){
		int tmp=i*n;
		if(tmp>k)
			break;
		a[tmp]++;
	}
	int ans=0;
	for(int i=1; i<=k; i++)
		if(a[i]==2)
			ans++;
	cout<<ans<<endl;
	return 0;
}
