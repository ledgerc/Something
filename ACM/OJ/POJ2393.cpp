#include<iostream>
using namespace std;
const int maxn = 1e4+7;
int n,s;
int main(){
	cin>>n>>s; 
	int minc=0x3f3f3ff3;
	long long sum=0;
	while(n--){
        int c, y;
        scanf("%d%d",&c,&y);
        if(c>minc+s)
			c=minc+s;
        minc=c;
        sum+=c*y;
    }
    printf("%I64d\n", sum);
    return 0;
}
