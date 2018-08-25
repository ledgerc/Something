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

int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	cout<<3<<endl;
	cout<<e+c-a<<" "<<f+d-b<<endl;
	cout<<e+a-c<<" "<<f+b-d<<endl;
	cout<<a+c-e<<" "<<b+d-f<<endl;
	return 0;
}
