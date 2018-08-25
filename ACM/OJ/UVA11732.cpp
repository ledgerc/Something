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
const int maxnode = 4000*1000+100;
const int sigma_size = 26;
ll ans;
struct Trie{
	int head[maxnode];
	int next[maxnode];
	char ch[maxnode];
	int tot[maxnode];
	int flag[maxnode];
	int sz;
	void clear(){
		sz=1; tot[0]=head[0]=next[0]=0;
		memset(flag,0,sizeof flag);
	}
	void insert(const char *s){
		int u=0,v,n=strlen(s);
		ans+=tot[0];
		tot[0]++;
		for(int i=0; i<n; i++){
			bool found=false;
			for(v=head[u]; v!=0; v=next[v])
				if(ch[v]==s[i]){
					found=true;
					break;
				}
			if(!found){
				v=sz++;
				tot[v]=flag[v]=head[v]=0;
				next[v]=head[u];
				ch[v]=s[i];
				head[u]=v;
			}
			u=v;
			ans+=tot[u]*2;
			tot[u]++;
		}
		if(flag[v])
			ans+=flag[v];
		flag[v]++;
	}
};
char s[1010];
Trie trie;
int main(){
	int n,kase=1;
	while(scanf("%d",&n)!=EOF&&n){
		trie.clear();
		ans=0;
		for(int i=0; i<n; i++){
			scanf("%s",s);
			trie.insert(s);
		}
		printf("Case %d: %lld\n",kase++,ans);
	}
	return 0;
}
