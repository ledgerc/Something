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
const int maxn = 1e3+7;
const int maxm = 5e5+7;
const double pi = acos(-1.0);

/*
* POJ 1470
* 给出一颗有向树，Q个查询
* 输出查询结果中每个点出现次数
*/
/*
* LCA离线算法，Tarjan
*复杂度O(n+Q);
*/
//
int F[maxn];
int find(int x){
	if(F[x]==-1)
		return x;
	return F[x]=find(F[x]);
}
void unite(int u,int v){
	int tmp1=find(u),tmp2=find(v);
	if(tmp1!=tmp2);
		F[tmp1]=tmp2;
}

bool vis[maxn];
int ancestor[maxn];
struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}

struct Query{
	int q,next;
	int index;
}query[maxm*2];
int answer[maxm];
int h[maxm];
int tt,Q;

void addquery(int u,int v,int index){
	query[tt].q=v;
	query[tt].next=h[u];
	query[tt].index=index;
	h[u]=tt++;
	query[tt].q=u;
	query[tt].next=h[v];
	query[tt].index=index;
	h[v]=tt++;
}
void init(){
	tot=0;
	memset(head,-1,sizeof head);
	tt=0;
	memset(h,-1,sizeof h);
	memset(vis,false,sizeof vis);
	memset(F,-1,sizeof F);
	memset(ancestor,0,sizeof ancestor);
}

void LCA(int u){
	ancestor[u]=u;
	vis[u]=true;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(vis[v])
			continue;
		LCA(v);
		unite(u,v);
		ancestor[find(u)]=u;
	}
	for(int i=h[u]; i!=-1; i=query[i].next){
		int v=query[i].q;
		if(vis[u])
			answer[query[i].index]=ancestor[find(v)];
	}
}

bool flag[maxn];
int Count_num[maxn];
int main(){
	int n; int u,v,k;
	while(scanf("%d",&n)!=EOF){
		init();
		memset(flag,false,sizeof flag);
		for(int i=1; i<=n; i++){
			scanf("%d:(%d)",&u,&k);
			while(k--){
				scanf("%d",&v);
				flag[v] = true;
				addedge(u,v);
				addedge(v,u);
			}
		}
		cin>>Q;
		for(int i=0; i<Q; i++){
			char c; cin>>c;
			scanf("%d %d)",&u,&v);
			addquery(u,v,i);
		}
		int root;
		for(int i=1; i<=n; i++)
			if(!flag[i]){
				root=i;
				break;
			}
		LCA(root);
		memset(Count_num,0,sizeof Count_num);
		for(int i = 0;i < Q;i++)
			Count_num[answer[i]]++;
		for(int i = 1;i <= n;i++)
			if(Count_num[i] > 0)
				printf("%d:%d\n",i,Count_num[i]);
	}
	return 0;
}
