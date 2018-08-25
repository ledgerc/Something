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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
int tmpNum[maxn],num[maxn]; 
int treeNum[maxn];
int lowbit(int x){
	return x&(-x);
}
int getSum(int x){
	int sum=0;
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
	while(scanf("%d",&n)&&n){
		int x,y,m;
		memset(treeNum,0,sizeof treeNum);
		m=n;
		while(m--){
			scanf("%d%d",&x,&y);
			add(x,1);
			add(y+1,-1);
		}
		printf("%d",getSum(1));
		for(int i=2; i<=n; i++)
			printf(" %d",getSum(i));
		printf("\n");
	}
	return 0;
}
