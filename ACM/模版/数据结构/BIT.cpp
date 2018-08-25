struct Bit{
	int n,treenum[maxn];
	void init(int k){
		n=k;
		memset(treenum,0,sizeof treenum);
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int i,int add){
		while(i<=n){
			treenum[i]+=add;
			i+=lowbit(i);
		}
	}
	int Sum(int i){
		int sum=0;
		while(i){
			sum+=treenum[i];
			i-=lowbit(i);
		}
		return sum;
	}
};

struct BIT{
	int c[maxn][maxn];
	int n;
	void init(){
		n=maxn;
		memset(c,0,sizeof c);
	}
	int lowbit(int x){
	    return x & (-x);
	}
	void add(int x,int y,int val){
	    for(int i=x; i<=n; i+=lowbit(i))
	        for(int j=y; j<=n; j+=lowbit(j))
	            c[i][j]+=val;
	}
	int get(int x,int y){
	    int sum=0;
	    for(int i=x; i>0; i-=lowbit(i))
	        for(int j=y; j>0; k-=lowbit(j))
	            sum+=c[i][j];
    	return sum;
	}
}

int n,m;
ll treeNum[maxn][maxn][maxn];
int lowbit(int x){
	return x&(-x);
}
ll getSum(int x,int y,int z){
	ll sum=0;
	for(int i=x; i>0; i-=lowbit(i))
		for(int j=y; j>0; j-=lowbit(j))
			for(int k=z; k>0; k-=lowbit(k))
				sum+=treeNum[i][j][k];
	return sum;
}
void add(int x,int y,int z,int val){
	for(int i=x; i<maxn; i+=lowbit(i))
        for(int j=y; j<maxn; j+=lowbit(j))
            for(int k=z; k<maxn; k+=lowbit(k))
                treeNum[i][j][k]+=val;
}
