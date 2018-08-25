#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<Cstdio>
using namespace std;
int k2,k3,k5,k6;
int main(){
	cin>>k2>>k3>>k5>>k6;
	int minn=min(k2,min(k5,k6));
	k2-=minn;
	int ans=minn*256;
	minn=min(k2,k3);
	ans+=minn*32;
	cout<<ans<<endl;
}
