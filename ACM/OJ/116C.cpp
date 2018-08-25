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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int f[maxn];
void init(int n){
	for(int i=0; i<n; i++){
		f[i]=i;
	}
}
int find(int x){
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
void unite(int x,int y){
	x=find(x); y=find(y);
	if(x==y)
		return;
	f[x]=y;
}
bool same(int x,int y){
	return find(x)==find(y);
} 
int main(){
	int n; cin>>n;
	init(n);
	for(int i=0; i<n; i++){
		int tmp; cin>>tmp; tmp--;
		unite(i,tmp);
	}
	set<int> s;
	for(int i=0; i<n; i++){
		int tmp=find(i);
		s.insert(tmp);
	}
	cout<<s.size()<<endl;
}
