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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		int a[maxn];
		for(int i=0; i<n; i++)
			sc(a[i]);
		if(n<10||n>13){
			cout<<"No"<<endl;
			continue;
		}
		sort(a,a+n);
		int cnt1=0;
		int b[maxn];
		for(int i=0; i<n-1; i++){
			if(a[i]==1)
				cnt1++;
			b[i]=a[i+1]-a[i];
		}
		if(cnt1<2){
			cout<<"No"<<endl;
			continue;
		}
		bool flag=true,flag1=false;
		for(int i=n-1; i>=0; i--){
			if(flag){
				if(b[i]!=0)
					flag=false;
			}
			else{
				if(b[i]>2){
					flag1=true;
					break;
				}
			}
		}
		if(flag1)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
}
