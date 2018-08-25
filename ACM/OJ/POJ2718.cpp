#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
//关键就是用next_permutation()函数求这列数的全排列，排除前导零的情况。
//不懂这题为什么是搜索 
int a[15];
int n;
void solve(){
    while(a[0]==0)
        next_permutation(a,a+n);
    int ans=INF;
    int mid=(n+1)/2;
    do{
        if(a[mid]){
            int x=a[0],y=a[mid];
            for(int i=1;i<mid;i++)
                x=x*10+a[i];
            for(int i=mid+1;i<n;i++)
                y=y*10+a[i];
            if(ans>abs(x-y))
                ans=abs(x-y);
        }

    }while(next_permutation(a,a+n));
    cout<<ans<<endl;
}
int main(){
    int T;
    char c;

    scanf("%d",&T);
    getchar();
    while(T--){
        n=0;
        memset(a,0,sizeof(a));

        while((c=getchar())!='\n'){
            if(c!=' ')
                a[n++]=c-'0';
        }
        if(n==1)
            printf("%d\n",a[0]);
        else if(n==2)
            printf("%d\n",abs(a[1]-a[0]));
        else
            solve();
    }
    return 0;
}
