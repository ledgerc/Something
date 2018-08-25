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
const int maxn = 5e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dpmax[maxn][20];
int dpmin[maxn][20];

void makeMaxRmq(int n,int b[]){
	for(int i=0; i<n; i++)
		dpmax[i][0]=b[i];
	for(int j=1; (1<<j)<=n; j++)
		for(int i=0; i+(1<<j)-1<n; i++)
			dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
}
int getMax(int u,int v){
	int k=(int)(log(v-u+1.0)/log(2.0));
	return max(dpmax[u][k],dpmax[v-(1<<k)+1][k]);
}
void makeMinRmq(int n,int b[]){
	for(int i=0; i<n; i++)
		dpmin[i][0]=b[i];
	for(int j=1; (1<<j)<=n; j++)
		for(int i=0; i+(1<<j)-1<n; i++)
			dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
}
int getMin(int u,int v){
	int k=(int)(log(v-u+1.0)/log(2.0));
	return min(dpmin[u][k],dpmin[v-(1<<k)+1][k]);
}
int a[maxn];
int main(){
	int n,Q,u,v;
	while(scanf("%d%d",&n,&Q)!=EOF){
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		makeMaxRmq(n,a);makeMinRmq(n,a);
		while(Q--){
			scanf("%d%d",&u,&v);
			u--,v--;
			int tmp1=getMax(u,v),tmp2=getMin(u,v);
			printf("%d\n",tmp1-tmp2);
		}
	}
	return 0;
}
