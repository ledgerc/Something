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
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 9973;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

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
