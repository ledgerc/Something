#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;

ll dp[25][3];
void init(){
	dp[0][0]=1;dp[0][1]=0;dp[0][2]=0;
	for(int i=1; i<=25; i++){
		dp[i][0]=10*dp[i-1][0]-dp[i-1][1];//��ǰ���0~9�����֣�������9ǰ���4
        dp[i][1]=dp[i-1][0];//���λ��9
        dp[i][2]=10*dp[i-1][2]+dp[i-1][1];//�ڱ�������49��ǰ�����������������9ǰ���4
	}
}
int bit[25];
ll calc(ll n){
	int len=0;
	while(n){
		bit[++len]=n%10;
		n/=10;
	}
	bit[len+1]=0;
	ll ans=0;
	bool flag=false;
	for(int i=len; i>=1; i--){
		ans+=dp[i-1][2]*bit[i];
        if(flag)//��λ�Ѿ�����4����62����������
            ans+=dp[i-1][0]*bit[i];
        else{
    		if(bit[i]>4)
    			ans+=dp[i-1][1];
		}
        if((bit[i+1]==4&&bit[i]==9))
            flag=true;
	}
	if(flag)
		ans++;
	return ans;
}
int main(){
	int T; scanf("%d",&T);
	init();
    while(T--){
    	ll n; scanf("%lld",&n);
        printf("%lld\n",calc(n));
    }
    return 0;
}
