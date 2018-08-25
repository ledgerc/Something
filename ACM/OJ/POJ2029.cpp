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
const int maxn = 1e2+50;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,w,h;
int treeNum[maxn][maxn];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int y,int val){
	for(int i=x; i<maxn; i+=lowbit(i))
		for(int j=y; j<maxn; j+=lowbit(j))
			treeNum[i][j]+=val;
}
int getSum(int x,int y){
	int sum=0;
	for(int i=x; i>0; i-=lowbit(i))
		for(int j=y; j>0; j-=lowbit(j))
			sum+=treeNum[i][j];
	return sum;
}
int solve(int x,int y){
	int ans=0;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			int sum=getSum(i+x-1,j+y-1);
			sum-=getSum(i-1,j+y-1);
            sum-=getSum(i+x-1,j-1);  
            sum+=getSum(i-1,j-1);  
            ans=max(ans,sum); 
		}
	}
	return ans;
}
int main(){
	int x,y;
	while(scanf("%d",&n)&&n){
		scanf("%d%d",&w,&h);
		memset(treeNum,0,sizeof treeNum);
		for(int i=0; i<n; i++){
			scanf("%d%d",&x,&y);
			add(y,x,1);
		}
		scanf("%d%d",&x,&y);
		printf("%d\n",solve(y,x)); 
	}
	return 0;
}
