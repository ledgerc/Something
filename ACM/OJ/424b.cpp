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
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

map<char,char> mp;
int main(){
	char mp1[maxn],mp2[maxn];
	char s[maxn];
	scanf("%s%s%s",mp1,mp2,s);
	for(int i=0; i<26; i++)
		mp[mp1[i]]=mp2[i];
	int len=strlen(s);
	for(int i=0; i<len; i++){
		if(s[i]>='0'&&s[i]<='9')
			printf("%c",s[i]);
		else if(s[i]>='a'&&s[i]<='z')
			printf("%c",mp[s[i]]);
		else
			printf("%c",mp[s[i]-'A'+'a']-'a'+'A');
	}
	printf("\n");
	return 0;
}
