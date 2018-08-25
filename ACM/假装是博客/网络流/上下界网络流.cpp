//
struct Dinic{
	struct Edge{
		int to,next,cap;
	}edge[maxn*maxn];
	int tot,head[maxn],dist[maxn],s,t;
	//bool vis[maxn];//≈–∂œ «∑Ò—°÷– 
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
int down[maxn*maxn];
int cnt[maxn];
int main(){
	int T;cin>>T;
	while(T--){
		int n,m,s,t; scanf("%d%d",&n,&m); s=0,t=n+1;
		memset(cnt,0,sizeof cnt); dinic.init(s,t);
		for(int i=0; i<m; i++){
			int u,v,up; scanf("%d%d%d%d",&u,&v,&down[i],&up);
			dinic.addedge(u,v,up-down[i]);
			cnt[u]+=down[i]; cnt[v]-=down[i];
		}
		int sum=0;
		for(int i=1; i<=n; i++){
			if(cnt[i]>0){
				sum+=cnt[i];
				dinic.addedge(i,t,cnt[i]);
			}
			else if(cnt[i]<0)
				dinic.addedge(s,i,-cnt[i]);
		}
		if(sum==dinic.max_flow()){
			puts("YES");
			for(int i=0; i<m; i++){
				printf("%d\n",down[i]+dinic.edge[(2*i^1)].cap);
			}
			puts("");
		}
		else
			puts("NO\n");
	}
}
