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


int n,q;

int ch[maxn][2],pre[maxn],key[maxn];
int add[maxn],rev[maxn],Max[maxn],sum[maxn],size[maxn];
bool rt[maxn];
void Update_Add(int r,int d){
	if(!r)
		return ;
	key[r]+=d;
	add[r]+=d;
	Max[r]+=d;
	sum[r]+=d*size[r];
}
void Update_Rev(int r){
	if(!r)
		return;
	swap(ch[r][0],ch[r][1]);
	rev[r]^=1;
}
void push_down(int r){
	if(add[r]){
		Update_Add(ch[r][0],add[r]);
		Update_Add(ch[r][1],add[r]);
		add[r]=0;
	}
	if(rev[r]){
		Update_Rev(ch[r][0]);
		Update_Rev(ch[r][1]);
		rev[r]=0;
	}
}
void push_up(int r){
	if(!r)
		return ;
	Max[r]=key[r];
	sum[r]=key[r];
	size[r]=1;
	if(ch[r][0]){
		Max[r]=max(Max[r],Max[ch[r][0]]);
		sum[r]=sum[r]+sum[ch[r][0]];
		size[r]=size[r]+size[ch[r][0]];
	}
	if(ch[r][1]){
		Max[r]=max(Max[r],Max[ch[r][1]]);
		sum[r]=sum[r]+sum[ch[r][1]];
		size[r]=size[r]+size[ch[r][1]];
	}
//	Max[r]=max(max(Max[ch[r][0]],Max[ch[r][1]]),key[r]);
//	sum[r]=sum[ch[r][1]]+sum[ch[r][0]]+key[r];
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
void P(int r){
	if(!rt[r])
		P(pre[r]);
	push_down(r);
}
void Splay(int r){
 	P(r);
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
//使r成为它所在的树的根
void mroot(int r){
	Access(r);
	Splay(r);
	Update_Rev(r);
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
//link(a,b) : 如果a,b不在同一颗子树中
//则通过在a,b之间连边的方式，连接这两颗子树
void link(int u,int v){
	if(judge(u,v)){
		puts("no");
		return;
	}
	mroot(u);
	pre[u]=v;
	puts("yes");
}
//如果a,b在同一颗子树中，且a!=b
//则将a视为这颗子树的根以后，切断b与其父亲结点的连接
void cut(int u,int v){
	if(u==v||!judge(u,v)){
		puts("-1");
		return;
	}
	mroot(u);
	Splay(v);
	pre[ch[v][0]]=pre[v];
	pre[v]=0;
	rt[ch[v][0]]=true;
	ch[v][0]=0;
	push_up(v);
}
//ADD(a,b,w): 如果a,b在同一颗子树中，则将a,b之间路径上所有点的点权增加w
void ADD(int u,int v,int w){
	if(!judge(u,v)){
		puts("-1");
		return;
	}
	lca(u,v);
	Update_Add(ch[u][1],w);
	Update_Add(v,w);
	key[u]+=w;
	push_up(u);
}
//修改点权 
void change(int u,int k){
	Access(u);
	key[u]=k;
	push_up(u);
} 
//query(a,b): 如果a,b在同一颗子树中，返回a,b之间路径上点权的最大值 
void query(int u,int v){
	if(!judge(u,v)){
		puts("no");
		return;
	}
	lca(u,v);
	printf("%d\n",max(max(Max[v],Max[ch[u][1]]),key[u]));
	//点权：printf("%d\n",max(max(Max[v],Max[ch[u][1]]),key[u]));
	//边权：printf("%d\n",max(Max[v],Max[ch[u][1]]));
	//点权和： printf("%d\n",sum[v]+sum[ch[u][1]]+key[u]);
}
void querysum(int u,int v){
	if(!judge(u,v)){
		puts("impossible");
		return;
	}
	lca(u,v);
	printf("%d\n",sum[v]+sum[ch[u][1]]+key[u]);
}

struct Edge{
	int to,next;
}edge[maxn*2];
int head[maxn],tot;
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int u){
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(pre[v]!=0)
			continue;
		pre[v]=u;
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
		size[i]=1;
	}
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1; i<=n; i++){
		scanf("%d",&key[i]);
		Max[i]=sum[i]=key[i];	
	}
	Max[0]=-inf; size[0]=0;
	pre[1]=-1;
	dfs(1);
	pre[1]=0;
	scanf("%d",&q);
	char op[20]; int u,v;
	while(q--){
		scanf("%s%d%d",op,&u,&v);
		if(op[0]=='b'){
			link(u,v);
		}
		else if(op[0]=='p'){
			ADD(u,u,v-key[u]);
		}
		else
			querysum(u,v);
	}
	return 0;
}
