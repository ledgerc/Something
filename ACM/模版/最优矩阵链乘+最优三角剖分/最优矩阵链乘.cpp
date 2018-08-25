#include<stdio.h>
#include<iostream>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,p[105],f[105][105];
    while(scanf("%d",&n)&&n){
        int i,j,k;
        for(i=0;i<=n;i++)scanf("%d",&p[i]);
        for(i=1;i<=n;i++){
            for(j=0;j<=n;j++)f[i][j]=1<<30;
            f[i][i]=0;
            f[i][i+1]=p[i-1]*p[i]*p[i+1];
        }
        for(k=2;k<=n;k++)
            for(i=1;i<=n-k;i++)
                for(j=0;j<k;j++)
                    f[i][i+k]=min(  (f[i][i+j]+f[i+j+1][i+k]+p[i-1]*p[i+j]*p[i+k])  ,  (f[i][i+k])  );
        printf("%d\n",f[1][n]);
    }
    return 0;
}
