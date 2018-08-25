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
int treeNum[maxn],ans[maxn];
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
struct Node{
	int s,e;
	int number;
	bool operator < (const Node &tmp)const {
		if(s<tmp.s)
			return true;
		else if(s==tmp.s&&e>tmp.e)
			return true;
		return false;
	}
	bool operator == (const Node &tmp)const {
		return s==tmp.s&&e==tmp.e;
	}
}cow[maxn];
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0; i<n; i++){
			scanf("%d%d",&cow[i].s,&cow[i].e);
			cow[i].number=i;
		}
		memset(treeNum,0,sizeof treeNum);
		memset(ans,0,sizeof ans);
		sort(cow,cow+n);
		for(int i=0; i<n; i++){
			int id=cow[i].e;
			if(i&&cow[i]==cow[i-1])
				ans[cow[i].number]=ans[cow[i-1].number];
			else
				ans[cow[i].number]+=i-getSum(id-1);
			add(id,1);
		}
		printf("%d",ans[0]);
		for(int i=1; i<n; i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
