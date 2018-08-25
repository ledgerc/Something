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

//Ⱦɫ�������Եõ��ֵ�����С�Ľ⣩ 
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
bool vis[maxn];//Ⱦɫ��ǣ�Ϊtrue��ʾѡ��
int S[maxn],top;//ջ 
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




// ǿ��ͨ���㷨����������ֻ�ܵõ�����⣩
struct Edge{
	int to,next;
}edge[maxm];
int head[maxn],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u]; head[u]=tot++;
}
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];//Belong�����ֵ1~scc
int Index,top;
int scc;
bool Instack[maxn];
int num[maxn];
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
		}while(v!=u);
	}
}
bool solvable(int n){//n���ܸ���,��Ҫѡ��һ��
	memset(DFN,0,sizeof DFN);
	memset(Instack,false,sizeof Instack);
	memset(num,0,sizeof num);
	Index=scc=top=0;
	for(int i=0; i<n; i++)
		if(!DFN[i])
			Tarjan(i);
	for(int i=0; i<n; i+=2)
		if(Belong[i]==Belong[i^1])
			return false;
	return true;
}
//��������������һ��ⲿ�� 
queue<int> q1,q2;
vector< vector<int> > dag;//����������DAGͼ
char color[maxn];//Ⱦɫ��Ϊ'R'��ѡ���
int indeg[maxn];//���
int cf[maxn];
void solve(int n){
	dag.assign(scc+1,vector<int>());
	memset(indeg,0,sizeof indeg);
	memset(color,0,sizeof color);
	for(int u=0; u<n; u++)
		for(int i=head[u]; i!=-1; i=edge[i].next){
			int v=edge[i].to;
			if(Belong[u]!=Belong[v]){
				dag[Belong[v]].push_back(Belong[u]);
				indeg[Belong[u]]++;
			}
		}
	for(int i=0; i<n; i+=2){
		cf[Belong[i]]=Belong[i^1];
		cf[Belong[i^1]]=Belong[i];
	}
	while(!q1.empty())
		q1.pop();
	while(!q2.empty())
		q2.pop();
	for(int i=1; i<=scc; i++)
		if(indeg[i]==0)
			q1.push(i);
	while(!q1.empty()){
		 int u=q1.front();
		 q1.pop();
		 if(color[u]==0){
		 	color[u]='R';
			color[cf[u]]='B';
		}
		int sz=dag[u].size();
		for(int i=0; i<sz; i++){
			indeg[dag[u][i]]--;
			if(indeg[dag[u][i]]==0)
				q1.push(dag[u][i]);
		}
	}
}
int change(char s[]){
	int ret=0;
	int i=0;
	while(s[i]>='0'&&s[i]<='9'){
		ret*=10;
		ret+=s[i]-'0';
		i++;
	}
	if(s[i]=='w')
		return 2*ret;
	else
		return 2*ret+1;
}
int main(){
	int n,m;
	char s1[10],s2[10];
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
			break;
		init();
		while(m--){
			scanf("%s%s",s1,s2);
			int u=change(s1);
			int v=change(s2);
			addedge(u^1,v);
			addedge(v^1,u);
		}
		addedge(1,0);
		if(solvable(2*n)){
			solve(2*n);
			for(int i=1; i<n; i++){
				//ע����һ�����ж�color[Belong[
				if(color[Belong[2*i]] == 'R')
					printf("%dw",i);
				else
					printf("%dh",i);
				if(i<n-1)
					printf(" ");
				else
					printf("\n");
			}
		}
		else
			printf("bad luck\n");
	}
	return 0;
}





//Korasaju POJ3207
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
const int maxm = 1e6+7;
const double pi = acos(-1.0);


vector<vector<int> > adj;//ԭͼ 
vector<vector<int> > radj;//��ͼ 
vector<vector<int> > dag;//����������DAGͼ 
int n,cnt;
int id[maxn],st[maxn],ind[maxn];//ǿ��ͨ���� ����˳�� ��� 
bool vis[maxn];

void dfs(int u){
    vis[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    	if(!vis[adj[u][i]])
    		dfs(adj[u][i]);
    st[cnt++]=u;
}
void rdfs(int u){
    vis[u]=true;
    id[u]=cnt;
    for(int i=0; i<radj[u].size(); i++)
		if(!vis[radj[u][i]])
    		rdfs(radj[u][i]);
}
void korasaju(){
    int i;
    memset(vis,false,sizeof(vis));
    for(cnt=0,i=0; i<2*n; i++)
    	if(!vis[i])
			dfs(i);
    memset(id,0,sizeof(id));
    memset(vis,false,sizeof(vis));
    for(cnt=0,i=2*n-1;i>=0;i--)
    	if(!vis[st[i]]){
        	cnt++;
    		rdfs(st[i]);
    	}
}
bool solvable(){
	for(int i=0; i<n; i++)
		if(id[2*i]==id[2*i+1])
			return false;
	return true;
}
struct Node{
	int s,t;
}node[maxn];
int main(){
	int N;
	while(scanf("%d%d",&N,&n)!=EOF){
		int u,v;
		for(int i=0; i<n; i++){
			scanf("%d%d",&u,&v);
			if(u>v)
				swap(u,v);
			node[i].s=u; node[i].t=v;
		}
        adj.assign(2*n,vector<int>());
        radj.assign(2*n,vector<int>());
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++){
				if((node[i].s<node[j].s&&node[j].s<node[i].t&&node[i].t<node[j].t)
				||(node[j].s<node[i].s&&node[i].s<node[j].t&&node[j].t<node[i].t)){
					adj[2*i].push_back(2*j+1);
                	adj[2*j+1].push_back(2*i);
                	adj[2*i+1].push_back(2*j);
                	adj[2*j].push_back(2*i+1);
                	radj[2*j+1].push_back(2*i);
                	radj[2*i].push_back(2*j+1);
                	radj[2*j].push_back(2*i+1);
                	radj[2*i+1].push_back(2*j);
				}
			}
		korasaju();
		if(solvable())
			printf("panda is telling the truth...\n");
		else
			printf("the evil panda is lying again\n");
	}
	return 0;
}





//korasaju
