#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 110+7;
const int maxm = 1e6+7;
struct Point{
	int x,y;
	bool operator < (const Point &a){
		return x<a.x;
	}
};
Point p[maxn];
int n,m,y[maxn],on[maxn],on2[maxn],left1[maxn];
int solve() {

	sort(p,p+n);
	sort(y,y+n);
	int num = unique(y,y+n) - y;
	if(num <= 2)
		return n;
	int ans = 0;
	
	for(int i = 0; i < num; i++) 
		for(int j = i + 1; j < num; j++) {
			int ymin = y[i], ymax = y[j];
			
			int cnt = 0;
			for(int k = 0; k < n; k++) {
				if(k == 0 || p[k].x != p[k-1].x) {
					cnt++;
					on[cnt] = on2[cnt] = 0;
					left1[cnt] = left1[cnt-1] + on2[cnt-1] - on[cnt-1];
				}
				if(p[k].y > ymin && p[k].y < ymax)
					on[cnt]++;
				if(p[k].y >= ymin && p[k].y <= ymax)
					on2[cnt]++;
			}
			if(cnt <= 2)
				return n;
			int tmp = 0;
			for(int k = 1; k <= cnt; k++) {
				ans = max(ans,left1[k] + on2[k] + tmp); 	
				tmp = max(tmp, on[k] - left1[k]);
			}
		}
	return ans;
}
int main(){
	int kase=1;
	while(scanf("%d",&n)&&n){
		for(int i=0; i<n; i++){
			cin>>p[i].x>>p[i].y;
			y[i]=p[i].y;
		}
		printf("Case %d: %d\n",kase++,solve());
	}
	return 0;
}
