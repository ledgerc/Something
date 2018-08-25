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
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		double a,b; scanf("%lf : %lf",&a,&b);
		double tmpc=atan(b/a); tmpc*=180; tmpc/=pi; tmpc*=2;
		double c=a*a+b*b; c=sqrt(c);
		tmpc/=360; tmpc*=2*pi*c; tmpc+=2*a;
		double tmp=200/tmpc;
		double length=tmp*a*2,width=tmp*b*2;
		printf("Case %d: %.10f %.10f\n",kase,length,width);
	}
	return 0;
}
/*
1
3 4
*/
