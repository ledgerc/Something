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
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


//Dinic
struct Dinic{
	struct Edge{
		int to,next,cap;
	}edge[maxn*maxn];
	int tot,head[maxn],dist[maxn],s,t;
	bool vis[maxn];
	void init(int ss,int tt){
		s=ss; t=tt;
		tot=0;
		memset(head,-1,sizeof head);
	}
	void addedge(int u,int v,int w){
		edge[tot]=(Edge){v,head[u],w};
		head[u]=tot++;
		edge[tot]=(Edge){u,head[v],0};
		head[v]=tot++;
	}
	bool bfs(){
		queue<int> que;
		que.push(s);
		memset(dist,-1,sizeof dist);
		memset(vis,false,sizeof vis);
		dist[s]=0;
		while(!que.empty()){
			int u=que.front(); que.pop();
			for(int i=head[u]; i!=-1; i=edge[i].next){
				if(dist[edge[i].to]==-1&&edge[i].cap>0){
					dist[edge[i].to]=dist[u]+1;
					vis[edge[i].to]=true;
					que.push(edge[i].to);
				}
			}
		}
		return dist[t]!=-1;
	}
	int dfs(int start, int curFlow){
        if(start==t)
            return curFlow;
        int i,minFlow=0,v,temp;
        for(i=head[start]; i!=-1; i=edge[i].next){
            v=edge[i].to;
            if(dist[start]==dist[v]-1&&edge[i].cap > 0){
                temp=dfs(v,min(edge[i].cap,curFlow));
                edge[i].cap-=temp;
                edge[i^1].cap+=temp;
                curFlow-=temp;
                minFlow+=temp;
                if(0==curFlow)
                    break;
            }
        }
        if(0==minFlow)
            dist[start]=-2;
        return minFlow;
    }
    int max_flow(){
        int res=0;
        while(bfs()){
            res+=dfs(s,inf);
        }
        return res;
    }
}dinic;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	dinic.init(0,n+m+1);
	int sum=0;
	for(int i=1; i<=n; i++){
		int tmp; scanf("%d",&tmp); sum+=tmp;
		dinic.addedge(0,i,tmp);
		char ch=getchar();
		while((ch=getchar())!='\n'){
			tmp = ch-'0';
			while((ch=getchar())&&ch>='0'&&ch<='9')
				tmp = tmp*10+ch-'0';
			dinic.addedge(i,tmp+n,inf);
			if(ch=='\n')
				break;
		}
	}
	for(int i=1; i<=m; i++){
		int tmp; scanf("%d",&tmp);
		dinic.addedge(n+i,n+m+1,tmp);
	}
	int ans = dinic.max_flow();
	vector<int> vec;
	for(int i=1; i<=n; i++){
		if(dinic.vis[i])
			vec.push_back(i);
	}
	for(int i=0; i<vec.size(); i++)
		printf("%d ",vec[i]);
	printf("\n");
	vec.clear();
	for(int i=1; i<=m; i++)
		if(dinic.vis[n+i])
			vec.push_back(i+n);
	for(int i=0; i<vec.size(); i++)
		printf("%d ",vec[i]-n);
	printf("\n%d\n",sum-ans);
	return 0;
}
