#include<iostream>
#include<Cstdio>
#include<cstring>
#include<string>
#include<Set>
#include<algorithm>
using namespace std; 
const int maxn = 1e3+8;
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
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;int ans=0;
		init(n+1);
		for(int i=0; i<m; i++){
			int tmp1,tmp2; cin>>tmp1>>tmp2;
			unite(tmp1,tmp2);
		}
		for(int i=1; i<=n; i++){
			if(f[i]==i)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
