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
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
形式一：
	g(n) = sigma(d|n, f(d))
	f(n) = sigma(d|n, μ(n/d) * g(d))
形式二：
	g(n) = sigma(d|n, f(d))
	f(n) = sigma(n|d, μ(n) * g(n/d))
*/
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
	for(int i=0; i<=100; i++)
		printf("mu[%d]: %2d  prime[%d]: %d\n",i,mu[i],i,prime[i]); 
}


/*

//HDU4746 
bool check[maxn];
int prime[maxn];
int mu[maxn];
int sum[maxn];//sum[i]: mu[]的前缀和;
int num[maxn];//num[i]: i的质因子个数;
ll cnt[maxn][20];//cnt[i][j]: 表示公因子个数小于等于j时的mu的前i项和
void Moblus(){
	memset(check,false,sizeof check);
	mu[1]=1;
	int tot=0;
	for(int i=2; i<=maxn; i++){
		if(!check[i]){
			prime[tot++]=i;
			mu[i]=-1;
			num[i]=1; 
		}
		for(int j=0; j<tot; j++){
			if(i*prime[j]>maxn)
				break;
			check[i*prime[j]]=true;
			num[i*prime[j]]=num[i]+1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			else
				mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1; i<maxn; i++)
		for(int j=i; j<maxn; j+=i)
			cnt[j][num[i]]+=mu[j/i];
	for(int i=0; i<maxn; i++)
		for(int j=1; j<19; j++)
			cnt[i][j]+=cnt[i][j-1];
	for(int i=1; i<maxn; i++)
		for(int j=0; j<19; j++)
			cnt[i][j]+=cnt[i-1][j];
}
int main(){
	Moblus();
	int T; scanf("%d",&T);
	while(T--){
		int n,m,k; scanf("%d%d%d",&n,&m,&k);
		k=min(k,18);
		ll ans=0;
		if(n>m)
			swap(n,m);
		for(int i=1,last=i; i<=n; i=last+1){
			last=min(n/(n/i),m/(m/i));
			ans+=(ll)(cnt[last][k]-cnt[i-1][k])*(n/i)*(m/i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
*/
