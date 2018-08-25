//Dijkstra ��Դ���·���ڽӾ�����ʽ
//Ȩֵ����Ǹ�
const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int cost[maxn][maxn];//��ʾ��u,v��Ȩֵ 
int d[maxn];//�ӵ�s��������̾��� 
bool used[maxn];
int v;//������ 
void dijkstra(int s){
	fill(d,d+v,INF);
	fill(used,used+V,false);
	d[s]=0;
	while(true){
		int v=-1;
		//����δʹ�õĶ�����ѡ��һ��������С�Ķ��� 
		for(int u=0; u<v; u++){
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		}
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0; u<v; u++){
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
}

//�� 
struct qnode{
	int v; ll c;
	qnode(int _v=0,ll _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;
	}
}; 
struct Edge{
	int v; ll cost;
	Edge(int _v=0,ll _cost=0):v(_v),cost(_cost){}
};
vector<Edge>e[maxn];
void addedge(int u,int v,ll w){
	e[u].push_back(Edge(v,w));
}
bool vis[maxn];
ll dist[maxn];
void Dijkstra(int n,int start){
	memset(vis,false,sizeof(vis));
	for(int i=0;i<=n;i++)
		dist[i]=INF;
	priority_queue<qnode>que;
	while(!que.empty()) que.pop();
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
		for(int i=0; i<e[u].size(); i++){
			int v=e[tmp.v][i].v;
			ll cost=e[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
