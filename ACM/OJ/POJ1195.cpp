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
const int maxn = 2e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int s;
int num[maxn][maxn];
long long treeNum[maxn][maxn];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int y,int val){
	if(num[x][y]+val<0)
		val-=num[x][y];
	num[x][y]+=val;
	for(int i=x; i<maxn; i+=lowbit(i))
		for(int j=y; j<maxn; j+=lowbit(j))
			treeNum[i][j]+=val;
}
long long getSum(int x,int y){
	long long sum=0;
	for(int i=x; i>0; i-=lowbit(i))
		for(int j=y; j>0; j-=lowbit(j))
			sum+=treeNum[i][j];
	return sum;
}
int main(){
	int x,i,j,val;
	int l,r,u,d;
	while(scanf("%d%d",&x,&s)!=EOF){
		memset(treeNum,0,sizeof treeNum);
		memset(num,0,sizeof num);
		while(scanf("%d",&x)&&x!=3){
			if(x==1){
				scanf("%d%d%d",&i,&j,&val);
				add(i+1,j+1,val);
			}
			else{
				scanf("%d%d%d%d",&u,&l,&d,&r);
				l++,r++,u++,d++;
				ll sum=getSum(d,r);
                sum-=getSum(u-1,r);
                sum-=getSum(d,l-1);
                sum+=getSum(u-1,l-1);
                printf("%lld\n" ,sum);
			}
		}
	}
	return 0;
}
