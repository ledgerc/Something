struct Matrix{
    int row,col;
    static const int N=3;//!!!!!!!!!!!!!!!
    ll mat[N][N];
    void init(int r,int c,bool one=false){
        row=r; col=c;
        memset(mat,0,sizeof mat);
        if(!one)
			return;
        for(int i=0; i<row; ++i)
			mat[i][i]=1;
    }
    Matrix operator* (const Matrix& rhs){
        Matrix ret; ret.init(row, rhs.col);
        for(int k=0; k<col; ++k){
            for(int i=0; i<row; ++i){
                if(mat[i][k]==0)
					continue;
                for(int j=0; j <rhs.col; ++j){
                    if(rhs.mat[k][j] == 0)
						continue;
                    ret.mat[i][j]+=mat[i][k]*rhs.mat[k][j]%mod;
                    ret.mat[i][j]%=mod;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (ll n) {
        Matrix ret,x=*this;
        ret.init(row,col,1);
        for(;n;n>>=1) {
            if(n&1)
				ret=ret*x;
            x=x*x;
        }
        return ret;
    }
};


int n,k;
struct Matrix{
    int m[110][110];
}M;
Matrix Mult(Matrix a,Matrix b){
	Matrix ans;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			ans.m[i][j]=0;
			for(int k=0; k<n; k++)
				ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
		}
	return ans;
}
Matrix Pow(Matrix a,int b){
    Matrix ans;
    for(int i=0; i<n; i++)
    	for(int j=0; j<n; j++)
    		ans.m[i][j]=(i==j);
    while(b){
        if(b&1)
			ans=Mult(ans,a);
        a=Mult(a,a);
        b>>=1;
    }
    return ans;
}
int main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&M.m[i][j]);
		M=Pow(M,k);
		int ans=0;
		for(int i=0; i<n; i++)
			ans=(ans+M.m[i][i])%mod;
		cout<<ans<<endl;
	}
	return 0;
}
