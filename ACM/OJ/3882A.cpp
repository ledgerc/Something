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
	int n; cin>>n;
	int cnt=0;
	bool flag=false;
	if(n%2!=0){
		flag=true;
		n-=3;
		cnt++;
	}
	int tmp=n/2;
	cnt+=n/2;
	cout<<cnt<<endl;
	if(flag)
		cout<<"3 ";
	for(int i=0; i<tmp; i++)
		cout<<"2 ";
	cout<<endl;
	return 0;
}
