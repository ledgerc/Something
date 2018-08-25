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
const int maxn = 2e2+7;
const int maxm = 1e5+7;
const double pi = acos(-1.0);
const double eps = 1e-5;

struct Edge{
	int to,next;
}edge1[maxm],edge2[maxm];
int head1[maxn],head2[maxn];
int tot1,tot2;
bool vis1[maxn],vis2[maxn];
int Belong[maxn];//连通分量标记 
int st[maxn];//dfs结点结束时间
int Bcnt,Tcnt;
void addedge(int u,int v){
	edge1[tot1].to=v; edge1[tot1].next=head1[u]; head1[u]=tot1++;
	edge2[tot2].to=u; edge2[tot2].next=head2[v]; head2[v]=tot2++;
}
void init(){
	memset(vis1,false,sizeof vis1);
	memset(vis2,false,sizeof vis2);
	memset(head1,-1,sizeof head1);
	memset(head2,-1,sizeof head2);
	tot1=tot2=0;
	Bcnt=Tcnt=0;
}
void dfs1(int u){//对原图进行dfs,算出每个结点的结束时间，哪个点开始无所谓
	vis1[u]=true;
	for(int j=head1[u]; j!=-1; j=edge1[j].next)
		if(!vis1[edge1[j].to])
			dfs1(edge1[j].to);
	st[Tcnt++]=u;
}
void dfs2(int u){
	vis2[u]=true;
	Belong[u]=Bcnt;
	for(int i=head2[u]; i!=-1; i=edge2[i].next)
		if(!vis2[edge2[i].to])
			dfs2(edge2[i].to);
}

struct Point{
	int x,y;
}a[maxn];
double dist(Point a,Point b){
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool check(int n){
	for(int i=0; i<2*n; i++)
		if(!vis1[i])
			dfs1(i);
	for(int i=Tcnt-1; i>=0; i--)
		if(!vis2[st[i]]){
			dfs2(st[i]);
			Bcnt++;
		}
	for(int i=0; i<=2*n-2; i+=2)
		if(Belong[i]==Belong[i+1])
			return false;
	return true;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0; i<n; i++)
			scanf("%d%d%d%d",&a[2*i].x,&a[2*i].y,&a[2*i+1].x,&a[2*i+1].y);
		double l=0,r=40000.0;
		while(r-l>=eps){
			double mid=(l+r)/2;
			init();
			for(int i=0; i<2*n-2; i++){
				int tmp;
				if(i%2==0)
					tmp=i+2;
				else
					tmp=i+1;
				for(int j=tmp; j<2*n; j++)
					if(dist(a[i],a[j])<2*mid){
						addedge(i,j^1); addedge(j,i^1);
					}
			}
			if(check(n))
				l=mid;
			else
				r=mid;
		}
		printf("%.2lf\n",r);
	}
	return 0;
}
