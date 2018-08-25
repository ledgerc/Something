#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<Cstdio>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        int time=0,ans,num;
        while(n--){
            cin>>num;
            if(time==0){  
                ans=num;  
                time++;  
            }
            else{
                if(num==ans)
                    time++;
                else
                    time--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
