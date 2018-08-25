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
#define key_value (ch[ch[root][1]][0])
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

bool check[maxn];
int prime[maxn];
int mu[maxn];
int sum[maxn]; 
void Moblus(){
	memset(check,false,sizeof check);
	mu[1]=1;
	int tot=0;
	for(int i=2; i<=maxn; i++){
		if(!check[i]){
			prime[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0; j<tot; j++){
			if(i*prime[j]>maxn)
				break;
			check[i*prime[j]]=true;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			else
				mu[i*prime[j]]=-mu[i];
		}
	}
	sum[0]=0;
	for(int i=1; i<=maxn; i++)
		sum[i]=sum[i-1]+mu[i];
}
ll solve(int n,int m){
	if(n>m)
		swap(n,m);
	ll ans1=0;
	for(int i=1,last=0; i<=n; i=last+1){
		last=min(n/(n/i),m/(m/i));
		ans1+=(ll)(sum[last]-sum[i-1])*(n/i)*(m/i);
	}
	return ans1;
}
int main(){
	Moblus();
	int a,b,c,d,k;
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		ll ans=solve(b/k,d/k)-solve((a-1)/k,d/k)-solve(b/k,(c-1)/k)+solve((a-1)/k,(c-1)/k);
		printf("%lld\n",ans);
	}
	return 0;
}
