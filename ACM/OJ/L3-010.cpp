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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

vector<int> hi[maxn];
vector<int> edge[maxn];
bool f[maxn];
set<int> set1;
vector<int> ans;
void dfs(int v){
	f[v]=0;
	int p;
	for(int i=0; i<hi[v].size(); i++){
		p=hi[v][i];
		set1.insert(p);
	}
	for(int i=0; i<edge[v].size(); i++){
		int w=edge[v][i];
		if(f[w]){
			dfs(w);
		}
	}
}
int main(){
	int n,m; cin>>n;
	int u,v;
	for(int i=0; i<n; i++){
		cin>>m; getchar();
		u=0;
		for(int j=0; j<m; j++){
			cin>>v; f[v]=1;
			hi[v].push_back(i);
			if(u!=0){
				edge[v].push_back(u);
				edge[u].push_back(v);
			}
			u=v;
		} 
	}
	for(int i=1; i<maxn; i++){
		if(f[i]){
			set1.clear();
			dfs(i);
			ans.push_back(set1.size());
		}
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1; i>0; i--)
		cout<<ans[i]<<" ";
	cout<<ans[0]<<endl;
	return 0;
}
