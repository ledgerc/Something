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
const int maxn = 1e7+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

bool check[maxn];
int prime[maxn];
int mu[maxn];
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
}
int main(){
	Moblus();
	int T; scanf("%d",&T);
	while(T--){
		ll n; scanf("%lld",&n);
		ll ans1=0,ans2=0;
		for(int i=1; i<=n; i++)
			ans1+=(ll)mu[i]*(n/i)*(n/i)*(n/i);
		for(int i=1; i<=n; i++)
			ans2+=(ll)mu[i]*(n/i)*(n/i)*3;
		cout<<ans1+ans2+3<<endl;
	}
	return 0;
}
