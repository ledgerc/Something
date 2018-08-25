//从顶点from指向to的权值为cost的边 单源最短路 
struct edge{
	int from,to;
	int cost;
};
edge es[maxm];//边
int d[maxn];//最短距离 
int v,e;//v顶点数 e边数
void shortest_path(int s){
	for(int i=0; i<v; i++)
		d[i]=INF;
	d[s]=0;
	while(true){
		bool update = false;
		for(int i=0; i<e; i++){
			edge e=es[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update)
			break;
	}
}
