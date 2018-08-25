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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	string tmp1,tmp2;
	cin>>tmp1;
//	cout<<"tmp1: "<<tmp1<<endl;
	tmp2=tmp1;
	tmp2+=tmp1;
//	cout<<"tmp2: "<<tmp2<<endl;
	tmp2.erase(0,1);
//	cout<<"tmp2: "<<tmp2<<endl;
	cout<<tmp2.find(tmp1)+1;
	return 0;
}
