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
const int maxn = 1e4+7;
const int maxm = 1e5+7;
const double pi = acos(-1.0);

int T,n,m;
struct Edge{
	int to,next;
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];//Belong数组的值是1~scc 
int Index,top;
int scc;//强连通分量的个数 
bool Instack[maxn];
int num[maxn];//各个强连通分量包含点的个数，数组编号1~scc 不一定需要 
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void Tarjan(int u){
	int v;
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=true;
	for(int i=head[u]; i!=-1; i=edge[i].next){
		v=edge[i].to;
		if(!DFN[v]){
			Tarjan(v);
			if(Low[u]>Low[v])
				Low[u]=Low[v]; 
		}
		else if(Instack[v]&&Low[u]>DFN[v])
			Low[u]=DFN[v];
	}
	if(Low[u]==DFN[u]){
		scc++;
		do{
			v=Stack[--top];
			Instack[v]=false;
			Belong[v]=scc;
			num[scc]++;
		}
		while(v!=u);
	}
}
void solve(int N){
	memset(DFN,0,sizeof DFN);
	memset(Instack,false,sizeof Instack);
	memset(num,0,sizeof num);
	Index=scc=top=0;
	for(int i=1; i<=N; i++)
		if(!DFN[i])
			Tarjan(i);
}
vector<int> e[maxn];
int in[maxn];
int cnt[maxn],cnt2[maxn];
bool vis[maxn];
vector<int> ans;
void init(int n){
	tot=0;
	memset(head,-1,sizeof head);
	memset(in,0,sizeof in);
	memset(cnt,0,sizeof cnt);
	memset(cnt2,0,sizeof cnt2);
	memset(vis,false,sizeof vis);
	for(int i=0; i<=n; i++)
		e[i].clear();
	ans.clear();
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=0; i<m; i++){
			int u,v; scanf("%d%d",&u,&v);
			addedge(u+1,v+1);
		}
		solve(n);
		for(int u=1; u<=n; u++){
			cnt[Belong[u]]++; cnt2[Belong[u]]=cnt[Belong[u]];
			for(int i=head[u]; i!=-1; i=edge[i].next){
				int v=edge[i].to;
				if(Belong[u]!=Belong[v]){
					e[Belong[u]].push_back(Belong[v]);
					in[Belong[v]]++;
				}
			}
		}
		vector<int> tmp;
		for(int i=1; i<=scc; i++)
			if(in[i]==0)
				tmp.push_back(i);
		for(int i=0; i<tmp.size(); i++){
			vis[tmp[i]]=true;
			for(int j=0; j<e[tmp[i]].size(); i++){
				int v=e[tmp[i]][j]; in[v]--;
				if(in[v]==0&&!vis[v])
					tmp.push_back(v);
				cnt[v]+=cnt[i];
			}
		}
		/*
		cout<<"cnt: ";
		for(int i=1; i<=scc; i++)
			cout<<cnt[i]<<" ";
		cout<<endl;
		cout<<"cnt2: ";
		for(int i=1; i<=scc; i++)
			cout<<cnt2[i]<<" ";
		cout<<endl;
		*/
		int mx=-1;
		for(int i=1; i<=scc; i++)
			mx=max(mx,cnt[i]);
		printf("%d\n",mx-1);
		for(int i=1; i<=n; i++){
			if(cnt[Belong[i]]==mx)
				ans.push_back(i);
		}
		printf("%d",ans[0]-1);
		for(int i=1; i<ans.size(); i++)
			printf(" %d",ans[i]-1);
		cout<<endl;
	}
}
