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
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	int n,a,b; cin>>n;
	a=b=sqrt(n);
	if(a*b==n){
		cout<<a<<" "<<b<<endl;
		return 0;
	}
	while(true){
		while(a*b<=n){
			b++;
			if(a*b==n){
				cout<<a<<" "<<b<<endl;
				return 0;
			}
		}
		a--;
	}
	return 0;
}
