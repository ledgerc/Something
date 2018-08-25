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

int a[10],b[10],c[10];
int main(){
	int n; cin>>n;
	int tmp;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	for(int i=1; i<=n; i++){
		cin>>tmp;
		a[tmp]++,c[tmp]++;
	}
	for(int i=1; i<=n; i++){
		cin>>tmp;
		b[tmp]++,c[tmp]++;
	}
	int ans=0;
	for(int i=1; i<=5; i++){
		if(c[i]%2){
			printf("-1\n");
			return 0;
		}
		else if(a[i]>b[i])
			ans+=a[i]-c[i]/2;
	}
	printf("%d\n",ans);
	return 0;
}
