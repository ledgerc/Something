#include<iostream>  
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
struct cow{
    int id,l,r;
    bool operator<(cow a) const
    {
        if(l!=a.l)
        return l<a.l;
        return r<a.r;
    }
}x[50010];
struct stall{
    int id,t;
    stall(int x,int y){
        id=y;
        t=x;
    }
    stall(){};
    bool operator<(stall a) const{
        return t<a.t;
    }
};
int ans[50010];  
int main(){
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i].l,&x[i].r);
            x[i].id=i;
        }
        sort(x+1,x+n+1);
        multiset<stall> q;
        int num=0;
        for(int i=1;i<=n;i++){
            int val=x[i].l;
            multiset<stall>::iterator it;
            it=q.lower_bound(stall(val,1));
            if(it==q.begin()){  
                stall a;  
                a.t=x[i].r;  
                a.id=++num;  
                q.insert(a);  
                ans[x[i].id]=num;  
            }  
            else{  
                it--;  
                stall k=*it;  
                k.t=x[i].r;  
                ans[x[i].id]=k.id;  
                q.erase(it);  
                q.insert(k);  
            }  
        }  
        cout<<num<<endl;  
        for(int i=1;i<=n;i++)  
            cout<<ans[i]<<endl;  
    }  
    return 0;  
}  
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
typedef long long ll;
static const int M = 1000010;
static const int N = 50010;
static const int LEN = 100;
static const int MAX = 0x7fffffff;
static const int MIN = ~MAX;
static const double EPS = 1e-8;
struct cow_t {
    int first;
    int second;
    int num;
    bool operator < (const struct cow_t & t) const {
        return first < t.first;
    }
};
std::multiset<struct cow_t> cows;
void solve(int n){
    int output[N];
    int nstalls = 0;
    while (!cows.empty()) {
        std::multiset<struct cow_t>::iterator it
            = cows.begin();
        nstalls++;
        while (it != cows.end()) {
            struct cow_t tmp;
            tmp.first = it->second;
            output[it->num] = nstalls;
            std::multiset<struct cow_t>::iterator next
             = cows.upper_bound(tmp);
            cows.erase(it);
            it = next;
        }
    }
    printf("%d\n", nstalls);
    for (int i = 0; i < n; i++) {
        printf("%d\n", output[i]);
    }
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int interval_a, interval_b;
        struct cow_t tmp;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &interval_a, &interval_b);
            tmp.first = interval_a;
            tmp.second = interval_b;
            tmp.num = i;
            cows.insert(tmp);
        }
        solve(n);
    }
    return 0;
}
*/
