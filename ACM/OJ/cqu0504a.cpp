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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n; 
ll a[maxn],b[maxn],c[maxn];
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
		
	memset(b,0,sizeof b);
	b[0]=1;
	for(int i=1; i<n; i++){
		if(a[i]>a[i-1])
			b[i]=b[i-1]+1;
		else
			b[i]=1;
	}
	
	memset(c,0,sizeof c);
	c[n]=c[n-1]=1;
	for(int i=n-2; i>=0; i--){
		if(a[i]>a[i+1])
			c[i]=c[i+1]+1;
		else
			c[i]=1;
	}
	
	ll sum=0;
	for(int i=0; i<n; i++)
		sum+=max(b[i],c[i]);
	cout<<sum<<endl;
}
