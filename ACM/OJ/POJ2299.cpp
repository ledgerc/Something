#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 500010;
int n;
int tmpNum[MAXN] , num[MAXN];
int treeNum[MAXN];
int lowbit(int x){
    return x&(-x);
}
int getSum(int x){
    int sum = 0;
    while(x){
        sum += treeNum[x]; 
        x -= lowbit(x);
    }
    return sum;
}
void add(int x , int val){
    while(x < MAXN){
         treeNum[x] += val; 
         x += lowbit(x);
    }
}
int search(int x , int len){
    int left = 1;
    int right = len;
    while(left <= right){
         int mid = (left+right)>>1; 
         if(num[mid] == x)
             return mid;
         else if(num[mid] < x)
             left = mid+1;
         else
             right = mid-1;
    }
}
long long solve(){
    long long ans = 0;
    memcpy(tmpNum , num , sizeof(num));
    memset(treeNum , 0 , sizeof(treeNum));
    sort(num+1 , num+1+n);
    int len = unique(num+1 , num+1+n)-(num+1); 
    for(int i = 1 ; i <= n ; i++){
        int id = search(tmpNum[i] , len); 
        ans += i-getSum(id)-1;
        add(id , 1);
    }
    return ans;
}
int main(){
    while(scanf("%d" , &n) && n){
         for(int i = 1 ; i <= n ; i++) 
             scanf("%d" , &num[i]);
         printf("%lld\n" , solve());
    }
    return 0;
}
