#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1e3+7;
const int maxm = 1e4+7;
char a[maxn],b[maxn];
void kmp_pre(char x[],int m,int nex[]){
	int i,j;
	j=nex[0]=-1;
	i=0;
	while(i<m){
		while(-1!=j&&x[i]!=x[j])
			j=nex[j];
		if(x[++i]==x[++j])
			nex[i]=nex[j];
		else
			nex[i]=j;
	}
}
//����x��y�г��ֵĴ����������ص� 
int nex[10010];
int KMP(char x[],int m,char y[],int n){//x��ģʽ����y������ 
	int i,j;
	int ans=0;
	kmp_pre(x,m,nex);
	i=j=0;
	while(i<n){
		while(-1!=j && y[i]!=x[j])
			j=nex[j];
		i++;j++;
		if(j>=m){
			ans++;
			j=0;
		}
	}
	return ans;
}
int main(){
	while(scanf("%s",a)&&a[0]!='#'){
		scanf("%s",b);
		int n,m;
		m=strlen(b); n=strlen(a);
		int ans=KMP(b,m,a,n);
			printf("%d\n",ans);
	}
	return 0;
} 
