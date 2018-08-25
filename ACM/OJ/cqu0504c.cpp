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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int prime[maxn];
bool isprime[maxn+1];
void init(){
	int p=0;
	memset(isprime,true,sizeof isprime);
	isprime[0]=isprime[1]=false;
	for(int i=2; i<=maxn; i++){
		if(isprime[i]){
			prime[p++]=i;
			for(int j=2*i; j<=maxn; j+=i)
				isprime[j]=false;
		}
	}
}

ll dp[20][200][2000];//pos sum sqsum
int bit[20];
ll dfs(int pos,int sum,int sqsum,bool flag){
	if(pos==-1){
		if(isprime[sum]&&isprime[sqsum])
			return 1;
		return 0;
	}
	if(!flag&&dp[pos][sum][sqsum]!=-1)
		return dp[pos][sum][sqsum];
	
	int end=flag?bit[pos]:9;
	ll res=0;
	for(int i=0; i<=end; i++){
		res+=dfs(pos-1,sum+i,sqsum+i*i,flag&&i==end);
	}
	if(!flag)
		dp[pos][sum][sqsum]=res;
	return res;
}
ll calc(ll b){
	int len=0;
	while(b){
		bit[len++]=b%10;
		b/=10;
	}
	return dfs(len-1,0,0,1);
}
int main(){
	init();
	int T; cin>>T;
	memset(dp,-1,sizeof dp);
	while(T--){
		ll l,r; cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<endl;
	}
	return 0;
}
