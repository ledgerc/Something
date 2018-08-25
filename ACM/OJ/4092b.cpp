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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	char s1[maxn],s2[maxn];
	scanf("%s%s",s1,s2);
	int len=strlen(s1);
	char ans[maxn];
	bool flag=false;
	for(int i=0; i<len; i++){
		if(s2[i]>s1[i])
			flag=true;
		if(s2[i]==s1[i])
			ans[i]='z';
		else
			ans[i]=s2[i];
	}
	if(flag)
		cout<<"-1"<<endl;
	else
		printf("%s\n",ans);
	return 0;
}
