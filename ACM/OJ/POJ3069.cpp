#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
const int maxn = 1e3 + 7;
const int mod =  1e9 + 7;
using namespace std;
int N,R,x[maxn];
void solve(){
    sort(x,x + N);
    int i = 0, ans = 0;
    while(i < N){
        int s = x[i++];
        // keep moving right;
        while(i < N && x[i] <= s + R) i++;
        //p is the new point with mark;
        int p = x[i-1];
        //keep moving right until the distance p>R;
        while(i< N && x[i]<=p+R)i++;
        ans ++; 
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d%d",&R,&N)&&N!=-1&&R!=-1){
    	for(int i=0; i<N; i++){
    	    scanf("%d",&x[i]);
		}
		solve();
    }
    return 0;
}
