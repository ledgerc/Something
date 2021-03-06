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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int DEG = 20;
struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int fa[maxn][DEG];//fa[i][j]表示结点i的第2^j个祖先
int deg[maxn];//深度数组 
void BFS(int root){
	queue<int> que;
	deg[root]=0;
	fa[root][0]=root;
	que.push(root);
	while(!que.empty()){
		int tmp=que.front(); que.pop();
		for(int i=1; i<DEG; i++)
			fa[tmp][i]=fa[fa[tmp][i-1]][i-1];
		for(int i=head[tmp]; i!=-1; i=edge[i].next){
			int v=edge[i].to;
			if(v==fa[tmp][0])
				continue;
			deg[v]=deg[tmp]+1;
			fa[v][0]=tmp;
			que.push(v);
		}
	}
}
int LCA(int u,int v){
	if(deg[u]>deg[v])
		swap(u,v);
	int hu=deg[u],hv=deg[v];
	int tu=u,tv=v;
	for(int det=hv-hu,i=0; det; det>>=1,i++)
		if(det&1)
			tv=fa[tv][i];
	if(tu==tv)
		return tu;
	for(int i=DEG-1; i>=0; i--){
		if(fa[tu][i]==fa[tv][i])
			continue;
		tu=fa[tu][i];
		tv=fa[tv][i];
	}
	return fa[tu][0];
}
bool flag[maxn];
int main(){
	int T; cin>>T;
	int n,u,v;
	while(T--){
		cin>>n; init();
		memset(flag,false,sizeof flag);
		for(int i=1; i<n; i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);addedge(v,u);
			flag[v]=true;
		}
		int root;
		for(int i=1; i<=n; i++)
			if(!flag[i]){
				root=i;
				break;
			}
		BFS(root);
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
