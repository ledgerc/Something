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

struct Node{
	double w;
	double price;
	double aver;
}a[maxn];
bool cmp(Node a,Node b){
	return a.aver>b.aver;
}
int main(){
	int n,m; cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i].w;
	for(int i=0; i<n; i++)
		cin>>a[i].price;
	for(int i=0; i<n; i++)
		a[i].aver=a[i].price/a[i].w;
	sort(a,a+n,cmp);
	double ans=0;
	int i,cnt=0;
	while(m>0&&i<n){
		if(a[i].w<=m){
			ans+=a[i].price;
			m-=a[i].w;
		}
		else{
			ans+=a[i].aver*m;
			m=0;
		}
		i++;
	}
	printf("%.2lf\n",ans);
	return 0;
}
