#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
int n,k;
double a[maxn];
bool C(double x){
	int num=0;
	for(int i=0; i<n; i++){
		num+=(int)(a[i]/x);
	}
	return num>=k;
}
void solve(){
	double lb=0, ub=inf;
	for(int i=0; i<100; i++){
		double mid = (lb+ub)/2;
		if(C(mid))	lb=mid;
		else ub=mid;
	}
	printf("%.2f\n",floor(ub*100)/100);
}
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		scanf("%lf",&a[i]);
	}
	solve();
	return 0;
}
