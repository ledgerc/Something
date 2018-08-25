/* 邻接矩阵（匈牙利算法）

*********************************************************** 
//二分图匹配（匈牙利算法的DFS实现）(邻接矩阵形式) 
//初始化：g[][]两边顶点的划分情况 
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配 
//g没有边相连则初始化为0 
//uN是匹配左边的顶点数，vN是匹配右边的顶点数 
//调用：res=hungary();输出最大匹配数 
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解 
//时间复杂度:O(VE) 
//*************************************************************/ 
//顶点编号从0开始的

int uN,vN;//u,v的数目，使用前面必须赋值
int g[maxn][maxn];//邻接矩阵
int linker[maxn];
bool used[maxn];
bool dfs(int u){
	for(int v=0; v<vN; v++)
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	return false;
}
int hungary(){
	int res=0;
	memset(linker,-1,sizeof linker);
	for(int u=0; u<uN; u++){
		memset(used,false,sizeof used);
		if(dfs(u))
			res++;
	}
	return res;
}








/*
 邻接表（匈牙利算法） 
* 匈牙利算法邻接表形式  
* 使用前用init()进行初始化，给uN赋值  
* 加边使用函数addedge(u,v)
*/

struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],tot;
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;edge[tot].next=head[u];
	head[u]=tot++;
}
int linker[maxn];
bool used[maxn];
int uN;
bool dfs(int u){
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(!used[v]){
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}
int hungary(){
	int res=0;
	memset(linker,-1,sizeof linker);
	for(int u=0; u<uN; u++){
		memset(used,false,sizeof used);
		if(dfs(u))
			res++;
	}
	return res;
}


//二分图多重匹配
const int MAXN = 1010;
const int MAXM = 510;
int uN,vN;
int g[maxn][maxm];
int linker[maxm][maxn];
bool used[maxm];
int num[maxm];//
bool dfs(int u){
	for(int v=0; v<vN; v++){
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v][0]<num[v]){
				linker[v][++linker[v][0]]=u;
				return true;
			}
			for(int i=1; i<=num[0]; i++)
				if(dfs(linker[v][i])){
					linker[v][i]=u;
					return true;
				}
		}
	}
	return false;
}
int hungary(){
	int res=0;
	for(int i=0; i<vN; i++)
		linker[i][0]=0;
	for(int u=0; u<uN; u++){
		memset(used,false,sizeof used);
		if(dfs(u))
			res++;
	}
	return res;
}
