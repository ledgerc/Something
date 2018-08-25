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

int dp[12][15][2][10];//dp[i][j][k][z]：i:处理的数位，j:该数对13取模以后的值，k:是否已经包含13,z：结尾的数==上限 
int bit[12];
int dfs(int pos,int num,bool t,int e,bool flag){
	if(pos==-1)
		return t&&(num==0);

	if(!flag&&dp[pos][num][t][e]!=-1)//没有上限且被访问过
		return  dp[pos][num][t][e];

	int end=flag?bit[pos]:9;
	//如果有上限，只能取到当前位数，如果没上限，可取到9
    //假设该位是2，下一位是3，如果现在算到该位为1，那么下一位是能取到9的，如果该位为2，下一位只能取到3 
	
	int ans=0;
	
	for(int i=0; i<=end; i++)
		ans+=dfs(pos-1, (num*10+i)%13, t||(e==1&&i==3), i, flag&&(i==end));
		
	if(!flag)
		dp[pos][num][t][e]=ans;
	return ans;
}
int calc(int n){
	int pos=0;
	while(n){
		bit[pos++]=n%10;
		n/=10;
	}
	return dfs(pos-1,0,0,0,1);
}
int main(){
	int n;
	memset(dp,-1,sizeof dp);
	while(scanf("%d",&n)==1){
		printf("%d\n",calc(n));
	}
	return 0;
}






#include <cstdio>
#include <cstring>
using namespace std;

const int N=12;
int md[N];
int dp[N][13][3];
//dp[i][j][k] i：第i位，j：余数为j 
//k=0：不含13  1：3开头不含13  2：含13
void getdp(){
    md[0]=1;
    for(int i=1;i<N;i++)
		md[i]=md[i-1]*10%13;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<N-1;i++)
        for(int j=0;j<13;j++){
            for(int k=0;k<10;k++)
                dp[i+1][(j+md[i]*k)%13][0]+=dp[i][j][0];
				 
            dp[i+1][(j+md[i])%13][0]-=dp[i][j][1];
            
            dp[i+1][(j+md[i]*3)%13][1]+=dp[i][j][0];
            
            dp[i+1][(j+md[i])%13][2]+=dp[i][j][1];
            
            for(int k=0;k<10;k++)
                dp[i+1][(j+md[i]*k)%13][2]+=dp[i][j][2];
        }
}
int getans(int n){
    int d[11],len=0;
    for(int i=n; i; i/=10)
		d[len++]=i%10;
    d[len]=0;
    bool flag=false;
    int ans=0,mod=0;
    for(int i=len-1;i>=0;mod=(mod+d[i]*md[i])%13,i--){
        for(int j=0;j<d[i];j++)
			ans+=dp[i][(13-(mod+j*md[i])%13)%13][2];
        if(flag){
            for(int j=0;j<d[i];j++)
				ans+=dp[i][(13-(mod+j*md[i])%13)%13][0];
            continue;
        }
        if(d[i+1]==1 && d[i]>3)
			ans+=dp[i+1][(13-mod)%13][1];
        if(d[i]>1)
			ans+=dp[i][(13-(mod+md[i])%13)%13][1];
        if(d[i+1]==1 && d[i]==3)
			flag=true;
    }
    return ans;
}
int main(){
    getdp();
    int n;
    while(~scanf("%d",&n)){
        int ans=getans(n+1);
        printf("%d\n",ans);
    }
    return 0;
}
