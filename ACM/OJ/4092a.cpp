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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char s[maxn];
int main(){
	scanf("%s",s);
	int cnt=0;
	bool flag=false;
	int len=strlen(s);
	for(int i=0; i<len-1; i++){
		if(s[i]=='V'&&s[i+1]=='K'){
			s[i]='#'; s[i+1]='#';
			cnt++;
		}
	}
	for(int i=0; i<len-1; i++){
		if(s[i]=='V'&&s[i+1]=='V')
			flag=true;
		if(s[i]=='K'&&s[i+1]=='K')
			flag=true;
	}
	if(flag)
		cnt++;
	cout<<cnt<<endl;
}
