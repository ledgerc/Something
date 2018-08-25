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
	int n; int a[maxn];
	sc(n);
	int minn=inf;
	for(int i=0; i<n; i++){
		sc(a[i])
		minn=min(a[i],minn);
	}
	vector<int> ans;
	vector<int> cnt;
	while(true){
		ans.push_back(minn);
		int tmp=inf,tmpcnt=0;
		for(int i=0; i<n; i++){
			if(a[i]>0){
				a[i]-=minn;
				tmpcnt++;
			}
			if(a[i]>0)
				tmp=min(tmp,a[i]);
		}
		cnt.push_back(tmpcnt);
		if(tmp==inf)
			break;
		minn=tmp;
	}
	for(int i=0; i<ans.size(); i++)
		cout<<cnt[i]<<endl;
	return 0;
}
