//�Ӷ���fromָ��to��ȨֵΪcost�ı� ��Դ���· 
struct edge{
	int from,to;
	int cost;
};
edge es[maxm];//��
int d[maxn];//��̾��� 
int v,e;//v������ e����
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
