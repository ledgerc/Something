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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int MOD = 1e9+7; 
struct Matrix{
    ll mat[5][5];
};
Matrix mul(Matrix a,Matrix b){
    Matrix ret;
    memset(ret.mat,0,sizeof ret.mat);
    for(int k=0; k<3; k++)
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
				ret.mat[i][j]=(ret.mat[i][j]%MOD+(a.mat[i][k]%MOD*b.mat[k][j]%MOD))%MOD;
            }
        }
    return ret;
}
Matrix pow_M(Matrix a,ll n){
    Matrix ret;
    memset(ret.mat,0,sizeof(ret.mat));
    ret.mat[0][0]=ret.mat[1][1]=ret.mat[2][2]=1;
    Matrix temp=a;
    while(n){
        if(n&1)
			ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
}
int main(){
	int T; cin>>T;
	while(T--){
		ll n,m; scanf("%lld%lld",&n,&m);
		Matrix Mat;
		Mat.mat[0][0]=0,Mat.mat[0][1]=1,Mat.mat[0][2]=0;
		Mat.mat[1][0]=0,Mat.mat[1][1]=0,Mat.mat[1][2]=1;
		Mat.mat[2][0]=1,Mat.mat[2][1]=1,Mat.mat[2][2]=1;
		Matrix ans;
		ans.mat[0][0]=0,ans.mat[0][1]=0,ans.mat[0][2]=1;
		bool flag=false;
		ll a[maxn];
		for(int i=0; i<m; i++){
			scanf("%lld",&a[i]);
			if(a[i]==0||a[i]==n)
				flag=true;
		}
		if(flag){
			printf("0\n");
			continue;
		}
		sort(a,a+m);
		ll last=0;
        for(int i=0; i<m; ++i){
        	ll now=a[i];
        	if(now-last==1){
        		ans.mat[0][0]=ans.mat[0][1];
        		ans.mat[0][1]=ans.mat[0][2];
        		ans.mat[0][2]=0;
			}
			else if(now-last==2){
				ans.mat[0][1]=((ans.mat[0][0]+ans.mat[0][1])%mod+ans.mat[0][2])%mod;
				ans.mat[0][0]=ans.mat[0][2];
				ans.mat[0][2]=0;
			}
			else{
				Matrix tmp=pow_M(Mat,now-last-3);
				ll tmp1=((tmp.mat[2][0]*ans.mat[0][0]+tmp.mat[2][1]*ans.mat[0][1])%MOD+tmp.mat[2][2]*ans.mat[0][2])%MOD;
				tmp=mul(tmp,Mat);
                ll tmp2=((tmp.mat[2][0]*ans.mat[0][0]+tmp.mat[2][1]*ans.mat[0][1])%MOD+tmp.mat[2][2]*ans.mat[0][2])%MOD;
                ans.mat[0][0]=tmp1; ans.mat[0][1]=tmp2; ans.mat[0][2]=0;
			}
			last=now;
        }
        Matrix tmp=pow_M(Mat,n-last-1);
        ll res=((tmp.mat[2][0]*ans.mat[0][0]+tmp.mat[2][1]*ans.mat[0][1])%MOD+tmp.mat[2][2]*ans.mat[0][2])%MOD;
        printf("--%lld\n",res);
	}
	return 0;
}
