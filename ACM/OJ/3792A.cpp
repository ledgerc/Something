#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<Cstdio>
using namespace std;
const int maxn = 1e5+7;
char s[maxn];
int main(){
	int len,a=0,d=0;
	cin>>len>>s;
	for(int i=0; i<len; i++)
		if(s[i]=='A')
			a++;
		else
			d++;
	if(a>d)
		puts("Anton");
	else if(a<d)
		puts("Danik");
	else
		puts("Friendship");
	return 0;
} 
