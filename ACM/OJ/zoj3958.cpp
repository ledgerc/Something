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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	int T; cin>>T;
	while(T--){
		int cnt1=0,cnt2=0;
		int n; cin>>n;
		while(n--){
			int tmp; cin>>tmp;
			if(tmp==1)
				cnt1++;
			if(tmp==2)
				cnt2++;
		}
		if(cnt1>cnt2)
			cout<<"Kobayashi"<<endl;
		else if(cnt1<cnt2)
			cout<<"Tohru"<<endl;
		else
			cout<<"Draw"<<endl;
	}
	return 0;
}
