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
const int maxm = 1e7+7;
const double pi = acos(-1.0);

int n;
ll a[maxm];
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n/2; i+=2)
		swap(a[i],a[n-i-1]);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
