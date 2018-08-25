#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int MAXN=1010;
int a[MAXN];
int dp[MAXN][20];

void makeRMQIndex(int n,int b[]){//形成最小值下标的RMQ
    for(int i=0;i<n;i++)
      dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
       for(int i=0;i+(1<<j)-1<n;i++)
          dp[i][j]=b[dp[i][j-1]]<=b[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
          //这里一定要加等号，就是相等的时候取下标小的
}
int rmqIndex(int s,int v,int b[]){
    int k=(int)(log(v-s+1.0)/log(2.0));
    return b[dp[s][k]]<=b[dp[v-(1<<k)+1][k]]?dp[s][k]:dp[v-(1<<k)+1][k];
    //加等号，取小标小的
}
char str[MAXN];
int ans[MAXN];
int main(){
    int m;
    while(scanf("%s%d",&str,&m)!=EOF){
        int n=strlen(str);
        for(int i=0;i<n;i++)a[i]=str[i]-'0';
        makeRMQIndex(n,a);
        int t=0;
        int temp=0;
        for(int i=m;i<n;i++){//找n-m个数，每次从[t,i]中找最小的
            t=rmqIndex(t,i,a);
            ans[temp++]=a[t++];
        }
        t=0;
        while(t<temp&&ans[t]==0)t++;
        if(t>=temp)
			printf("0\n");
        else{
            for(int i=t;i<temp;i++)printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
