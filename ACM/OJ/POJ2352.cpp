#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 32010;

int n , ans[MAXN];
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

int main(){
    int x , y;
    while(scanf("%d" , &n) != EOF){ 
        memset(treeNum , 0 , sizeof(treeNum));
        memset(ans , 0 , sizeof(ans));
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d" , &x , &y); 
            x++;
            ans[getSum(x)]++; 
            add(x , 1);
        }
        for(int i = 0 ; i < n ; i++)
            printf("%d\n" , ans[i]);
    }
    return 0;
}
