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
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
 
 struct Edge{
 	int to,next;
 }edge[maxn];
 int tot,head[maxn];
 void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
}
 int size[maxn];
 ll fib[maxn];
 ll res;
void dfs(int u,int pre){
 	int son=0,leaf=0; size[u]=1;
 	for(int i=head[u]; i!=-1; i=edge[i].next){
 		int v=edge[i].to;
 		if(v==pre) continue;
 		dfs(v,u); son++;
 		size[u]+=size[v];
 		if(size[v]>1)
 			leaf++;
	}
	if(leaf>2){
		res=0;
	}
	else if(leaf>0){
		res=2*res%mod;
	}
	res=res*fib[son-leaf]%mod;
	//prln(res)
 }
 void init(){
 	tot=0; res=1;
 	memset(head,-1,sizeof head);
 }
int main(){
	fib[0]=fib[1]=1;
	for(int i=2; i<maxn; i++)
		fib[i]=i*fib[i-1]%mod;
	int T; scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		init();
		int n; scanf("%d",&n);
		if(n==1) printf("Case #%d: 1\n",kase);
		for(int i=1; i<n; i++){
			int u,v; scanf("%d%d",&u,&v);
			addedge(u,v); addedge(v,u);
		}
		dfs(1,-1);
		printf("Case #%d: %lld\n",kase,res*2%mod);
	}
	return 0;
}
