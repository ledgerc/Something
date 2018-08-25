#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 5e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int MOD=1e9+7;
struct Matrix{
    int row,col;
    static const int N=3;
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
                    ret.mat[i][j]+=mat[i][k]*rhs.mat[k][j]%MOD;
                    ret.mat[i][j]%=MOD;
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
ll a[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		Matrix Mat; Mat.init(3,3);
		Mat.mat[0][0]=1,Mat.mat[0][1]=1,Mat.mat[0][2]=0;
		Mat.mat[1][0]=1,Mat.mat[1][1]=0,Mat.mat[1][2]=1;
		Mat.mat[2][0]=1,Mat.mat[2][1]=0,Mat.mat[2][2]=0;
		Matrix ans; ans.init(1,3);
		ans.mat[0][0]=1,ans.mat[0][1]=0,ans.mat[0][2]=0;
		
		for(int i=1; i<=m; i++)
			scanf("%lld",&a[i]);
		a[0]=0; a[m+1]=n; m+=2;
		sort(a,a+m);
		
        for(int i = 1; i < m; ++i) {
        	Matrix tmp = Mat^(a[i]-a[i-1]);
            ans=ans*(Mat^(a[i]-a[i-1]));
            if(i<m-1)
				ans.mat[0][0]=0;
        }
        printf("%lld\n", ans.mat[0][0]);
	}
	return 0;
}
