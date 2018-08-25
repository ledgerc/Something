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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int mid[maxn],be[maxn];
struct node{
	int l,r;
}a[maxn];
int build(int la,int ra,int lb,int rb){
	if(la>ra)
		return 0;
	int rt=be[rb],p1=la,p2;
	while(mid[p1]!=be[rb])
		p1++;
	p2=p1-la;
	a[rt].l=build(la,p1-1,lb,lb+p2-1);
	a[rt].r=build(p1+1,ra,lb+p2,rb-1);
	return rt;
}
void bfs(int x){
	queue<int> q;
	vector<int> v;
	q.push(x);
	while(!q.empty()){
		int w=q.front(); q.pop();
		if(w==0)
			break;
		v.push_back(w);
		if(a[w].l!=0)
			q.push(a[w].l);
		if(a[w].r!=0)
			q.push(a[w].r);
	}
	for(int i=0; i<v.size(); i++)
		printf("%d%c",v[i],i==v.size()-1?'\n':' ');
	return ;
}
int main(){
	int n; cin>>n;
	for(int i=0; i<n; i++)
		cin>>be[i];
	for(int i=0; i<n; i++)
		cin>>mid[i];
	build(0,n-1,0,n-1);
	int root=be[n-1];
	bfs(root);
	return 0;
}
