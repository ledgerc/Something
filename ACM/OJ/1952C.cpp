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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
int a[maxn];
int main(){
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=29; i>=0; i--){
		int tmp=(1<<i+1)-1;
		int cnt=0;
		for(int j=1; j<=n; j++)
			if(a[j]&(1<<i)){
				cnt++;
				tmp&=a[j];
			}
		if(tmp%(1<<i)==0){
			cout<<cnt<<endl;
			for(int j=1; j<=n; j++)
				if(a[j]&(1<<i))
					printf("%d ",a[j]);
			return 0;
		}
	}
	return 0;
}
