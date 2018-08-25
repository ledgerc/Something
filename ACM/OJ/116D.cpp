#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	ll n,k,p=1,c=1,u=1; cin>>n>>k;
    if(k>n/2)
		k=n-k;
    while(p<n*k+1){
       	c+=k;
    	if(c>n){//—≠ª∑¡À“ª»¶ 
			c%=n;
			u++;
		}
       	p+=u;

       	if(u%2==0)
			u++;

       	if(p-1==n*k+1)
		   	cout<<p-1;
     	else
			cout<<p<<" ";
    }
    return 0;
}
/*

*/
