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

struct Node{
	ll cnt,sum,sqsum;
}dp[20][10][10];
int bit[20];
ll p[20];
Node dfs(int pos,int pre1,int pre,bool flag){
	if(pos==-1){
		Node tmp;
		tmp.cnt=(pre1!=0&&pre2!=0);
		tmp.sum=tmp.sqsum=0;
		return tmp;
	}
	if(!flag&&dp[pos][pre1][pre2].cnt!=-1)
		return dp[pos][pre1][pre2];
	int end=flag?bit[pos]:9;
	Node ans,tmp;
	ans.cnt=ans.sqsum=ans.sum=0;
	for(int i=0; i<=end; i++){
		if(i==7)
			continue;
		tmp=dfs(pos-1,(pre1+i)%7,(pre2*10+i)%7,flag&&i==end);
		
	}
	
	if(!flag)
		dp[pos][pre1][pre2]=ans;
	return ans;
}
ll calc(ll n){
	int pos=0;
	while(n){
		bit[pos++]=n%10;
		n/=10;
	}
	return dfs(pos-1,0,0,1).sqsum;
}
int main(){
	int T; scanf("%d",&T);
	ll l,r;
	p[0]=1;
	for(int i=1; i<20; i++)
		p[i]=(p[i-1]*10)%mod;
	for(int i=0; i<20; i++)
		for(int j=0; j<10; j++)
			for(int k=0; k<10; k++)
				dp[i][j][k]=-1;
	while(T--){
		scanf("%lld%lld",&l,&r);
	}
}
