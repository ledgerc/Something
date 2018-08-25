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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char s[maxn]={"qwertyuiopasdfghjkl;zxcvbnm,./"};
int main(){
	int tmp;
	char tmpc; scanf("%c",&tmpc);
	if(tmpc=='L') tmp=1;
	else tmp=-1;
	char s1[maxn];
	scanf("%s",s1);
	int len=strlen(s1);
	for(int i=0; i<len; i++)
		for(int j=0; ; j++){
			if(s[j]==s1[i]){
				cout<<s[j+tmp];
				break;
			}
		}
	return 0;
}
