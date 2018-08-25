#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1000010;
int b[maxn]={1,1,0};
typedef long long ll;
void db(){
	for(int i=2; i<maxn; i++){
		if(!b[i]){
			for(int j=i+i; j<=maxn; j+=i)
				b[j]=1;
		}
	}
}
int main(){
	db();
	int T,n,m,x=0;
	cin>>T;
	while(T--){
		x++;
		ll sum=0;
		cin>>n;
		while(n--){
			cin>>m;
			for(int i=m+1; ; i++){
				if(b[i]==0){
					sum+=i;
					break;
				}
			}
		}
		printf("Case %d: %lld Xukha\n",x,sum);
	}
	return 0;
}
