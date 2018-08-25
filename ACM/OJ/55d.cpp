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
const int mod = 2520;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 3e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

ll dp[21][50][maxn];
int bit[21];
int has[maxn];
ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void init(){
	int cnt=0;
	for(int i=1; i<=2520; i++)
		if(2520%i==0)
			has[i]=cnt++;
	memset(dp,-1,sizeof dp);
}
ll dfs(int pos,int num,int lcm,bool flag){
	if(pos==-1)
		return num%lcm==0;
	if(!flag&&dp[pos][has[lcm]][num]!=-1)
		return dp[pos][has[lcm]][num];
	int end=flag?bit[pos]:9;
	ll res=0;
	for(int i=0; i<=end; i++){
		ll nxlcm=lcm;
		if(i!=0)
			nxlcm=i/gcd(lcm,i)*lcm;
		res+=dfs(pos-1,(num*10+i)%mod,nxlcm,flag&&i==end);
	}
	if(!flag)
		dp[pos][has[lcm]][num]=res;
	return res;
}
ll calc(ll n){
	memset(bit,0,sizeof bit);
	int pos=0;
	while(n){
		bit[pos++]=n%10;
		n/=10;
	}
	return dfs(pos-1,0,1,1);
}
int main(){
	init();
	int T; scanf("%d",&T);
	while(T--){
		ll l,r; cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<endl;
	}
	return 0;
}
