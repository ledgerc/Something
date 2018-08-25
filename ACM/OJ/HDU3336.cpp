#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
const int N = 200005;
char a[N];
int nex[N],d[N];
void get_nex(char *b){
    int i = -1, j = 0;
    nex[0] = -1;
    int len = strlen(b);
    while(j < len){
        if(i == -1 || b[i] == b[j])
            nex[++j] = ++i;
        else
            i = nex[i];
    }
}
int main(){
    int T,i,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,a);
        get_nex(a);
        for(i=1; i<=n; i++)
            d[i]=1;
        d[0]=0;
        int sum=0;
        for(i=1; i<=n; i++){
            d[i]=d[nex[i]] + 1;
            sum+=d[i]%10007;
        }
        printf("%d\n",sum%10007);
    }
    return 0;
}
