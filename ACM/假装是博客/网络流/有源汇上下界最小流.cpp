struct Dinic{
	struct Edge{
		int to,next;
		ll cap;
		bool mark;
	}edge[maxm];
	int tot,head[maxm],dist[maxn],s,t;
	//bool vis[maxn];//≈–∂œ «∑Ò—°÷– 
	void init(int ss,int tt){
		s=ss; t=tt;
		tot=0;
		memset(head,-1,sizeof head);
	}
	void addedge(int u,int v,int w,bool flag){
		edge[tot]=(Edge){v,head[u],w,flag};
		head[u]=tot++;
		edge[tot]=(Edge){u,head[v],0,flag};
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
	ll dfs(int start,ll curFlow){
        if(start==t)
            return curFlow;
        ll i,minFlow=0,v,temp;
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
    ll max_flow(){
        ll res=0;
        while(bfs()){
            res+=dfs(s,inf);
        }
        return res;
    }
}dinic;
ll cnt[maxn];
int main(){
//	freopen("in.txt","r",stdin);
	int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t);
	int ss=0,tt=n+1; dinic.init(ss,tt); memset(cnt,0,sizeof cnt);
	for(int i=1; i<=m; i++){
		int u,v; ll down,up; scanf("%d%d%lld%lld",&u,&v,&down,&up);
		dinic.addedge(u,v,up-down,1);
		cnt[u]+=down; cnt[v]-=down;
	}
	ll sum=0;
	for(int i=1; i<=n; i++){
		if(cnt[i]>0){
			sum+=cnt[i];
			dinic.addedge(i,tt,cnt[i],0);
		}
		else
			dinic.addedge(ss,i,-cnt[i],0);
	}
	ll ans=0;
	ans+=dinic.max_flow();
	dinic.addedge(t,s,inf,0);
	ans+=dinic.max_flow();
	if(sum==ans){
		printf("%lld\n",dinic.edge[dinic.head[t]^1].cap);
	}
	else
		puts("please go home to sleep");
}
