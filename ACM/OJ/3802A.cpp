#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n;
	cin>>n>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o'){
			while(s[i+1]=='g'&&s[i+2]=='o'){
				i+=2; 
			}
			cout<<"***";
		}
		else{
			cout<<s[i];
		}
	}
	return 0;
}
