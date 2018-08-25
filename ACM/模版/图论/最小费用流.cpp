//最小费用最大流，求最大费用只需要取相反数，结果取相反数即可。
//点的总数为 N，点的编号 0~N-1
struct Edge{
	int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
int dis[maxn];//double???
bool vis[maxn];
int N;
void init(int n){
	N=n;
	tol=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v,int cap,int cost){
	edge[tol].to=v; edge[tol].cap=cap; edge[tol].cost=cost; edge[tol].flow=0;
	edge[tol].next=head[u]; head[u]=tol++;
	edge[tol].to=u;	edge[tol].cap=0; edge[tol].cost=-cost;	edge[tol].flow=0;
	edge[tol].next=head[v];	head[v]=tol++;
}
bool spfa(int s,int t){
	queue<int> q;
	for(int i=0; i<=N; i++){
		dis[i]=inf;
		vis[i]=false;
		pre[i]=-1;
	}
	dis[s]=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=false;
		for(int i=head[u]; i!=-1; i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
				dis[v]=dis[u]+edge[i].cost;
				pre[v]=i;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			} 
		}
	}
	if(pre[t]==-1)
		return false;
	else
		return true;
}
//返回的是最大流，cost存的是最小费
int MincostMaxflow(int s,int t,int &cost){
	int flow=0;
	cost=0;
	while(spfa(s,t)){
		int Min=inf;
		for(int i=pre[t]; i!=-1; i=pre[edge[i^1].to]){
		 	if(Min>edge[i].cap-edge[i].flow)
				Min=edge[i].cap-edge[i].flow;
		}
		for(int i=pre[t]; i!=-1; i=pre[edge[i^1].to]){
			edge[i].flow+=Min;
			edge[i^1].flow-=Min;
			cost+=edge[i].cost*Min;
		}
		flow+=Min;
	}
	return flow;
}



struct Edge{
    int from,to,cap,flow;
    double cost;
    Edge(){}
    Edge(int f,int t,int c,int fl,double co):from(f),to(t),cap(c),flow(fl),cost(co){}
};
struct MCMF{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> g[maxn];
    bool inq[maxn];
    double d[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n,int s,int t){
        this->n=n;
        this->s=s;
        this->t=t;
        edges.clear();
        for(int i = 0;i<=n;i++) g[i].clear();
    }
    void addedge(int from,int to,int cap,double cost){
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    bool BellmanFord(int &flow,double &cost){
        for(int i=0; i<=n; i++) d[i]=inf;
        memset(inq,0,sizeof(inq));
        d[s]=0,a[s]=inf,inq[s]=1,p[s]=0;
        queue<int> q; q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            inq[u]=0;
            for(int i=0; i<g[u].size(); i++){
                Edge &e=edges[g[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost+eps){//松弛eps 防止T 
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=g[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){
                        q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==inf) return false;
        flow+=a[t];
        cost+=a[t]*d[t];
        int u = t;
        while(u!=s){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }
    double MincostMaxflow(int &flow,double &cost){
        flow=0,cost=0;
        while(BellmanFord(flow,cost));
        return cost;
    }
}mc;
