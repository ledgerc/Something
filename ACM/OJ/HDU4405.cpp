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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
��dp[i]��ʾ��iλ��ʱ��������Ϸ������ҪͶ��������������
��Ȼdp[n]Ϊ0����Ҫ�����dp[0]��
����ֱ�ӷɹ�ȥ�ĵ㡣
����������vis[]����ʾ��vis[a]=b����ʾ������a��ʱ����ֱ�ӷɵ�b�㣬
��ô��Ȼdp[vis[a]]=dp[a]��

�����ƣ�dp[i](����õ㲻���ڿɷ��еĵ�)������һ��״̬��6�ֿ���
ÿ�ֶ���1/6�ĸ��ʡ�����for(int x=1;x<=6;x++) dp[i]+=dp[i+x]/6.0;
dp[i]+=1;ע��������ÿ�ֿ����Ե�������Ҫ+1����Ϊ��6�ֿ����Լ�����ֻ����һ��״̬����������ǰ״̬�����ǵ�ǰһ��״̬������������ֱ�����ΪͶ�����ӵĴ�����Ҫ+1��
*/ 
double dp[maxn];
int vis[maxn];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n+m==0)
			break;
		memset(vis,-1,sizeof vis);
		int u,v;
		for(int i=1; i<=m; i++){
			scanf("%d%d",&u,&v);
			vis[u]=v;
		}
		memset(dp,0,sizeof dp);
		for(int i=n-1; i>=0; i--){
			if(vis[i]==-1){
				for(int j=1; j<=6; j++)
					dp[i]+=dp[i+j]/6.0;
				dp[i]+=1;
			}
			else
				dp[i]=dp[vis[i]];
		}
		printf("%.4lf\n",dp[0]);
	}
	return 0;
}
