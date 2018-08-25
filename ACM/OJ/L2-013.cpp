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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int f[maxn];
bool vis[maxn];
struct Node{
	int x,y;
}p[maxn];
int find(int x){
	if(f[x]==-1)
		return x;
	return f[x]=find(f[x]);
}
void unite(int a,int b){
	int tmpa=find(a),tmpb=find(b);
	if(tmpa!=tmpb)
		f[tmpa]=tmpb;
}
void init(){
	memset(f,-1,sizeof f);
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	init();
	int tmpa,tmpb;
	for(int i=0; i<m; i++){
		scanf("%d%d",&tmpa,&tmpb);
		p[i].x=tmpa,p[i].y=tmpb;
		unite(tmpa,tmpb);
	}
	int num=0,num1;
	for(int i=0; i<n; i++)
		if(f[i]==i)
			num++;
	memset(vis,false,sizeof vis);
	int k; scanf("%d",&k);
	while(k--){
		num1=0;
		memset(f,-1,sizeof f);
		int x; scanf("%d",&x);
		vis[x]=1;
		for(int i=0; i<m; i++){
			if(vis[p[i].x]==1||vis[p[i].y]==1)
				continue;
			else
				unite(p[i].x,p[i].y);
		}
		for(int i=0; i<n; i++)
			if(f[i]==-1)
				num1++;
		if(num==num1||num+1==num1)
			printf("City %d is lost.\n");
		else
			printf("Red Alert: City %d is lost!\n",x);
		num=num1;
	}
	num=0;
	for(int i=0; i<n; i++)
		if(vis[i]==1)
			num++;
	if(num==n)
		printf("Game Over.\n");
	return 0;
	
}
