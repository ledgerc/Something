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

int dp[maxn];
int c[maxn],w[maxn];
int v;
void ZeroOnePack(int cost,int weigh){
	for(int i=v; i>=cost; i--)
		dp[i]=max(dp[i],dp[i-cost]+weigh);
}
void CompletePack(int cost,int weigh){
	for(int i=cost; i<=v; i++)
		dp[i]=max(dp[i],dp[i-cost]+weigh);
}
void MultiplePack(int cost,int weigh,int cnt){
	if(v<=cnt*cost){
		CompletePack(cost,weigh);
		return ;
	}
	else{
		int k=1;
		while(k<=cnt){
			ZeroOnePack(k*cost,k*weigh);
			cnt=cnt-k;
			k=2*k;
		}
		ZeroOnePack(cnt*cost,cnt*weigh);
	}
}
