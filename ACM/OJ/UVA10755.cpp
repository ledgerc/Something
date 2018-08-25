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
const int N = 25;
ll g[N][N][N];
int a,b,c;
ll sum(int startA, int endA, int startB, int endB, int C){
	return g[endA][endB][C]-g[startA-1][endB][C]-g[endA][startB-1][C]+g[startA-1][startB-1][C];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(g,0,sizeof(g));
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1; i<=a; i++){
			for(int j=1; j<=b; j++){
				for(int k=1; k<=c; k++){
					scanf("%lld",&g[i][j][k]);
					g[i][j][k]+=(g[i-1][j][k]+g[i][j-1][k]-g[i-1][j-1][k]);
				}
			}
		}
		ll ans=-INF;
		for(int startA=1; startA<=a; startA++){
			for(int endA=startA; endA<=a; endA++){
				for(int startB=1; startB<=b; startB++){
					for(int endB=startB; endB<=b; endB++) {
						int startC=1;
						int endC=1;
						ll m=0;
						while(endC<=c){
							m+=sum(startA, endA, startB, endB, endC);
							if(m>ans)
								ans=m;
							while(m<0&&startC<=endC){
								m-=sum(startA,endA,startB,endB,startC);
								startC++;
								if(startC<=endC&&m>ans)
									ans=m;
							}
							endC++;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
		if(t)
			printf("\n");
	}
}
