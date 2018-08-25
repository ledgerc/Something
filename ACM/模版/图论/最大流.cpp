//Ford-Flukerson
//用于表示边的结构体(终点、容量、反向边) 
struct edge{
	int to,cap,rev;
};
vector<edge> G[maxn];//图的领接表表示 
bool used[maxn];//DFS中用到的访问标记 
void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
//DFS寻找增广路 
int dfs(int v,int t,int f){
	if(v==t)
		return f;
	used[v]=true;
	for(int i=0; i<G[v].size(); i++){
		edge &e=G[v][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//求解s到t的最大流 
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		memset(used,0,sizeof used);
		int f=dfs(s,t,inf);
		if(f==0)
			return flow;
		flow+=f;
	}
}



//Dinic
//用于表示边的结构体(终点、容量、反向边) 
struct edge{
	int to,cap,rev;
};
vector<edge> G[maxn];//图的领接表表示
int level[maxn];//顶点到源点的距离标号
int iter[maxn];//当前弧，在其之前的边已经没有用了 
void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
//通过BFS计算从源点出发的距离标号 
void bfs(int s){
	memset(level,-1,sizeof level);
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front(); que.pop();
		for(int i=0; i<G[v].size(); i++){
			edge&e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
//通过DFS寻找增广路
int dfs(int v,int t,int f){
	if(v==t)
		return f;
	for(int &i=iter[v]; i<G[v].size(); i++){
		edge&e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//求解从s到t的最大流 
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)
			return flow;
		memset(iter,0,sizeof iter);
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}



//Dinic
struct Dinic{
	struct Edge{
		int to,next,cap;
	}edge[maxn*maxn];
	int tot,head[maxn],dist[maxn],s,t;
	//bool vis[maxn];//判断是否选中 
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
	//	memset(vis,false,sizeof vis);
		dist[s]=0;
		while(!que.empty()){
			int u=que.front(); que.pop();
			for(int i=head[u]; i!=-1; i=edge[i].next){
				if(dist[edge[i].to]==-1&&edge[i].cap>0){
					dist[edge[i].to]=dist[u]+1;
					//vis[edge[i].to]=true;
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





//Edmonds_Karp
//最大流模板
//初始化：g[][],start,end
int g[maxn][maxn];//存边的容量，没有边的初始化为0
int path[maxn],flow[maxn],start,end;
int n;//点的个数，编号0-n.n包括了源点和汇点。
queue<int> q;
int bfs(){
	int i,t;
	while(!q.empty())//把清空队列
		q.pop();
	memset(path,-1,sizeof path);//每次搜索前都把路径初始化成-1
	path[start]=0;
	flow[start]=inf;//源点可以有无穷的流流进
	q.push(start);
	while(!q.empty()){
		t=q.front(); q.pop();
		if(t==end)
			break;
		//枚举所有的点，如果点的编号起始点有变化可以改这里
		for(int i=0; i<=n; i++){
			if(i!=start&&path[i]==-1&&g[t][i]){
				flow[i]=flow[t]<g[t][i]?flow[t]:g[t][i];
				q.push(i);
				path[i]=t;
			}
		}
	}
	if(path[end]==-1)//即找不到汇点上去了。找不到增广路径了
		return -1;
	return flow[end];
}
int Edmonds_Karp(){
	int max_flow=0;
	int step,now,pre;
	while((step=bfs())!=-1){
		max_flow+=step;
		now=end;
		while(now!=start){
			pre=path[now];
			g[pre][now]-=step;
			g[now][pre]+=step;
			now=pre;
		}
	}
	return max_flow;
}
//------------------
 int g[maxn][maxn];
int flow[maxn][maxn];
int path[maxn];
int a[maxn];//a表示从源点到其他各点的最大流，在求出最大流之后，a>0 的就在源点集合中，反之为0的就在汇点集合中
int n;
int maxflow(){
	queue<int> q;
	memset(flow,0,sizeof flow);
	int max_flow=0;
	while(1){
		memset(a,0,sizeof a);
		a[1]=inf;
		while(!q.empty())
			q.pop();
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v=1; v<=n; v++)
				if(!a[v]&&flow[u][v]<g[u][v]){
					path[v]=u;
					a[v]=min(a[u],g[u][v]-flow[u][v]);
					q.push(v);
				}
		}
		if(a[2]==0)
			break;
		for(int u=2; u!=1; u=path[u]){
			flow[path[u]][u]+=a[2];
            flow[u][path[u]]-=a[2];
		}
		max_flow+=a[2];
	}
	return max_flow;
}

 
 
 
 
 
 
 
 
 
 
 //-------------
//ISAP 邻接表形式
const int MAXN = 100010;
const int MAXM = 400010;
const int INF = 0x3f3f3f3f;
struct Edge{
	int to,next,cap,flow;
}edge[MAXM];
int tot;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0){
	edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
	edge[tol].flow=0;head[u]=tol++;
	edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
	edge[tol].flow=0;head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N){
	memset(gap,0,sizeof gap);
	memset(dep,0,sizeof dep);
	memcpy(cur,head,sizeof head);
	int u=start;
	pre[u]=-1;
	gap[0]=N;
	int ans=0;
	while(dep[start]<N){
		if(u==end){
			int Min=INF;
			for(int i=pre[u]; i!=-1; i=pre[edge[i^1].to])
				if(Min>edge[i].cap-edge[i].flow)
					Min=edge[i].cap-edge[i].flow;
			for(int i=pre[u]; i!=-1; i=pre[edge[i^1].to]){
				edge[i].flow+=Min;
				edge[i^1].flow-=Min;
			}
			u=start;
			ans+=Min;
			continue;
		}
		bool flag=false;
		int v;
		for(int i=cur[u]; i!=-1; i=edge[i].next){
			v=edge[i].to;
			if(edge[i].cap-edge[i].flow&&dep[v]+1==dep[u]){
				flag=true;
				cur[u]=pre[v]=i;
				break;
			}
		}
		if(flag){
			u=v;
			continue;
		}
		int Min=N;
		for(int i=head[u]; i!=-1; i=edge[i].next)
			if(edge[i].cap-edge[i].flow&&dep[edge[i].to]<Min){
				Min=dep[edge[i].to];
				cur[u]=i;
			}
		gap[dep[u]]--;
		if(!gap[dep[u]])
			return ans;
		dep[u]=Min+1;
		gap[dep[u]]++;
		if(u!=start)
			u=edge[pre[u]^1].to;
	}
	return ans;
}
