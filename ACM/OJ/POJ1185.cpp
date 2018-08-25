#include <stdio.h>   
#include <string.h>   
#include <iostream>   
#define MAX(a,b) (a)>(b)?(a):(b)   
using namespace std;   
int dp[105][65][65];    //d[i][j][k]: ����i��״̬��s[j]����i-1��״̬��s[k]����  
int s[105]; //һ�е�״̬ѡ��s[0], s[1], ... , s[k-1]  
int n,m;    //n�С�m��  
int k;  //һ�е�����״̬��  
int map[105];   //'H''P'��ͼmap[0]~map[n-1]����ͼÿһ��map[line]: 1001 ��ʾHPPH  
int sum[105];   
  
/* dp[i][j][k]��ʾ��i�У���ǰj״̬�� 
    i-1����k״̬ʱ���������� dp[i][j][k]=MAX(dp[i][j][k],dp[i-1][k][p]+sum[j]) 
    1. �����±����0��ʼ 
    2. m<=10��֤�˿�����һ��int�洢һ�е�״̬ 
*/  
  
//״̬s[x]�Ƿ�����г�ͻ  
bool ok(int x){   
    if(x&(x<<1))
		return false;
    if(x&(x<<2))
		return false;
    return true;  
}
//״̬s[x]���ж��ٸ�1   
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
    for(int i=0;i<(1<<m);i++){ //iö������mλ�Ķ�������     
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
					map[i]=map[i]|(1<<j);//�ѵ�i��ԭʼ״̬ȡ�������map[i]   
            }
        }
        
        k=0;
        find();
  
        //1. ��ʼ����0��״̬��ֻ������Ч״̬����Ч״̬Ϊ-1��  
        for(i=0;i<k;i++)
            if(!(s[i]&map[0])) //s[i]Ϊ1��λ�����Ӧƽԭ(0)����&�����Ϊ0
                dp[0][i][0]=sum[i];
  
        //2. �����1~n-1��״̬��������Ч״̬,continue��  
        for(int r=1;r<n;r++)
        {
            for(int i=0;i<k;i++)//ö�ٵ�r�е�״̬ s[i]  
            {
                if(map[r]&s[i]) continue;   //ͨ�������ų����ֵ�r�е�״̬
  
                for(int p=0;p<k;p++) //ö�ٵ�r-1��״̬ s[p]
                {   
                    if(s[i] & s[p]) continue;   //r��r-1û����Ӵ���
  
                    for(int q=0;q<k;q++) //ö�ٵ�r-2��״̬s[q]
                    {   
                         if(s[p] & s[q])
						 	continue;   //Sam���������Ҽӵ�
                         if(s[i] & s[q])    continue;   //r��r-2��û�нӴ���
  
                         if(dp[r-1][p][q]==-1)  continue;   //���в����ܵ�����dp[i][j][k]��Ϊ-1����ʼ����ֵ
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
