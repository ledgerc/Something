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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char s[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		scanf("%s",s);
		char ans[maxn];
		int len=strlen(s);
		strcpy(ans,s);
		for(int i=0; i<len; i++){
			int tmpc=s[len-1];
			for(int j=len-1; j>=1; j--)
				s[j]=s[j-1];
			s[0]=tmpc;
			if(strcmp(s,ans)<0)
				strcpy(ans,s);
		}
		printf("%s\n",ans);
	}
	return 0;
}
