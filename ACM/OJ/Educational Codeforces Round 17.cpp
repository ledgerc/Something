#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6+10;
int a[maxn];
void init(){
    long long int n;
    int k,ans = 0,flag = 0;
    scanf("%I64d%d",&n,&k);
    for(long long i = 1 ; i * i <= n ; i++){
        if(n%i == 0){
            a[++ans] = i;
            if(i *i == n) flag = 1;
        }
        if(ans == k){
            printf("%I64d\n",i);
            return ;
        }
    }
    if(flag == 0){
        if(k>2*ans)
            printf("-1\n");
        else
            printf("%I64d\n",(long long)n/a[2*ans-k+1]);
    }
    else{
        if(k>2*ans-1)printf("-1\n");
        else    printf("%I64d\n",(long long)n/a[2*ans-k]);
    }
}

int main(){
    init();
    return 0;
}
