#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e5+7;
int f[maxn];
int main(){
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)&&n){
		f[1]=0;
		for(int i=2; i<=n; i++)
			f[i]=(f[i-1]+k)%i;
		int ans=(m-k+1+f[n])%n;
		if(ans<=0)
			ans+=n;
		printf("%d\n",ans);
	}
	return 0;
} 
