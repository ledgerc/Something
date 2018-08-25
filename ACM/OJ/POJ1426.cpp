#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
bool found;
void DFS(unsigned __int64 t ,int n,int k){
    if(found)
        return ;//如果已经发现了答案就没搜的必要了
    if(t%n==0){//发现答案，输出，标记变量该true
        printf("%I64u\n",t);
        found=true;
        return ;
    }
    if(k==19)	return ;//到第19层，回溯
    DFS(t*10,n,k+1);    //搜索×10
    DFS(t*10+1,n,k+1);  //搜索×10+1
}
int main(){
    int n;
    while(cin>>n,n){
        found=false;   //标记变量，当为true代表搜到了题意第一的m
        DFS(1,n,0);    //从1开始搜n的倍数，第三个参数代表搜的层数，当到第19层时返回（因为第20层64位整数存不下）
    }
    return 0;
}
/*
#include<stdio.h>
#include <stdlib.h>
#include <iostream>
int s=0;
using namespace std;
void bag(__int64 p,int n,int k)
{
    if(s==1||k==20)
        return;
    if(p%n==0){
        printf("%I64u\n",p);
        s=1;
    }
	else{
        bag(10*p,n,k+1);
        bag(10*p+1,n,k+1);        
    }
}
int main(){
    int n;
    while(cin>>n,n){
        s=0;
        bag(1,n,1);
    }
    return 0;
}
*/
