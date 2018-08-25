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
//用二分查找的方法找到一个位置，使得num>b[i-1] 并且num<b[i],并用num代替b[i]
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
		//如果a[i]比b[]数组中最大还大直接插入到后面即可
		if(a[i]>=b[len]){
			len++; b[len]=a[i];
		}
		else{
		//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
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
