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
const int maxn = 3e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

string s;
int tmp; 
int a[maxn];
int main(){
	int n; cin>>s>>n;
	while(n--){cin>>tmp;
		a[--tmp]++;
		a[s.size()-tmp]++;
	}
	for(n=0,tmp=0; n<s.size(); n++){
		tmp+=a[n];
		cout<<s[(tmp%2?s.size()-1-n:n)];
	}
	return 0;
}
