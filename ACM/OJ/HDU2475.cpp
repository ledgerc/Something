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
const int maxm = 1e5+7;
const double pi = acos(-1.0);

struct Edge{
	int to,next;
}edge[maxm];
int head[maxn],tot;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void addedge(int u,int v){
	edge[tot].to=v; edge[tot].next=head[u];
	head[u]=tot++;
}

