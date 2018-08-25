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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,a[maxn];
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		int cnt=0;
		for(int i=0; i<n; i++){
			if(m>=a[i]){
				m-=a[i];
				cnt++;
			}
		}
		cout<<n-cnt<<endl;
	}
	return 0;
}
