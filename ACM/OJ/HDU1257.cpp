#include<stdio.h>  
int main(){
    int n,i,j,x,m,dp[1005];  
    while(scanf("%d",&n)!=EOF&&n){  
        dp[1]=0;m=0;
        for(i=1;i<=n;i++){      
            scanf("%d",&x);
            for(j=1;j<=m;j++){ 
                if(x<=dp[j]){  
                    dp[j]=x;  
                    break;  
                }  
            } 
            if(j>m)  
                dp[++m]=x;  
        }  
        printf("%d\n",m);  
    }  
    return 0;  
}
