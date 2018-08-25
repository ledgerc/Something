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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int tree[20][maxn];//表示每层每个位置的值 
int sorted[maxn];
int toleft[20][maxn];//toleft[p][i]表示第i层从1到i有多少个数分入左边
void build(int l,int r,int dep){
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	int same=mid-l+1;//表示等于中间值而且被分入左边的个数
	for(int i=l; i<=r; i++)
		if(tree[dep][i]<sorted[mid])
			same--;
	int lpos=l,rpos=mid+1;
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])//比中间的数小,分入左边 
			tree[dep+1][lpos++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0){
			tree[dep+1][lpos++]=tree[dep][i];
			same--;
		}
		else//比中间值大分入右边
			tree[dep+1][rpos++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+lpos-l;//从1到i放左边的个数
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}
//查询区间第k大的数，[L,R]是大区间，[l,r]是要查询的小区间
int query(int L,int R,int l,int r,int dep,int k){
	if(l==r)
		return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//[l,r]中位于左边的个数
	if(cnt>=k){
		//L+要查询的区间前被放在左边的个数
		int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		//左端点加上查询区间会被放在左边的个数
		int newr=newl+cnt-1; 
		return query(L,mid,newl,newr,dep+1,k);
	}
	else{
		int newr=r+toleft[dep][R]-toleft[dep][r];
		int newl=newr-(r-l-cnt);
		return query(mid+1,R,newl,newr,dep+1,k-cnt);
	}
}
int main(){
	int n,m; int kase=1;
	while(scanf("%d",&n)!=EOF){
		for(int i=1; i<=n; i++){
			scanf("%d",&tree[0][i]);
			sorted[i]=tree[0][i];
		}
		sort(sorted+1,sorted+n+1);
		build(1,n,0);
		scanf("%d",&m);
		int l,r;
		printf("Case %d:\n",kase++);
		while(m--){
			scanf("%d%d",&l,&r);
			int k=(r-l)/2+1;
			printf("---%d\n",query(1,n,l,r,0,k));
		}
	}
	return 0;
}
