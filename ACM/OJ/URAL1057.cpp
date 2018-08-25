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

int f[40][40];
int a[40];
void init(){
	f[0][0]=1;
	for(int i=1; i<=31; i++){
		f[i][0]=f[i-1][0];
		for(int j=1; j<=i; j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1];
	}
}
int calc(int x,int k){
	int tot=0,ans=0;
	for(int i=31; i>0; i--){
		if(x&(1<<i)){
			tot++;
			if(tot>k)
				break;
			x^=(1<<i);
		}
		if((1<<(i-1))<=x)
			ans+=f[i-1][k-tot];
	}
	if(tot+x==k)
		ans++;
	return ans;
}
int change(int n,int b){
	int len=0,res=0;
	while(n){
		a[++len]=n%b;
		n/=b;
	}
	int j=len;
	while(a[len]<=1)
		len--;
	while(len>=1){
		a[len]=1;
		len--;
	}
	while(j>=1){
		res=a[j]+(res<<1);
		j--;
	}
	return res;
}
int help(int n,int k,int b){
	int tmp=change(n,b);
	return calc(tmp,k);
}
int main(){
	int l,r,k,b;
	init();
	while(scanf("%d%d%d%d",&l,&r,&k,&b)!=EOF){
		int ans=help(r,k,b)-help(l-1,k,b);
		printf("%d\n",ans);
	}
	return 0;
}
