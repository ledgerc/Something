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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,c;
int dp[2][maxn];
int q[maxn],head,tail;
int main(){
	while(scanf("%d%d",&n,&c)!=EOF){
		int pre=0,now=1,x;
		scanf("%d",&x);
		for(int i=0; i<x; i++)
			dp[pre][i]=inf;
		for(int i=x; i<=100; i++)
			dp[pre][i]=(x-i)*(x-i);
		for(int i=1; i<n; i++){
			scanf("%d",&x);
			head=tail=0;
			for(int j=0; j<=100; j++){
				int nowf=dp[pre][j]-j*c;
				while(head<tail && q[tail-1]>nowf)
					tail--;
				q[tail++]=nowf;
				if(j<x)
					dp[now][j]=inf;
				else
					dp[now][j]=q[head]+j*c+(x-j)*(x-j);
			}
			head=tail=0;
			for(int j=100; j>0; j--){
				int nowf=dp[pre][j]+j*c;
				while(head<tail && q[tail-1]>nowf)
					tail--;
				q[tail++]=nowf;
				if(j>=x)
					dp[now][j]=min(dp[now][j],q[head]-j*c+(x-j)*(x-j));
			}
			swap(now,pre);
		}
		int ans=inf;
		for(int i=0; i<=100; i++)
			ans=min(ans,dp[pre][i]);
		printf("%d\n",ans);
	}
}
