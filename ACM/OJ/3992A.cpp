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

int a[maxn];
int main(){
	int n; cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	int cnt=0;
	for(int i=1; i<n-1; i++)
		if(a[i]>a[0]&&a[i]<a[n-1])
			cnt++;
	cout<<cnt<<endl;
	return 0;
}
