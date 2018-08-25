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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
int T,n,m,k;
struct Node{
	int x,y;
}city[maxm];
bool cmp(Node a,Node b){
	if(a.x<b.x)
		return true;
	else if(a.x==b.x&&a.y<b.y)
		return true;
	return false;
}
ll treeNum[maxn];
int lowbit(int x){
	return x&(-x);
}
ll getSum(int x){
	ll sum=0;
	while(x){
		sum+=treeNum[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int val){
	while(x<maxn){
		treeNum[x]+=val;
		x+=lowbit(x);
	}
}
int main(){
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0; i<k; i++)
			scanf("%d%d",&city[i].x,&city[i].y);
		ll ans=0;
		memset(treeNum,0,sizeof treeNum); 
		sort(city,city+k,cmp);
		for(int i=0; i<k; i++){
			ans+=i-getSum(city[i].y);
			add(city[i].y,1);
		}
		printf("Test case %d: %lld\n",kase,ans);
	}
	return 0;
}
