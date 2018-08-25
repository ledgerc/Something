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
	int n; cin>>n; n++;
	memset(a,0,sizeof a);
	for(int i=2; i<=n; i++)
		if(!a[i])
			for(int j=i+i; j<=n; j+=i)
				a[j]=1;
	if(n<4)
		cout<<"1"<<endl;
	else
		cout<<"2"<<endl;
	for(int i=2; i<=n; i++)
		printf("%d ",a[i]+1);
	return 0;
}
