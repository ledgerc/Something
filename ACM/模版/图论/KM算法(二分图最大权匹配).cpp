//Kuhn-Munkres 
/*  KM�㷨
*   ���Ӷ�O(nx*nx*ny)
*  �����Ȩƥ��
*   ������СȨƥ�䣬�ɽ�Ȩֵȡ�෴�������ȡ�෴��
*  ��ı�Ŵ�0��ʼ
*/
int nx,ny;
int g[maxn][maxn];
int linker[maxn],lx[maxn],ly[maxn];
int slack[maxn];
bool visx[maxn],visy[maxn];
bool DFS(int x){
 	visx[x]=true;
 	for(int y=0; y<ny; y++){
		if(visy[y])
			continue;
		int tmp=lx[x]+ly[y]-g[x][y];
		if(tmp==0){
			visy[y]=true;
			if(linker[y]==-1||DFS(linker[y])){
				linker[y]=x;
				return true;
			}
		}
		else if(slack[y]>tmp)
			slack[y]=tmp;
	}
	return false;
}
int KM(){
 	memset(linker,-1,sizeof(linker));
	memset(ly,0,sizeof(ly));
	for(int i=0; i<nx; i++){
		lx[i]=-inf;
		for(int j=0; j<ny; j++)
			if(g[i][j]>lx[i])
				lx[i]=g[i][j];
	}
	for(int x=0; x<nx; x++){
		for(int i=0; i<ny; i++)
			slack[i]=inf;
		while(true){
			memset(visx,false,sizeof(visx));
			memset(visy,false,sizeof(visy));
			if(DFS(x))
				break;
			int d=inf;
			for(int i=0; i<ny; i++)
				if(!visy[i]&&d>slack[i])
					d=slack[i];
			for(int i=0; i<nx; i++)
				if(visx[i])
					lx[i]-=d;
			for(int i=0; i<ny; i++){
				if(visy[i])
					ly[i]+=d;
				else
					slack[i]-=d;
			}   
		}
	}
	int res=0;
	for(int i=0; i<ny; i++)
		if(linker[i]!=-1)
			res+=g[linker[i]][i];
	return res;
}
 
 //HDU 2255
int main(){
	int n;
	while(scanf("%d",&n)==1){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&g[i][j]);
		nx=ny=n;
		printf("%d\n",KM());
	}
	return 0;
}
