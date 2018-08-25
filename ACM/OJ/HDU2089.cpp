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

int dp[10][3];
void init(){
	dp[0][0]=1;dp[0][1]=0;dp[0][2]=0;
	for(int i=1; i<=6; i++){
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//�����λ���ϳ�4�����9�����֣���Ҫ����2֮ǰ����6
        dp[i][1]=dp[i-1][0];//�ڲ������������ֵ����λ����2
        dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];
        //�����в���������ǰ���������֣������޲��������ֵ����λ��4��������2ǰ���6
	}
}
int bit[10];
int solve(int n){
	int len=0;
	int tmp=n;
	while(n){
		bit[++len]=n%10;
		n/=10;
	}
	bit[len+1]=0;
	int ans=0;
	bool flag=false;
	for(int i=len; i>=1; i--){
		ans+=dp[i-1][2]*bit[i];
        if(flag)//��λ�Ѿ�����4����62����������
            ans+=dp[i-1][0]*bit[i];
        if(!flag&&bit[i]>4)
            ans+=dp[i-1][0];
        if(!flag&&bit[i+1]==6&&bit[i]>2)
            ans+=dp[i][1];
        if(!flag&&bit[i]>6)
            ans+=dp[i-1][1];
        if(bit[i]==4||(bit[i+1]==6&&bit[i]==2))
            flag=true;
	}
	if(flag)
		ans++;
	return tmp-ans;
}
int main(){
	init();
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		if(n+m==0)
			break;
		printf("%d\n",solve(m)-solve(n-1));
	}
	return 0;
}

/*
int dp[10][10];
void init(){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(int i=1; i<=7; i++)
		for(int j=0; j<10; j++)//ö�ٵ�iλ���ܳ��ֵ���
			for(int k=0; k<10; k++)//ö�ٵ�i-1λ���ܳ��ֵ���
				if(j!=4&&!(j==6&&k==2))
					dp[i][j]+=dp[i-1][k];
}
int solve(int n){
	init();
	int digit[10];
	int len=0;
	while(n>0){//��n��ÿһλ�ֱ�浽digit 
		digit[++len]=n%10;
		n/=10;
	}
	digit[len+1]=0;
	int ans=0;
	for(int i=len; i; i--){
		for(int j=0; j<digit[i]; j++){
			if(j!=4&&!(digit[i+1]==6&&j==2))
				ans+=dp[i][j];
		}
		if(digit[i]==4||(digit[i]==2&&digit[i+1]==6))
			break;
	}
	return ans;
}
int main(){
	int l,r;
	while(scanf("%d%d",&l,&r)!=EOF&&(l+r)){
		int ans=solve(r+1)-solve(l);
		printf("%d\n",ans);
	}
	return 0;
}
*/
