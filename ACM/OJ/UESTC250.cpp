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

int dp[15][10];
void init(){
	memset(dp,0,sizeof dp);
	for(int i=0; i<10; i++)
		dp[1][i]=1;
	for(int i=2; i<=10; i++)
		for(int j=0; j<10; j++){
			for(int k=0; k<=j-2; k++)
				dp[i][j]+=dp[i-1][k];
			for(int k=j+2; k<10; k++)
				dp[i][j]+=dp[i-2][k];
		}
}
int bit[20];
int calc(int n){
	if(n==0)
		return 0;
	int len=0;
	while(n){
		bit[++len]=n%10;
		n/=10;
	}
	bit[len+1]=-10;
	int ans=0;
	bool flag=true;
	for(int i=1; i<len; i++)//add those whose length is smaller than the n;
		for(int j=1; j<=9; j++)
			ans+=dp[i][j];
	for(int j=1; j<bit[len]; j++)//the highest bit
		ans+=dp[len][j];
	for(int i=len-1; i>=1; i--){
		for(int j=0; j<bit[i]; j++)
			if(abs(bit[i+1]-j)>=2)
				ans+=dp[i][j];
		if(abs(bit[i+1]-bit[i])<2){
			flag=false;
			break;
		}
	}
	if(flag)
		ans++;
	return ans;
}
int main(){
	int l,r;
	init();
	scanf("%d%d",&l,&r);
	printf("%d\n",calc(r)-calc(l-1));
	
	return 0;
}
