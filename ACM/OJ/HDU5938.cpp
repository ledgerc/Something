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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

ll tot,mx,tmpa,tmpb;
char s[maxn];
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		scanf("%s",s);
		int len=strlen(s);
		
		tot=0,mx=0; tmpa=0,tmpb=0;
		tot=-(s[len-3]-'0')*(s[len-2]-'0')/(s[len-1]-'0');
		tmpa=s[0]-'0',tmpb=0;
		for(int i=1;i<len-3;i++)  
            tmpb=tmpb*10+s[i]-'0';
		mx=tot+tmpa+tmpb;
		
		tmpa=s[len-4]-'0',tmpb=0;
		for(int i=0;i<len-4;i++)  
            tmpb=tmpb*10+s[i]-'0';
		tot+=tmpa+tmpb;
		mx=max(mx,tot);
		
		if(len>5){
			tot=-(s[len-4]-'0')*(s[len-3]-'0')/((s[len-2]-'0')*10+(s[len-1]-'0'));
			tmpa=s[0]-'0',tmpb=0;
			for(int i=1; i<len-4; i++)
				tmpb=tmpb*10+s[i]-'0';
			tot+=tmpa+tmpb;
			mx=max(mx,tot);
			
			tot=-(s[len-4]-'0')*(s[len-3]-'0')/((s[len-2]-'0')*10+(s[len-1]-'0'));
			tmpa=s[len-5]-'0',tmpb=0;
			for(int i=0; i<len-5; i++)
				tmpb=tmpb*10+s[i]-'0';
			tot+=tmpa+tmpb;
			mx=max(mx,tot);
		}
		printf("Case #%d: %lld\n",kase,mx);
	}
	return 0;
}
