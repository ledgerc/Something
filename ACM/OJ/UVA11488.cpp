#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cctype>
#include<stack>
#include<cmath>
#include<string>
#include<cstring>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const ll INF = 1e18;
const ll MOD = 20071027;
const double EPS = 1e-10;
const double Pi = acos(-1.0);
const int maxn = 2e5+10;
const int MAX = 26;
const int maxnode = 4000*100+100;
const int sigma_size = 26;
struct Trie{
	int ch[maxnode][sigma_size];
	ll val[maxnode];
	int sz;
	void clear(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
	}
	int idx(char c){
		return c-'0';
	}
	void insert(char *s){
		int u=0,n=strlen(s);
		for(int i=0; i<n; i++){
			int id=idx(s[i]);
			if(ch[u][id]==0){
				ch[u][id]=sz;
				memset(ch[sz],0,sizeof ch[sz]);
				val[sz++]=0;
			}
			u=ch[u][id];
			val[u]++;
		}
	}
	ll search(char *s){
		ll n=strlen(s),u=0,ans=0,res=0;
		for(int i=0; i<n; i++){
			int id=idx(s[i]);
			res++;
			if(ch[u][id]==0)
				return ans;
			u=ch[u][id];
			if(val[u]>0){
				ans=max(ans,res*val[u]);
			}
		}
		return ans;
	}
};
Trie trie;
char s[50010][210];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		trie.clear();
		int n; scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%s",&s[i]);
			trie.insert(s[i]);
		}
		ll ans=0;
		for(int i=0; i<n; i++){
			ans=max(ans,trie.search(s[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

