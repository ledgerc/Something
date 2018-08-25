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
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,B,num;
int pre[maxn];
int a[maxn],b[maxn];
int cnta,cntb;
vector<int> e[maxn];
int dfs(int u,int fa){
	int size=0;
	for(int i=0; i<e[u].size(); i++){
		int v=e[u][i];
		if(v==fa)
			continue;
		size+=dfs(v,u);
		if(size>=B){
			num++;
			for(int j=cnta; j>cnta-size; j--)
				pre[a[j]]=num;
			b[++cntb]=u;
			cnta-=size;
			size=0;
		}
	}
	size++;
	a[++cnta]=u;
	return size;
}
int main(){
	scanf("%d%d",&n,&B);
	for(int i=0; i<=n; i++)
		e[i].clear();
	for(int i=1; i<n; i++){
		int u,v; scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	num=0;cnta=cntb=0;
	int ans=dfs(1,0);
	if(ans){
		for(int i=1; i<=cnta; i++)
			pre[a[i]]=num;
	}
	printf("%d\n",num);
	if(num){
		for(int i=1; i<=n; i++)
			printf("%d%c",pre[i],(i==n)?'\n':' ');
		for(int i=1; i<=cntb; i++)
			printf("%d%c",b[i],(i==cntb)?'\n':' ');
	}
	return 0;
}
