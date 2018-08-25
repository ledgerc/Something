struct Dinic{
	struct Edge{
		int to,next,cap;
		bool mark;
	}edge[maxn*maxn];
	int tot,head[maxn],dist[maxn],s,t;
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
        	int tmp  = dfs(s,inf);
            res+=tmp;
        }
        return res;
    }
}dinic;
int down[maxn*maxn];
int cnt[maxn];
int main(){
	int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t);
	int ss=0,tt=n+1;
	dinic.init(ss,tt); memset(cnt,0,sizeof cnt);
	for(int i=1; i<=m; i++){
		int u,v,up; scanf("%d%d%d%d",&u,&v,&down[i],&up);
		dinic.addedge(u,v,up-down[i],1);
		cnt[u]+=down[i]; cnt[v]-=down[i];
	}
	int sum=0;
	for(int i=1; i<=n; i++){
		if(cnt[i]>0){
			sum+=cnt[i];
			dinic.addedge(i,tt,cnt[i],0);
		}
		else if(cnt[i]<0)
			dinic.addedge(ss,i,-cnt[i],0);
	}
	dinic.addedge(t,s,inf,0);
	if(sum==dinic.max_flow()){
		int mx = dinic.edge[dinic.head[t]^1].cap;
		for(int i=0; i<dinic.tot; i++){
			if(!dinic.edge[i].mark){
				dinic.edge[i].to=0;
			}
		}
		dinic.s=s; dinic.t=t; dinic.head[ss]=-1; dinic.head[tt]=-1;
		printf("%d\n",mx+dinic.max_flow());
	}
	else
		puts("please go home to sleep");
	return 0;
}
/*
10 15 9 10
9 1 17 18
9 2 12 13
9 3 11 12
1 5 3 4
1 6 6 7
1 7 7 8
2 5 9 10
2 6 2 3
2 7 0 1
3 5 3 4
3 6 1 2
3 7 6 7
5 10 16 17
6 10 10 11
7 10 14 15
*/
