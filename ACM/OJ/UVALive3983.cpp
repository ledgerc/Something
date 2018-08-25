#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[100010];
int total_d[100010],total_w[100010],origins[100010];
int x[100010],y[100010];
int n,M;
int func(int x){
    return d[x]-total_d[x+1]+origins[x+1];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&M,&n);
        int w;
        total_d[0]=total_w[0]=0;
        x[0]=y[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x[i],&y[i],&w);
            total_d[i]=total_d[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            total_w[i]=total_w[i-1]+w;
            origins[i]=x[i]+y[i];
            d[i]=total_d[i]+origins[i];
        }
        int cur=0;
        for(int i=1;i<=n;i++){
            while(cur<i && total_w[i]-total_w[cur]>M)
				cur++;
            int temp=1<<30;
            for(int j=cur;j<i;j++){
                temp=min(temp,func(j));
            }
            if(temp<(1<<30))
                d[i]+=temp;
        }
        printf("%d\n",d[n]);
        if(t>0)
			printf("\n");
    }
    return 0;
}
