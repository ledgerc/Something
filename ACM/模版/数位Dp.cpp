#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int dp[20][2000];
int a[20];//储存最大值的数字情况
//state是dp的状态
//f是当前层是否被限制
int dfs(int pos, int state, int f){
	//到达末尾返回//这种情况下记录的是[0,r]
	if(pos==-1)
		;
	//没有被限制且已经计算过值的情况
	if (!f&&dp[pos][state]!=-1)
		return dp[pos][state];
	//i在考虑限制后能达到的最大值
	int end=f?a[pos]:9;
	int res=0;
	for (int i=0; i<=end; ++i){
		//状态转移
		int laststate=state;
		
		//下一个状态是被限制的当且仅当当前被限制且取了极限值
		res+=dfs(pos-1,laststate,f&&i==end);
	}
	//只有在没被限制的情况下才更新dp的值
	//换言之dp储存的是没被限制情况下的所有值
	if(!f)
		dp[pos][state]=res;
	return res;
}
int cal(ll x){
	//将最大数字所有位记录下来
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,1);
}
