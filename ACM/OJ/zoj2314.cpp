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
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 3e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Dinic{
	struct Edge{
		int to,next,cap;
	}edge[maxn*maxn];
	int tot,head[maxn],dist[maxn],s,t;
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
		dist[s]=0;
		while(!que.empty()){
			int u=que.front(); que.pop();
			for(int i=head[u]; i!=-1; i=edge[i].next){
				if(dist[edge[i].to]==-1&&edge[i].cap>0){
					dist[edge[i].to]=dist[u]+1;
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
}G;
int nodeNum, edgeNum,
    cnt[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);

    int sum, i, j, test, u, v, down[maxn*maxn], up, s, t;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d", &nodeNum, &edgeNum);

        s = nodeNum + 1, t = nodeNum + 2;
        G.init(s, t);
        memset(cnt, 0, sizeof(cnt));

        for(i = 0; i < edgeNum; i++){
            scanf("%d%d%d%d", &u, &v, &down[i], &up);
            cnt[u] += down[i], cnt[v] -= down[i];
            G.addedge(u, v, up - down[i]);
        }

        sum = 0;
        for(i = 1; i <= nodeNum; i++){
            if(cnt[i] > 0){
                G.addedge(i, t, cnt[i]);
                sum += cnt[i];
            }
            else if(cnt[i] < 0)
                G.addedge(s, i, -cnt[i]);
        }

        if(sum == G.max_flow()){
            printf("YES\n");
            for(i = 0; i < edgeNum; i++)
                printf("%d\n", down[i] + G.edge[(2*i)^1].cap);
            printf("\n");
        }
        else
            printf("NO\n\n");
    }

    return 0;
}


