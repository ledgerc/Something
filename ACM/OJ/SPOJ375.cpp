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
#include<bitset>
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
const int maxn = 3e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


int T,n,q;

int ch[maxn][2],pre[maxn],key[maxn];
int add[maxn],rev[maxn],Max[maxn];
bool rt[maxn];

void push_up(int r){
	Max[r]=max(max(Max[ch[r][0]],Max[ch[r][1]]),key[r]);
}
void Rotate(int x){
	int y=pre[x],kind=ch[y][1]==x;
	ch[y][kind]=ch[x][!kind];
	pre[ch[y][kind]]=y;
	pre[x]=pre[y];
	pre[y]=x;
	ch[x][!kind]=y;
	if(rt[y])
		rt[y]=false,rt[x]=true;
	else
		ch[pre[x]][ch[pre[x]][1]==y]=x;
	push_up(y);
}
//P函数先将根结点到r的路径上所有的结点的标记逐级下放
 void Splay(int r){
 	//P(r);
	while(!rt[r]){
		int f=pre[r],ff=pre[f];
		if(rt[f])
			Rotate(r);
		else if( (ch[ff][1]==f)==(ch[f][1]==r) )
			Rotate(f),Rotate(r);
		else
			Rotate(r),Rotate(r);
	}
	push_up(r);
}
int Access(int x){
	int y=0;
	for(; x; x=pre[y=x]){
		Splay(x);
		rt[ch[x][1]]=true,rt[ch[x][1]=y]=false;
		push_up(x);
	}
	return y;
}
//判断是否是同根(真实的树，非splay)
bool judge(int u,int v){
	while(pre[u])
		u=pre[u];
	while(pre[v])
		v=pre[v];
	return u==v;
}
//调用后u是原来u和v的lca,v和ch[u][1]分别存着lca的2个儿子
//(原来u和v所在的2颗子树)
void lca(int &u,int &v){
	Access(v),v=0;
	while(u){
		Splay(u);
		if(!pre[u])
			return;
		rt[ch[u][1]]=true;
		rt[ch[u][1]=v]=false;
		push_up(u);
		u=pre[v=u];
	}
}
//query(a,b): 如果a,b在同一颗子树中，返回a,b之间路径上点权的最大值 
void query(int u,int v){
	lca(u,v);
	printf("%d\n",max(max(Max[v],Max[ch[u][1]]),key[u]));
	//边权：printf("%d\n",max(Max[v],Max[ch[u][1]]));
}
//修改点权 
void change(int u,int k){
	Access(u);
	key[u]=k;
	push_up(u);
}

struct Edge{
	int to,next;
	int val,index;
}edge[maxn*2];
int head[maxn],tot;
int id[maxn];
void addedge(int u,int v,int val,int index){
	edge[tot].to=v; edge[tot].next=head[u];
	edge[tot].val=val; edge[tot].index=index;
	head[u]=tot++;
}
void dfs(int u){
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(pre[v]!=0)
			continue;
		pre[v]=u;
		id[edge[i].index]=v;
		key[v]=edge[i].val;
		dfs(v);
	}
}

void init(){
	tot=0;
	memset(head,-1,sizeof head);
	for(int i=0; i<=n; i++){
		pre[i]=0;
		ch[i][0]=ch[i][1]=0;
		rev[i]=0;
		add[i]=0;
		rt[i]=true;
	}
	Max[0]=-inf;
}
int main(){
	int u,v,w;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1; i<n; i++){
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w,i);
			addedge(v,u,w,i);
		}
		pre[1]=-1;
		dfs(1);
		pre[1]=0;
		char op[20];
		while(scanf("%s",op)!=EOF){
			if(op[0]=='D')
				break;
			scanf("%d%d",&u,&v);
			if(op[0]=='C')
				change(id[u],v);
			else
				query(u,v);
		}
	}
}
