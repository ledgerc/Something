#include<iostream>
#include<cmath>
using namespace std;
int main(){
double ans;
while(scanf("%lf",&ans)!=EOF){
	
if(ans<0)
 ans=-ans;
printf("%.2f\n",ans);
}
return 0;
}
