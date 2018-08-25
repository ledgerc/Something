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

int n;
int a[maxn][maxn],b[maxn][maxn];
int l[maxn],r[maxn],u[maxn];
int main(){
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	for(int i=0; i<=n; i++)
		a[0][i]=a[i][0]=inf;
	memset(b,0,sizeof b);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(a[i][j]==a[i-1][j]+1&&a[i][j]==a[i][j-1]+1)
				b[i][j]=1;
	
	return 0;
}
