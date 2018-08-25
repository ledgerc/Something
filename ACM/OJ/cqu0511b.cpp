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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int MAX = 26;
const int maxnode = 1e5+7;
const int sigma_size = 26;
struct Trie{
	int ch[maxnode][sigma_size];
	int cnt[maxnode];
	int sz;
	multiset<pair<int,int> > suffix;
	void clear(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		suffix.clear();
		suffix.insert({inf,inf});
	}
	int idx(char c){
		return c-'a';
	}
	void insert(const char *s,int add){
		int u=0,n=strlen(s);
		for(int i=0; i<n; i++){
			int id=idx(s[n-i-1]);
			if(ch[u][id]==0){
				ch[u][id]=sz;
				memset(ch[sz],0,sizeof ch[sz]);
				cnt[sz++]=0;
			}
			u=ch[u][id];
			auto iter=suffix.find({i+1,cnt[u]});
			if(iter!=suffix.end())
				suffix.erase(iter);
			cnt[u]+=add;
			suffix.insert({i+1,cnt[u]});
		}
	}
	bool query(int k,int l){
		return suffix.lower_bound({l,k})->first==l;
	}
};
Trie trie;
char s[maxn];
int main(){
	int q; scanf("%d",&q);
	trie.clear();
	vector<string> qs(q);
	bool vis[maxn];
	memset(vis,false,sizeof vis);
	for(int i=0; i<q; i++){
		int op; scanf("%d",&op);
		if(op==1){
			scanf("%s",s);
			trie.insert(s,1);
			qs[i]=s;
		}
		else if(op==2){
			int k,l; scanf("%d%d",&k,&l);
			if(trie.query(k,l))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			int x; scanf("%d",&x);
			if(!vis[x]){
				vis[x]=true;
				trie.insert(qs[x-1].c_str(),-1);
			}
		}
	}
	return 0;
}
