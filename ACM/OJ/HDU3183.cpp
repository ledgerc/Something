#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int MAXN=1010;
int a[MAXN];
int dp[MAXN][20];

void makeRMQIndex(int n,int b[]){//�γ���Сֵ�±��RMQ
    for(int i=0;i<n;i++)
      dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
       for(int i=0;i+(1<<j)-1<n;i++)
          dp[i][j]=b[dp[i][j-1]]<=b[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
          //����һ��Ҫ�ӵȺţ�������ȵ�ʱ��ȡ�±�С��
}
int rmqIndex(int s,int v,int b[]){
    int k=(int)(log(v-s+1.0)/log(2.0));
    return b[dp[s][k]]<=b[dp[v-(1<<k)+1][k]]?dp[s][k]:dp[v-(1<<k)+1][k];
    //�ӵȺţ�ȡС��С��
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
        for(int i=m;i<n;i++){//��n-m������ÿ�δ�[t,i]������С��
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
