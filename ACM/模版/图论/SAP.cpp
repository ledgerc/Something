//SAP �ڽӾ�����ʽ1

/*
*SAP�㷨(������ʽ) 
*����Ŵ�0��ʼ 
*/
const int MAXN=1100;
int maze[MAXN][MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int sap(int start,int end,int nodenum){
	memset(cur,0,sizeof cur);
	memset(dis,0,sizeof dis);
	memset(gap,0,sizeof gap);
	int u=pre[start]=start,maxflow=0,aug=-1;
	gap[0]=nodenum;
	while(dis[start]<nodenum){
		loop:
			for(int v=cur[v]; v<nodenum; v++)
				if(maze[u][v]&&dis[u]==dis[v]+1){
					if(aug==-1||aug>maze[u][v])
						aug=maze[u][v];
					pre[v]=u;
					u=cur[u]=v;
					if(v==end){
						maxflow+=aug;
						for(u=pre[u]; v!=start; v=u,u=pre[u]){
							maze[u][v]-=aug;
							maze[v][u]+=aug;
						}
						aug=-1;
					}
					goto loop;
				}
		int mindis=nodenum-1;
		for(int v=0; v<nodenum; v++)
			if(maze[u][v]&&mindis>dis[v]){
				cur[u]=v;
				mindis=dis[v];
			}
		if((--gap[dis[u]])==0)
			break;
		gap[dis[u]=mindis+1]++;
		u=pre[u];
	}
	return maxflow;
}

// SAP��Ӿ�����ʽ2
/*
* SAP��Ӿ�����ʽ 
* ��ı�Ŵ�0��ʼ 
* ���Ӹ�flow���飬����ԭ����maze�������ڶ��ʹ�������
*/ 
const int MAXN=1100;
int maze[MAXN][MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int flow[MAXN][MAXN];
int sap(int start,int end,int nodenum){
	memset(cur,0,sizeof(cur));
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	memset(flow,0,sizeof(flow));
	int u=pre[start]=start,maxflow=0,aug=-1;
	gap[0]=nodenum;
	while(dis[start]<nodenum){
		loop:
		for(int v=cur[u];v<nodenum;v++)
			if(maze[u][v]-flow[u][v]&&dis[u]==dis[v]+1){
				if(aug==-1||aug>maze[u][v]-flow[u][v])
					aug=maze[u][v]-flow[u][v];
				pre[v]=u;
				u=cur[u]=v;
				if(v==end){
					maxflow+=aug;
					for(u=pre[u];v!=start;v=u,u=pre[u]){
						flow[u][v]+=aug;
						flow[v][u]-=aug;
					}
					aug=-1;
				}
				goto loop;
			}
		int mindis=nodenum-1;
		for(int v=0;v<nodenum;v++)
			if(maze[u][v]-flow[u][v]&&mindis>dis[v]){
				cur[u]=v;
				mindis=dis[v];
			}
		if((--gap[dis[u]])==0)
			break;
		gap[dis[u]=mindis+1]++;
		u=pre[u]; 
	}
	return maxflow;
}
