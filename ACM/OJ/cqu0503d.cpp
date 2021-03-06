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
const int maxn = 3e3+7;
const int maxm = 2e6+7;
const double pi = acos(-1.0);

int T,n,A,B;
struct Edge{
	int to,next;
}edge[maxm];
int tot,head[maxn];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
bool vis[maxn];//染色标记，为true表示选择
int S[maxn],top;//栈 
bool dfs(int u){
	if(vis[u^1])
		return false;
	if(vis[u])
		return true;
	vis[u]=true;
	S[top++]=u;
	for(int i=head[u]; i!=-1; i=edge[i].next)
		if(!dfs(edge[i].to))
			return false;
	return true;
}
bool Twosat(int n){
	memset(vis,false,sizeof vis);
	for(int i=0; i<n; i+=2){
		if(vis[i]||vis[i^1])
			continue;
		top=0;
		if(!dfs(i)){
			while(top)
				vis[S[--top]]=false;
			if(!dfs(i^1))
				return false;
		}
	}
	return true;
}

struct Node{
	int x,y;
}a[maxn],like[maxn],dislike[maxn],p1,p2;
int dist1[maxn],dist2[maxn],dab;
bool solve(int mid){
	init();
	for(int i=0; i<A; i++){
		addedge(dislike[i].x*2,dislike[i].y*2+1);
		addedge(dislike[i].x*2+1,dislike[i].y*2);
		addedge(dislike[i].y*2,dislike[i].x*2+1);
		addedge(dislike[i].y*2+1,dislike[i].x*2);
	}
	for(int i=0; i<B; i++){
		addedge(like[i].x*2,like[i].y*2);
		addedge(like[i].x*2+1,like[i].y*2+1);
		addedge(like[i].y*2,like[i].x*2);
		addedge(like[i].y*2+1,like[i].x*2+1);
	}
	for(int i=0; i<n; i++){
		if(dist1[i]>mid)
			addedge(i*2,i*2+1);
		if(dist2[i]>mid)
			addedge(i*2+1,i*2);
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(dist1[i]+dist1[j]>mid){
				addedge(i*2,j*2+1);
				addedge(j*2,i*2+1);
			}
			if(dist2[i]+dist2[j]>mid){
				addedge(i*2+1,j*2);
				addedge(j*2+1,i*2);
			}
			if(dist1[i]+dist2[j]+dab>mid){
				addedge(i*2,j*2);
				addedge(j*2+1,i*2+1);
			}
			if(dist2[i]+dist1[j]+dab>mid){
				addedge(i*2+1,j*2+1);
				addedge(j*2,i*2);
			}
		}
	}
	return Twosat(2*n);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&A,&B);
		cin>>p1.x>>p1.y>>p2.x>>p2.y;
		dab=abs(p1.x-p2.x)+abs(p1.y-p2.y);
		for(int i=0; i<n; i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(int i=0; i<n; i++){
			dist1[i]=abs(a[i].x-p1.x)+abs(a[i].y-p1.y);
			dist2[i]=abs(a[i].x-p2.x)+abs(a[i].y-p2.y);
		}
		for(int i=0; i<A; i++){
			scanf("%d%d",&dislike[i].x,&dislike[i].y);
			dislike[i].x--; dislike[i].y--;
		}
		for(int i=0; i<B; i++){
			scanf("%d%d",&like[i].x,&like[i].y);
			like[i].x--; like[i].y--;
		}
		int l=0,r=maxm*10,ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(solve(mid)){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
