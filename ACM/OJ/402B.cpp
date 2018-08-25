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

string s;
int main(){
	int n;
	cin>>s>>n;
	int len=s.size()-1;
	int a=0,b=0;
	while(len>=0){
		if(s[len]=='0')
			a++;
		else
			b++;
		if(a==n){
			cout<<b<<endl;
			return 0;
		}
		len--;
	}
	cout<<s.size()-1<<endl;
	return 0;
}
