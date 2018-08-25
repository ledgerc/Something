#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 1e4+7;
int a[maxn],b[maxm];
void kmp_pre(int x[],int m,int nex[]){
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
int KMP(int x[],int m,int y[],int n){//x��ģʽ����y������ 
	int i,j;
	int ans=0;
	kmp_pre(x,m,nex);
	i=j=0;
	while(i<n){
		while(-1!=j && y[i]!=x[j])
			j=nex[j];
		i++;j++;
		if(j>=m){
			return i-j+1;
			ans++;
			j=nex[j];
		}
	}
	return ans;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		if(n<m){
			printf("-1\n");
			continue;
		}
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		for(int i=0; i<m; i++)
			scanf("%d",&b[i]);
		int ans=KMP(b,m,a,n);
		if(ans==0)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
