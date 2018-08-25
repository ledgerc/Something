#include <stdio.h>   
#include <string.h>   
#include <iostream>   
#define MAX(a,b) (a)>(b)?(a):(b)   
using namespace std;   
int dp[105][65][65];    //d[i][j][k]: “第i行状态是s[j]，第i-1行状态是s[k]”的  
int s[105]; //一行的状态选择s[0], s[1], ... , s[k-1]  
int n,m;    //n行×m列  
int k;  //一行的所有状态数  
int map[105];   //'H''P'地图map[0]~map[n-1]，地图每一行map[line]: 1001 表示HPPH  
int sum[105];   
  
/* dp[i][j][k]表示第i行，当前j状态， 
    i-1行是k状态时候的最大炮数 dp[i][j][k]=MAX(dp[i][j][k],dp[i-1][k][p]+sum[j]) 
    1. 所有下标均从0开始 
    2. m<=10保证了可以用一个int存储一行的状态 
*/  
  
//状态s[x]是否造成行冲突  
bool ok(int x){   
    if(x&(x<<1))
		return false;
    if(x&(x<<2))
		return false;
    return true;  
}
//状态s[x]下有多少个1   
int getsum(int x){   
    int num=0;   
    while(x>0){   
        if(x&1)num++;
        x>>=1;
    }
    return num;
}
void find(){
    memset(s,0,sizeof(s));
    for(int i=0;i<(1<<m);i++){ //i枚举所有m位的二进制数     
        if(ok(i)){
            s[k]=i;   
            sum[k++]=getsum(i);   
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){   
        memset(dp,-1,sizeof(dp));
        int i;  
        for(i=0;i<n;i++){
             for(int j=0;j<m;j++){
                char tmp;   
                cin>>tmp;   
                if(tmp=='H')
					map[i]=map[i]|(1<<j);//把第i行原始状态取反后放入map[i]   
            }
        }
        
        k=0;
        find();
  
        //1. 初始化第0行状态（只考虑有效状态，无效状态为-1）  
        for(i=0;i<k;i++)
            if(!(s[i]&map[0])) //s[i]为1的位如果对应平原(0)，则&运算后为0
                dp[0][i][0]=sum[i];
  
        //2. 计算第1~n-1行状态（碰到无效状态,continue）  
        for(int r=1;r<n;r++)
        {
            for(int i=0;i<k;i++)//枚举第r行的状态 s[i]  
            {
                if(map[r]&s[i]) continue;   //通过地形排除部分第r行的状态
  
                for(int p=0;p<k;p++) //枚举第r-1行状态 s[p]
                {   
                    if(s[i] & s[p]) continue;   //r与r-1没有想接触的
  
                    for(int q=0;q<k;q++) //枚举第r-2行状态s[q]
                    {   
                         if(s[p] & s[q])
						 	continue;   //Sam：这行是我加的
                         if(s[i] & s[q])    continue;   //r与r-2行没有接触的
  
                         if(dp[r-1][p][q]==-1)  continue;   //所有不可能的情形dp[i][j][k]都为-1（初始化的值
                         dp[r][i][p]=MAX(dp[r][i][p],dp[r-1][p][q]+sum[i]);   
                    }
                }
            }
        }
        int ans=0;
        for(i=0;i<k;i++)
            for(int j=0;j<k;j++)
                ans=MAX(ans,dp[n-1][i][j]);
        printf("%d\n",ans);
    }
    system("pause");  
    return 0;  
}
