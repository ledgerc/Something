int n,m;
bool g[maxn][maxn],vis[maxn];
int lable[maxn],set[maxn];
void Relable(){
	memset(vis,false,sizeof vis);
	vis[1]=true;
	for(int num=n-1; num>0; num--){
		memset(lable,0,sizeof lable);
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				for(int j=1; j<=n-num; j++)
					if(g[i][set[n-j+1]])
						lable[i]++;
			}
		}
		int maxv=0,mx;
		for(int i=1; i<=n; i++){
			if(lable[i]>maxv){
				maxv=lable[i];
				mx=i;
			}
		}
		set[num]=mx;
		vis[mx]=true;
	}
}
bool check(){
	int tmp[maxn];
	for(int i=1; i<=n; i++){
		memset(tmp,0,sizeof tmp);
		int t=0;
		for(int j=i+1; j<=n; j++){
			if(g[set[i]][set[j]]){
				t++;
				tmp[t]=set[j];
			}
		}
		for(int j=2; j<=t; j++)
			if(!g[tmp[j]][tmp[1]])
				return false;
	}
	return true;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0)
			break;
		memset(g,false,sizeof g);
		for(int i=0; i<m; i++){
			int u,v; scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=true;
		}
		set[n]=1;
		Relable();
		if(check())
			printf("Perfect\n");
		else
			printf("Imperfect\n");
		printf("\n");
	}
	return 0;
}
