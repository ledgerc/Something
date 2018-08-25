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
#include<bitset>
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
const int maxn = 5e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
某天，Lostmonkey发明了一种超级弹力装置，为了在他的绵羊朋友面前显摆，
他邀请小绵羊一起玩个游戏。
游戏一开始，Lostmonkey在地上沿着一条直线摆上n个装置，
每个装置设定初始弹力系数ki，当绵羊达到第i个装置时，
它会往后弹ki步，达到第i+ki个装置，若不存在第i+ki个装置，

i=1，你要输出从j出发被弹几次后被弹飞，
若i=2则还会再输入一个正整数k，表示第j个弹力装置的系数被修改成k。
*/ 
int n,q;
//跳出该块需要的部数 跳向下一个块的哪个点 
int a[maxn],cnt[maxn],to[maxn];
//点属于第几个块/块长/块数 块左端  块右端 
int belong[maxn],block,num,l[maxn],r[maxn];
//下标从1开始 
void Build(){
	block=(int)sqrt(n+0.5);
	num=n/block;
	if(n%block)
		num++;
	for(int i=1; i<=num; i++){
		l[i]=(i-1)*block+1;
		r[i]=i*block;
	}
	r[num]=n;//最右端端点更新
	for(int i=1; i<=n; i++)
		belong[i]=((i-1)/block)+1;
	for(int i=num; i>0; i--){
		for(int j=r[i]; j>=l[i]; j--){
			if(j+a[j]>r[i]){
				cnt[j]=1; to[j]=min(n+1,j+a[j]);
			}
			else{
				cnt[j]=cnt[j+a[j]]+1;
				to[j]=min(n+1,to[j+a[j]]);
			}
		}
	}
}
void modify(int pos,int val){
	a[pos]=val;
	for(int i=pos; i>=l[belong[pos]]; i--){
		if(i+a[i]>r[belong[pos]]){
			cnt[i]=1;
			to[i]=min(n+1,i+a[i]);
		}
		else{
			cnt[i]=cnt[i+a[i]]+1;
			to[i]=min(n+1,to[i+a[i]]);
		}
	}
}
int query(int pos){
	int ans=0;
	for(int i=pos; i<=n; i=to[i])
		ans+=cnt[i];
	return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		Build();
		scanf("%d",&q);
		int op,pos,v;
		for(int i=0; i<q; i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%d",&pos); pos++;
				printf("%d\n",query(pos));
			}
			else{
				scanf("%d%d",&pos,&v); pos++;
				modify(pos,v);
			}
		}
	}
	return 0;
}
