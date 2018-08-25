#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod = 1e9+7;
const int maxn = 250*250;
const int INF = 0x3f3f3f3f;
int s[maxn],g[maxn],d[maxn];
int num[maxn];
int main(){
	ios::sync_with_stdio(false);
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		int N,p,q,tmp; cin>>N>>p>>q;
		memset(num,0,sizeof num);
		for(int i=1; i<=p+1; i++){
			cin>>tmp; num[tmp]=i;
		}
		int n=0;
		for(int i=0; i<q+1; i++){
			cin>>tmp;
			if(num[tmp])
				s[n++]=num[tmp];
		}
		for(int i=1; i<=n; i++)
			g[i]=INF;
		int ans=0;
		for(int i=0; i<n; i++){
			int k=lower_bound(g+1,g+n+1,s[i])-g;
			d[i]=k;
			g[k]=s[i];
			ans=max(ans,d[i]);
		}
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}
