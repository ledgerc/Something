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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const int maxv = 1<<13;
const double pi = acos(-1.0);

int prime[maxv];
bool isprime[maxv+1];
void init(){
	int p=0;
	memset(isprime,true,sizeof isprime);
	isprime[0]=isprime[1]=false;
	for(int i=2; i<=maxv; i++){
		if(isprime[i]){
			prime[p++]=i;
			for(int j=2*i; j<=maxv; j+=i)
				isprime[j]=false;
		}
	}
}

int in[maxn];
ll dp[2][maxn];
int main(){
	int T; scanf("%d",&T);
	init();
	while(T--){
		int n; scanf("%d",&n);
		memset(in,0,sizeof in);
		for(int i=1; i<=n; i++){
			int tmp; scanf("%d",&tmp);
			in[tmp]++;
		}
		int pre=0,now=1;
		memset(dp,0,sizeof dp);
		dp[pre][0]=1;
		for(int i=3500; i<=4500; i++)
			if(in[i]){
				memset(dp[now],0,sizeof dp[now]);
				for(int j=0; j<maxv; j++){
					dp[now][j]=(dp[now][j]+(in[i]/2+1)*dp[pre][j]%mod)%mod;
					dp[now][j^i]=(dp[now][j^i]+((in[i]-1)/2+1)*dp[pre][j]%mod)%mod;
				}
				swap(now,pre);
			}
		ll ans=0;
		for(int i=2; i<maxv; i++)
			if(dp[pre][i]!=0&&isprime[i]){
				ans=(ans+dp[pre][i])%mod;
			}
		cout<<ans<<endl;
	}
	return 0;
}
