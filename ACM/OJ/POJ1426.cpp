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
        return ;//����Ѿ������˴𰸾�û�ѵı�Ҫ��
    if(t%n==0){//���ִ𰸣��������Ǳ�����true
        printf("%I64u\n",t);
        found=true;
        return ;
    }
    if(k==19)	return ;//����19�㣬����
    DFS(t*10,n,k+1);    //������10
    DFS(t*10+1,n,k+1);  //������10+1
}
int main(){
    int n;
    while(cin>>n,n){
        found=false;   //��Ǳ�������Ϊtrue�����ѵ��������һ��m
        DFS(1,n,0);    //��1��ʼ��n�ı��������������������ѵĲ�����������19��ʱ���أ���Ϊ��20��64λ�����治�£�
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
