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

//筛法欧拉函数表 
int euler[3000001];
void getEuler(){
	memset(euler,0,sizeof euler);
	euler[1]=1;
	for(int i=2; i<=3000000; i++)
		if(!euler[i])
			for(int j=i; j<=3000000; j+=i){
				if(!euler[j])
					euler[j]=j;
				euler[j]=euler[j]/i*(i-1);
			}
}
//求单个数的欧拉函数
ll eular(ll n){
	ll ans=n;
	for(int i=2; i*i<=n; i++)
		if(n%i==0){
			ans-=ans/i;
			while(n%i==0)
				n/=i;
		}
	if(n>1)
		ans-=ans/n;
	return ans;
}
