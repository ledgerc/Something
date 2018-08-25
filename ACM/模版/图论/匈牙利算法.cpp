/* �ڽӾ����������㷨��

*********************************************************** 
//����ͼƥ�䣨�������㷨��DFSʵ�֣�(�ڽӾ�����ʽ) 
//��ʼ����g[][]���߶���Ļ������ 
//����g[i][j]��ʾi->j������߾Ϳ����ˣ���������ұߵ�ƥ�� 
//gû�б��������ʼ��Ϊ0 
//uN��ƥ����ߵĶ�������vN��ƥ���ұߵĶ����� 
//���ã�res=hungary();������ƥ���� 
//�ŵ㣺�����ڳ���ͼ��DFS������·��ʵ�ּ��������� 
//ʱ�临�Ӷ�:O(VE) 
//*************************************************************/ 
//�����Ŵ�0��ʼ��

int uN,vN;//u,v����Ŀ��ʹ��ǰ����븳ֵ
int g[maxn][maxn];//�ڽӾ���
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
 �ڽӱ��������㷨�� 
* �������㷨�ڽӱ���ʽ  
* ʹ��ǰ��init()���г�ʼ������uN��ֵ  
* �ӱ�ʹ�ú���addedge(u,v)
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


//����ͼ����ƥ��
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
