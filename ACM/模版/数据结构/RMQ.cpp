int a[maxn],Max[maxn][20],Min[maxn][20];
void rmq_init(int l,int r){
	for(int i=l; i<=r; i++)
		Max[i][0]=Min[i][0]=a[i];
	for(int j=1; l+(1<<j)-1<=r; j++)
		for(int i=l; i+(1<<j)-1<=r; i++){
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
			Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
		}
}
int rmq_max(int l,int r){
	int k=log2(r-l+1);
	return max(Max[l][k],Max[r-(1<<k)+1][k]);
}
int rmq_min(int l,int r){
	int k=log2(r-l+1);
	return min(Min[l][k],Min[r-(1<<k)+1][k]);
}
