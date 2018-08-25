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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

bool prime[maxn];
int n;
void init(){
	memset(prime,1,sizeof prime);
	prime[0]=false; prime[1]=false;
	for(int i=2; i<=maxn; i++){
		if(prime[i]){
			for(int k=i*i; k<=maxn; k+=i)
				prime[k]=false;
		}
	}
}
int main(){
	int m;
	cin>>m;
	init();
	int cnt=0;
	for(int i=m-1; i>=0; i--){
		if(prime[i]){
			printf("%6d",i);
			cnt++;
		}
		if(cnt==10)
			break;
	}
	cout<<endl;
	return 0;
}
