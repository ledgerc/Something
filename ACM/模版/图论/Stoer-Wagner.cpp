//全局最小割
//复杂度 O(n^3) 
int n,m;
int vis[maxn];
int wet[maxn];
int combine[maxn];
int e[maxn][maxn];
int s,t,mincut;
void Search(){
    int i,j,Max,tmp;
    memset(vis,0,sizeof(vis));
    memset(wet,0,sizeof(wet));
    s=t=-1;
    for(i=0; i<n; i++){
        Max=-inf;
        for(j=0; j<n; j++){
            if (!combine[j]&&!vis[j]&&wet[j]>Max){
               tmp=j;
               Max=wet[j];
            }
        }
        if(t==tmp)
		 	return;
        s=t; t=tmp;
        mincut=Max;
        vis[tmp]=1;
        for(j=0; j<n; j++){
            if(!combine[j]&&!vis[j]){
            	wet[j]+=e[tmp][j];
            }
        }
    }
}
int Stoer_Wagner(){
    int i,j;
    memset(combine,0,sizeof(combine));
    int ans=inf;
    for (i=0; i<n-1; i++){
        Search();
        if(mincut<ans)
			ans=mincut;
        if(ans==0)
			return 0;
        combine[t] = 1;
        for(j=0; j<n; j++){
            if(!combine[j]){
               e[s][j]+=e[t][j];
               e[j][s]+=e[j][t];
            }
        }
    }
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m) != EOF){
    	memset(e,0,sizeof(e));
    	while(m--){
    		int u,v,w;
        	scanf("%d%d%d", &u, &v, &w);
          	e[u][v]+=w;
          	e[v][u]+=w;
       }
       printf("%d\n",Stoer_Wagner());
    }
    return 0;
}
