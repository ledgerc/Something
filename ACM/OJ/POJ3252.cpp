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
	从高位到低位搜索过程中，遇到当前位为0，则不处理，
	但要用计数器zero累计当前0出现的次数 遇到当前位为1，则先把它看做为0，
	zero+1，那么此时当前位 后面的 所有低位任意组合都会比k小，
	找出这些组合中RN的个数，统计完毕后把当前位恢复为原来的1，然后zero-1，
	继续向低位搜索
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
 * 转换成2进制中，0的个数不少于1的个数
 * 直接用排列组合的方法也可以出来
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[40][40][40];
int bit[40];
int dfs(int pos,int num0,int num1,bool flag,bool z){
	//pos-第几层 num0 num1 0、1的个数
    if(pos==-1)//如果到达最底层 返回这个数是不是RN
		return num0>=num1;
    
    //记忆化搜索 
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
