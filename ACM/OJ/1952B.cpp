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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	double m,r;	cin>>m>>r;
	double r2=sqrt(double(2.0));
	double ans=0;
	for(int i=1; i<=m; i++){
		ans+=2.0;
		if(i>1){
			ans+=2.0+r2;
			ans+=(i-2)*(i-1+2.0*r2);
		}
		if(i<m){
			ans+=2.0+r2;
			ans+=(m-i-1)*(m-i+2.0*r2);
		}
	}
	printf("%.10lf\n",ans*r/(m*m));
	
	return 0;
}
