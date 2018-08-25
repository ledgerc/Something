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
const int maxn = 2e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Edge{
	int to,next;
}edge[maxm];
int tot,head[maxn];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
bool vis[maxn];//染色标记，为true表示选择
int S[maxn],top;//栈 
bool dfs(int u){
	if(vis[u^1])
		return false;
	if(vis[u])
		return true;
	vis[u]=true;
	S[top++]=u;
	for(int i=head[u]; i!=-1; i=edge[i].next)
		if(!dfs(edge[i].to))
			return false;
	return true;
}
bool Twosat(int n){
	memset(vis,false,sizeof vis);
	for(int i=0; i<n; i+=2){
		if(vis[i]||vis[i^1])
			continue;
		top=0;
		if(!dfs(i)){
			while(top)
				vis[S[--top]]=false;
			if(!dfs(i^1))
				return false;
		}
	}
	return true;
}
int main(){
	int n,m;
	int u,v;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		while(m--){
			scanf("%d%d",&u,&v);
			u--,v--;
			addedge(u,v^1); addedge(v,u^1);
		}
		if(Twosat(2*n)){
			for(int i=0; i<2*n; i++)
				if(vis[i])
					printf("%d\n",i+1);
		}
		else
			printf("NIE\n");
	}
	return 0;
}
