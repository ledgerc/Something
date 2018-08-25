#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
#define bug() cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//求子树中的点值与x异或的最大值 
vector<int> e[maxn];
int n,q,a[maxn];
int tot,index;
int tree[maxn*35][2],ch[maxn*35][2],root[maxn];
int first[maxn],ed[maxn];
void build(int last,int cur,int num,int pos){
	if(pos<0) return;
	int tmp = !!(num&(1<<pos));
	tree[cur][tmp]=tree[last][tmp]+1;
	tree[cur][tmp^1]=tree[last][tmp^1];
	ch[cur][tmp^1]=ch[last][tmp^1];
	build(ch[last][tmp],ch[cur][tmp]=++tot,num,pos-1);
}
void dfs(int u){
	first[u]=++index;
	build(root[first[u]-1],root[first[u]]=++tot,a[u],30);
	for(int i=0; i<e[u].size(); i++){
		int v=e[u][i];
		dfs(v);
	}
	ed[u]=index;
}
int query(int last,int cur,int num,int sum,int pos){
	if(pos<0) return sum;
	int tmp = !!(num&(1<<pos));
	if(tree[cur][tmp^1]-tree[last][tmp^1]>0)
		return query(ch[last][tmp^1],ch[cur][tmp^1],num,sum|(1<<pos),pos-1);
	else
		return query(ch[last][tmp],ch[cur][tmp],num,sum,pos-1);
}
void init(){
	tot=index=0;
	memset(tree,0,sizeof tree);
	memset(ch,0,sizeof ch);
	memset(root,0,sizeof root);
	for(int i=0; i<=n; i++) e[i].clear();
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		init();
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		for(int i=2; i<=n; i++){
			int u; scanf("%d",&u);
			e[u].push_back(i);
		}
		dfs(1);
		while(q--){
			int u,x; scanf("%d%d",&u,&x);
			printf("%d\n",query(root[first[u]-1],root[ed[u]],x,0,30));
		}
	}
}
