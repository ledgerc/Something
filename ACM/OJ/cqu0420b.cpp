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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+7;
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
ll sum(ll a){
	int ans=0;
	while(a>0){
		ans+=(a%10);
		a/=10;
	}
	return ans;
}
int main(){
	init();
	vector<ll> prim;
	for(int i=0; i<maxn; i++)
		if(isprime[i]){
			prim.push_back(i);
		}
	ll n;
	sc(n);
	ll ans1=sum(n);
	ll ans2=0;
	ll tmp=n;
	for(int i=0; i<prim.size(); i++){
	//	cout<<prim[i]<<endl;
		if(tmp%prim[i]==0){
			int cntt=0;
		//	cout<<prim[i]<<endl;
			while(tmp%prim[i]==0){
				tmp/=prim[i];
				cntt++;
			}
			ans2+=(cntt)*sum(prim[i]);
		//	cout<<cntt<<" "<<prim[i]<<endl;
		}
		if(tmp==1)
			break;
	}
	if(ans1==ans2)
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
}
