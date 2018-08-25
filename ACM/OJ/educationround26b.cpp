#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char mp[maxn][maxn];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%s",mp[i]+1);
	if(n%3!=0&&m%3!=0){
		puts("NO");
		return 0;
	}
	if(n%3==0){
		set<char> s;
		char c1 = mp[1][1]; s.insert(c1);
		bool flag=false;
		for(int i=1; i<=n/3; i++)
			for(int j=1; j<=m; j++)
				if(mp[i][j]!=c1)
					flag=true;
		c1=mp[n/3+1][1]; s.insert(c1);
		for(int i=1; i<=n/3; i++)
			for(int j=1; j<=m; j++)
				if(mp[i+n/3][j]!=c1)
					flag=true;
		c1=mp[n*2/3+1][1]; s.insert(c1);
		for(int i=1; i<=n/3; i++)
			for(int j=1; j<=m; j++)
				if(mp[n*2/3+i][j]!=c1)
					flag=true;
		if(!flag&&s.size()==3){
			puts("YES");
			return 0;
		} 
	}
	if(m%3==0){
		set<char> s;
		char c1 = mp[1][1]; s.insert(c1);
		bool flag=false;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m/3; j++)
				if(mp[i][j]!=c1)
					flag=true;
		c1=mp[1][m/3+1]; s.insert(c1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m/3; j++)
				if(mp[i][j+m/3]!=c1)
					flag=true;
		c1=mp[1][m*2/3+1]; s.insert(c1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m/3; j++)
				if(mp[i][j+m*2/3]!=c1)
					flag=true;
		if(!flag&&s.size()==3){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
