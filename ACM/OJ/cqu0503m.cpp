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
const int maxn = 5e5+7;
const int maxm = 5e6+7;
const double pi = acos(-1.0);

int T,n;
ll l,r;
ll a[20];
struct qnode{
	ll v; ll c;
	qnode(ll _v=0,ll _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;
	}
};
bool vis[maxn];
ll dist[maxn];
void Dijkstra(){
	memset(vis,false,sizeof(vis));
	memset(dist,inf,sizeof dist);
	priority_queue<qnode>que;
	while(!que.empty())
		que.pop();
	dist[0]=0;
	que.push(qnode(0,0));
	qnode tmp;
	while(!que.empty()){
		tmp=que.top(); que.pop();
		ll u=tmp.v;
		if(vis[u])
			continue;
		vis[u]=true;
		for(int i=2; i<=n; i++){
			ll v=(u+a[i])%a[1];
			if(dist[v]>dist[u]+a[i]){
				dist[v]=dist[u]+a[i];
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld",&n,&l,&r);
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		Dijkstra();
		ll sum=0;
		for(int i=0; i<a[1]; i++){
			if(r>=dist[i])
				sum+=(r-dist[i])/a[1]+1;
            if(l-1>=dist[i])
            	sum-=(l-1-dist[i])/a[1]+1;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
