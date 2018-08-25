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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
����dp[i][j][ii][jj]��ʾ��ǰi�����У��ʹﵽj��ii����ѡ��jj���ز�ѡ�����������ii��jj��ΧΪ0-2������ѭ���Ϳ����ˡ�

�����֣�
1. ��i ������ѡ�ɲ�ѡ����ôdp[i][j][ii][jj] += dp[i-1][j][ii][jj] + dp[i-1][j-a[i]][ii][jj]��
2. �ַ����֣�
	1. ��i������ѡ��dp[i][j][ii][jj] += dp[i-1][j-a[i]][ii-1][jj]��
	2. ��i�����ز�ѡ��dp[i][j][ii][jj] += dp[i-1][j][ii][jj-1]��
*/
int a[maxn];
int dp[maxn][maxn][3][3];
int main(){
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof dp);
		dp[0][0][0][0]=1;
		for(int i=1; i<=n; i++){
			for(int j=m; j>=0; j--){
				for(int ii=2; ii>=0; ii--){
					for(int jj=2; jj>=0; jj--){
						dp[i][j][ii][jj]+=dp[i-1][j][ii][jj];
						dp[i][j][ii][jj]%=mod;
						if(j+a[i]<=m){
							dp[i][j+a[i]][ii][jj]+=dp[i-1][j][ii][jj];
							dp[i][j+a[i]][ii][jj]%=mod;
						}
						if(ii>0&&j+a[i]<=m){
							dp[i][j+a[i]][ii][jj]+=dp[i-1][j][ii-1][jj];
							dp[i][j+a[i]][ii][jj]%=mod;
						}
						if(jj>0){
							dp[i][j][ii][jj]+=dp[i-1][j][ii][jj-1];
							dp[i][j][ii][jj]%=mod;
						}
					}
				}
			}
		}
		ll ret=0;
		for(int i=2; i<=m; i++)
			ret+=dp[n][i][2][2];
		printf("%lld\n",ret*2*2%mod);
	}
	return 0;
}
