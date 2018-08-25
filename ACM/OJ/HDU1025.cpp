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
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int a[maxn],b[maxn];
int search(int num,int low,int high){
	int mid;
	while(low<=high){
		mid=(low+high)>>1;
		if(num>=b[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return low;
}
int DP(int n){
	int i,len,pos;
	b[1]=a[1];
	len=1;
	for(i=2; i<=n; i++){
		if(a[i]>=b[len]){
			len++; b[len]=a[i];
		}
		else{
			pos=search(a[i],1,len);
			b[pos]=a[i];
		}
	}
	return len;
}
int main(){
	int n; int kase=0;
	while(scanf("%d",&n)!=EOF){
		kase++;
		for(int i=1; i<=n; i++){
			int u,v; scanf("%d%d",&u,&v);
			a[u]=v;
		}
		printf("Case %d:\n",kase);
		int ans=DP(n);
		if(ans==1)
			printf("My king, at most 1 road can be built.\n\n");
		else
			printf("My king, at most %d roads can be built.\n\n",ans);
		
	}
	return 0;
}
