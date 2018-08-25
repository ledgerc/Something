#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn = 110;
int n;
int s[maxn],a[maxn];
int d[maxn][maxn];
bool used[maxn][maxn];
int dp(int i,int j){
	if(used[i][j])
		return d[i][j];
	used[i][j]=true;
	int m=0;
	for(int k=i+1; k<=j; k++)
		m=min(m,dp(k,j));
	for(int k=i; k<j; k++)
		m=min(m,dp(i,k));
	d[i][j]=s[j]-s[i-1]-m;
	return d[i][j];
}
int main(){
	while(scanf("%d",&n)&&n){
		memset(used,false,sizeof used);
		s[0]=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		printf("%d\n",2*dp(1,n)-s[n]);
	}
	return 0;
}
