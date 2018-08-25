#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const ll INF = 1e18;
const int maxn = 2e5+10;
const ll MOD = 20071027;
const double EPS = 1e-10;
const double Pi = acos(-1.0);
const int MAX = 26;
const int maxnode = 50*4000*100+100;
const int sigma_size = 2;
struct Trie{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	void clear(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
	}
	void insert(int *s){
		int u=0,n=32;
		for(int i=0; i<n; i++){
			int id=s[i];
			if(ch[u][id]==0){
				ch[u][id]=sz;
				memset(ch[sz],0,sizeof ch[sz]);
				val[sz++]=0;
			}
			u=ch[u][id];
		}
		val[u]=1;
	}
	int search(int *s){
		int n=32,u=0,ans=0;
		for(int i=0; i<n; i++){
			int id=s[i];
			if(ch[u][id]==0)
				id=1-id;
			ans+=id<<(n-1-i);
			u=ch[u][id];
		}
		return ans;
	}
};
Trie trie;
int main(){
	int T; scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		int n,m; scanf("%d%d",&n,&m);
		trie.clear();
		for(int i=0; i<n; i++){
			int x; scanf("%d",&x);
			int s[40];
			for(int j=31; j>=0; j--){
				if((x>>j)&1)
					s[31-j]=1;
				else
					s[31-j]=0;
			}
			trie.insert(s);
		}
		printf("Case #%d:\n",kase);
		for(int i=0; i<m; i++){
			int x; scanf("%d",&x);
			int s[40];
			for(int j=31; j>=0; j--){
				if((x>>j)&1)
					s[31-j]=0;
				else
					s[31-j]=1;
			}
			printf("%d\n",trie.search(s));
		}
	}
	return 0;
}
