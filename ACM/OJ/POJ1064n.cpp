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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,k;
double a[maxn];
bool check(int mid){
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=(int)(a[i]/mid);
	return sum>=k;
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0; i<n; i++)
			scanf("%lf",&a[i]);
		double l=0,r=200005.0;
		for(int i=0; i<200; i++){
			double mid=(l+r)/2;
			if(check(mid))
				l=mid;
			else
				r=mid;
		}
		printf("%.2f\n",floor(r*100)/100);
	}
}
