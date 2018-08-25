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

int  c[33][33]={0};//c[i][j]means that length is i,the number of zero is j
int bin[35];
void init(){
	for(int i=0; i<=32; i++)
		for(int j=0; j<=i; j++)
			if(!j||i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
	return ;
}
void bit(int n){
	bin[0]=0;
	while(n){
		bin[++bin[0]]=n%2;
		n/=2;
	}
	return ;
}
int calc(int n){
	int i,j,sum=0;
	bit(n);
	
	for(int i=1; i<bin[0]-1; i++)
		for(int j=i/2+1; j<=i; j++)
			sum+=c[i][j];
	/*
	�Ӹ�λ����λ���������У�������ǰλΪ0���򲻴���
	��Ҫ�ü�����zero�ۼƵ�ǰ0���ֵĴ��� ������ǰλΪ1�����Ȱ�������Ϊ0��
	zero+1����ô��ʱ��ǰλ ����� ���е�λ������϶����kС��
	�ҳ���Щ�����RN�ĸ�����ͳ����Ϻ�ѵ�ǰλ�ָ�Ϊԭ����1��Ȼ��zero-1��
	�������λ����
	*/
	int zero=0;
	for(int i=bin[0]-1; i>=1; i--)
		if(bin[i])
			for(j=(bin[0]+1)/2-(zero+1); j<=i-1; j++)
				sum+=c[i-1][j];
			else
				zero++;
	return sum;
}
int main(){
	init();
	int l,r; cin>>l>>r;
	cout<<calc(r+1)-calc(l)<<endl;
	return 0;
}

/*
 * POJ 3252
 * ת����2�����У�0�ĸ���������1�ĸ���
 * ֱ����������ϵķ���Ҳ���Գ���
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[40][40][40];
int bit[40];
int dfs(int pos,int num0,int num1,bool flag,bool z){
	//pos-�ڼ��� num0 num1 0��1�ĸ���
    if(pos==-1)//���������ײ� ����������ǲ���RN
		return num0>=num1;
    
    //���仯���� 
	if(!flag&&dp[pos][num0][num1]!=-1)
        return dp[pos][num0][num1];
    
	int ans=0;
    
    int end=flag?bit[pos]:1;
    
    for(int i=0;i<=end;i++)
        ans+=dfs(pos-1, (z&&i==0)?0:num0+(i==0), (z&&i==0)?0:num1+(i==1), flag&&i==end, z&&(i==0));
    
    if(!flag)
		dp[pos][num0][num1]=ans;

    return ans;
}
int calc(int n){
    int len=0;
    while(n){
        bit[len++]=n&1;
        n>>=1;
    }
    return dfs(len-1,0,0,1,1);
}
int main(){
    int l,r;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&l,&r)==2){
        printf("%d\n",calc(r)-calc(l-1));
    }
    return 0;
}
