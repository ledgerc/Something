#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	char c[6];
	while(scanf("%s",c)!=EOF){
		sort(c,c+3);
		cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
	}
	return 0;
} 
