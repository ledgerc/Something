#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int node[20];
int ans[1<<17],cover[1<<17];
int n;
int main(){
    int C=0;
    while(~scanf("%d",&n)&&n){  
        int m,i,j,t;
        for(i=0;i<n;i++){
            node[i]=1<<i;
            scanf("%d",&m);
            for(j=0;j<m;j++){
                scanf("%d",&t);  
                node[i]|=1<<t;
            }
        }
        int Max=(1<<n)-1,S,S0;
        for(S=1;S<=Max;S++){  
            cover[S]=0;
            for(i=0;i<n;i++)
                if(S&(1<<i))
					cover[S]|=node[i];
        }
        for(S=1;S<=Max;S++){
            ans[S]=0;
            for(S0=S;S0;S0=(S0-1)&S){
                if(cover[S0]==Max)
					ans[S]=max(ans[S],ans[S^S0]+1);
            }
        }
        printf("Case %d: %d\n",++C,ans[S-1]);
    }
}
