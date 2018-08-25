int n,m,s,t,k;
struct qnode{
	int v,c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn],E2[maxn];
bool vis[maxn];
int dist[maxn];
void Dijkstra(int n,int start){//点的编号从1开始
	memset(vis,false,sizeof(vis));
	for(int i=1; i<=n; i++)
		dist[i]=inf;
	priority_queue<qnode>que;
	while(!que.empty())
		que.pop();
	dist[start]=0;
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty()){
		tmp=que.top();
		que.pop();
		int u=tmp.v;
		if(vis[u])
			continue;
		vis[u]=true;
		for(int i=0; i<E2[u].size(); i++){
			int v=E2[tmp.v][i].v;
			int cost=E2[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
	E2[v].push_back(Edge(u,w));
}

struct Node{
	int u;
	int h,g;
    Node(int u_,int h_,int g_){u=u_,h=h_,g=g_;}
    bool operator<(Node a)const{
        return h+g>a.h+a.g;
    }
};
int cnt[maxn];
int Astar(int s,int t,int k){
	priority_queue<Node>que;
	while(!que.empty())
		que.pop();
	memset(cnt,0,sizeof cnt);
	if(s==t)
		k++;
	que.push(Node(s,0,dist[s]));
	while(!que.empty()){
		Node u = que.top(); que.pop();
		cnt[u.u]++;
		if(cnt[u.u]==k&&u.u==t)
			return u.h;
		if(cnt[u.u]>k)
			continue;
		for(int i=0; i<E[u.u].size(); i++){
			int v=E[u.u][i].v;int w=E[u.u][i].cost;
			que.push(Node(v,u.h+w,dist[v]));
		}
	}
	return -1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0; i<=n; i++){
			E[i].clear();
			E2[i].clear();
		}
		for(int i=0; i<m; i++){
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		scanf("%d%d%d",&s,&t,&k);
		Dijkstra(n,t);
		printf("%d\n",Astar(s,t,k));
	}
	return 0;
}




int head[MAXN],head1[MAXN];
LL dis[MAXN];
bool vis[MAXN];
int n,m,tot,st,en,k;
struct Edge{
    int u,v,nxt,nxt1;
    LL c;
    Edge(){}
    Edge(int _u,int _v,LL _c):u(_u),v(_v),c(_c){}
}e[MAXN*2];
struct qnode{
    int v;
    LL c;
    qnode(){}
    qnode(int _v,LL _c):v(_v),c(_c){}
    bool operator < (const qnode& rhs) const{
        return c+dis[v]>rhs.c+dis[rhs.v];
    }
};
void addedge(int u,int v,LL c){
    e[tot]=Edge(u,v,c);
    e[tot].nxt=head[u];head[u]=tot;
    e[tot].nxt1=head1[v];head1[v]=tot++;
}
void dij(int src){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) dis[i]=INF;
    dis[src]=0;
    priority_queue<qnode> que;
    que.push(qnode(src,0));
    while(!que.empty()){
        qnode pre=que.top(); que.pop();
        vis[pre.v]=true;
        for(int i=head1[pre.v];i!=-1;i=e[i].nxt1){
            if(dis[e[i].u]>dis[pre.v]+e[i].c){
                dis[e[i].u]=dis[pre.v]+e[i].c;
                que.push(qnode(e[i].u,0));
            }
        }
        while(!que.empty()&&vis[que.top().v]) que.pop();
    }
}
LL a_star(int src){
    priority_queue<qnode> que;
    que.push(qnode(src,0));
    k--;
    while(!que.empty()){
        qnode pre=que.top();que.pop();
        if(pre.v==en){
            if(k) k--;
            else return pre.c;
        }
        for(int i=head[pre.v];i!=-1;i=e[i].nxt)
            que.push(qnode(e[i].v,pre.c+e[i].c));
    }
    return -1;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        memset(head1,-1,sizeof(head1));
        tot=0;
        for(int i=0;i<m;i++){
            int u,v;LL c;
            scanf("%d%d%lld",&u,&v,&c);
            addedge(u,v,c); addedge(v,u,c);
        }
        st=1,en=n;k=2;
        dij(en);
        if(st==en) k++;
        printf("%lld\n",a_star(st));
    }
    return 0;
}
