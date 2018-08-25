#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
const int maxn = 1e6 + 7;
const int mod =  1e9 + 7;
using namespace std;
int l,p,n;
int a[maxn+1],b[maxn+1];
void solve(){
	a[n] = l;
	b[n] = 0;
	n++;
	
	priority_queue<int> que;
	
	int ans = 0, pos = 0, tank = p;
	
	for(int i = 0; i < n; i++){
		int d=a[i]-pos;
		
	while(tank - d < 0){
		if(que.empty()){
			puts("-1");
			return ;
		}
		tank+=que.top();
		que.pop();
		ans++;
	}
	
	tank-=d;
	pos = a[i];
	que.push(b[i]);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	scanf("%d%d",&l,&p);	
	solve();
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10010;
struct node{
	int dist, fuel;
};
node position[maxn];
int n, L, P;
bool cmp(const node &a, const node &b){
	return a.dist > b.dist;
}
int main(){
	while(scanf("%d", &n) != EOF){
		priority_queue<int> heap;
		for(int i = 0; i < n; i++)
			scanf("%d %d", &position[i].dist, &position[i].fuel);
		sort(position, position + n, cmp);
		scanf("%d %d", &L, &P);
		int t = 0;
		heap.push(P);
		int index = 0;
		while(L > 0 && !heap.empty()){
			t++;
			int tmp = heap.top();
			heap.pop();
			L -= tmp;
			while(index < n && L <= position[index].dist)
				heap.push(position[index++].fuel);
		}
		printf("%d\n", L <= 0? t - 1: -1);
	}
	return 0;
}
*/
