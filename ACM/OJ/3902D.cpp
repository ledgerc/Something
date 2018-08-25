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
const int maxn = 3e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Node{
	int x,y,id;
}a[maxn];
bool cmp(Node a,Node b){
	return a.y==b.y ? a.x<b.x : a.y>b.y;
}
priority_queue<int> q;
int ans=0,r=-1,n,k;
void solve(){
	q.push(-2e9);
	for(int i=0; i<n; i++){
		if(q.size()==k){
			int l=max(q.top(),a[i].x);
			if(a[i].y-l+1>=ans){
				ans=a[i].y-l+1;
				r=a[i].y;
			}
		}
		q.push(a[i].x);
		if(q.size()>k)
			q.pop();
	}
}
void print(){
	if(ans){
		int l=r-ans+1;
		for(int i=0; k>0; i++){
			if(a[i].x<=l&&a[i].y>=r){
				k--;
				printf("%d ",a[i].id);
			}
		}
	}
	else{
		for(int i=0; i<k; i++)
			printf("%d ",a[i].id);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i+1;
	}
	sort(a,a+n,cmp);
	solve();
	printf("%d\n",ans);
	print();
	return 0;
}
