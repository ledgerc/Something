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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double eps = 1e-4;
const double pi = acos(-1.0);

struct Node{
	int a,b;
}a[maxm];
int main(){
	int n,p; sc(n); sc(p);
	for(int i=0; i<n; i++){
		sc(a[i].a); sc(a[i].b);
	}
	double l=0,r=1e12;
	while(fabs(r-l)>eps){
		double mid=(l+r)/2;
		double tmp=0;
		for(int i=0; i<n; i++){
			double t=a[i].b-a[i].a*mid;
			if(t<0)
				tmp+=t;
		}
		if(mid*p+tmp>=0)
			l=mid;
		else
			r=mid;
	}
	if(l>1e11)
		cout<<"-1"<<endl;
	else
		cout<<l<<endl;
	return 0;
}
