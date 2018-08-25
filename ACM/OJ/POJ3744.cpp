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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


int n,k;
struct Matrix{
    double mat[110][110];
}M;
Matrix Mult(Matrix a,Matrix b){
	Matrix ans;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++){
			ans.mat[i][j]=0;
			for(int k=0; k<2; k++)
				ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j]);
		}
	return ans;
}
Matrix Pow(Matrix a,int b){
    Matrix ans;
    for(int i=0; i<2; i++)
    	for(int j=0; j<2; j++)
    		ans.mat[i][j]=(i==j);
    while(b){
    //	PR(b)
        if(b&1)
			ans=Mult(ans,a);
        a=Mult(a,a);
    //    PR(ans.mat[0][0])
        b>>=1;
    }
    return ans;
}
int a[maxn];
int main(){
	int n; double p;
	while(scanf("%d%lf",&n,&p)!=EOF){
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		double ans=1;
		Matrix tmp;
		tmp.mat[0][0]=p;tmp.mat[0][1]=1-p;
		tmp.mat[1][0]=1;tmp.mat[1][1]=0;
		
		Matrix temp;
		temp=Pow(tmp,a[0]-1);
		ans*=(1-temp.mat[0][0]);
		for(int i=1; i<n; i++){
			temp=Pow(tmp,a[i]-a[i-1]-1);
			ans*=(1-temp.mat[0][0]);
		}
		printf("%.7lf\n",ans);
	}
	return 0;
}
