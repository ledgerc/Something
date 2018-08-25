void kmp_pre(char x[],int m,int nexts[]){
	int i,j;
	j=nexts[0]=-1;
	i=0;
	while(i<m){
		while(-1!=j&&x[i]!=x[j])
			j=nexts[j];
		nexts[++i]=++j;
	}
}
//返回x在y中出现的次数，可以重叠 
int nexts[10010];
int KMP(char x[],int m,char y[],int n){//x是模式串，y是主串 
	int i,j;
	int ans=0;
	kmp_pre(x,m,nexts);
	i=j=0;
	while(i<n){
		while(-1!=j && y[i]!=x[j])
			j=nexts[j];
		i++;j++;
		if(j>=m){
			ans++;
			j=nexts[j];
		}
	}
	return ans;
}
