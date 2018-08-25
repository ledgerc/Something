#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A,B,C,k;
inline void exgcd(ll a,ll b,ll &g,ll &x,ll &y){
    if(b==0){x=1;y=0;g=a;}
    else{exgcd(b,a%b,g,y,x);y-=x*(a/b);}
}
int main(){
    while(scanf("%lld%lld%lld%lld",&A,&B,&C,&k)!=EOF){
        if(!A&&!B&&!C&&!k) break;
        ll c=B-A,a=C,b=1LL<<k,g,x,y;
        exgcd(a,b,g,x,y);
        if(c%g) printf("FOREVER\n");
        else{
            b/=g;c/=g;
            printf("%lld\n",(x%b*c%b+b)%b);
        }
    }
}
