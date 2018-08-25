#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 200005;
int n,m,C[N],pos[N];
int lowbit(int x){
    return x&(-x);
}
int Sum(int x){
    int ret=0;
    while(x>0){
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}
void Add(int x,int d){
    while(x<=N){
        C[x]+=d;
        x+=lowbit(x);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&m);
        memset(C,0,sizeof(C));
        for(int i=1,j=n; i<=n; i++,j--){
            pos[i]=j;
            Add(i,1);
        }
        int x,top = n;
        for(int i=0; i<m; i++){
            scanf("%d",&x);
            printf("%d",n-Sum(pos[x]));
            if(i!=m-1)
                printf(" ");
            Add(pos[x],-1);
            pos[x]=++top;
            Add(top,1);
        }
        printf("\n");
    }
    return 0;
}
