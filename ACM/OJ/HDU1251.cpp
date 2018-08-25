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
	int val[maxnode];
	int sz;
	void clear(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
	}
	int idx(char c){
		return c-'a';
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
	int search(char *s){
		int n=strlen(s),u=0;
		for(int i=0; i<n; i++){
			int id=idx(s[i]);
			if(ch[u][id]==0)
				return 0;
			u=ch[u][id];
		}
		return val[u];
	}
};
Trie trie;
char s[100];
int main(){
	trie.clear();
	while(gets(s)){
		if(strcmp(s,"")==0)
			break;
		trie.insert(s);
	}
	while(gets(s)){
		printf("%d\n",trie.search(s));
	}
	return 0;
}
