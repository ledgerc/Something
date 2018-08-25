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
#define key_value (ch[ch[root][1]][0])
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
char s[maxn],a[maxn];
bool vis[100];
int main(){
	memset(vis,false,sizeof vis);
	scanf("%s",s);
	for(int i=0; i<strlen(s); i++){
		vis[s[i]-'a']=true;
	}
	scanf("%s",s);
	scanf("%d",&n);
	bool f=false;
	for(int i=0; i<strlen(s); i++){
		if(s[i]=='*'){
			f=true;
			break;
		}
	}
	for(int kase=0; kase<n; kase++){
		scanf("%s",a);
		if(!f){
			if(strlen(a)<strlen(s)){
				puts("NO");
				continue;
			}
		}
		else if(strlen(a)<strlen(s)-1){
			puts("NO");
			continue;
		}
		bool flag=true;
		int pos;
		for(pos=0; pos<strlen(a); pos++){
			if(s[pos]=='*')
				break;
			if(s[pos]=='?'){
				if(!vis[a[pos]-'a']){
					flag=false;
					break;
				}
			}
			else if(s[pos]!=a[pos]){
				flag=false;
				break;
			}
		}
		int lens=strlen(s)-1,lena=strlen(a)-1;
		int len=lens-pos;
		int i;
		for(i=0; i<len; i++){
			if(s[lens-i]=='*')
				break;
			if(s[lens-i]=='?'){
				if(!vis[a[lena-i]-'a']){
					flag=false;
					break;
				}
			}
			else if(s[lens-i]!=a[lena-i]){
				flag=false;
				break;
			}
		}
		/*
		while(lens>=pos&&lena>=pos){
			if(s[lens]=='*')
				break;
			if(s[lens]=='?'){
				if(!vis[a[lena]-'a']){
					flag=false;
					break;
				}
			}
			else if(s[lens]!=a[lena]){
				flag=false;
				break;
			}
			lens--,lena--;
		}
		*/
		lena=lena-i;
		for(i=pos; i<=lena; i++){
			if(vis[a[i]-'a']){
				flag=false;
				break;
			}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
}
/*
abc
a*a
4
aaaaaa
adddda
*/
