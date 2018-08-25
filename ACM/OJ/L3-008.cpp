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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,k;
vector<int> edge[maxn];
bool vis[maxn];
int bfs(int u){
	queue<p> que;
	que.push(p(u,0));
	vis[u]=true;
	int ansstep=0,ansid=u;
	while(!que.empty()){
		p tmp=que.front(); que.pop();
		if(ansstep==tmp.second)
			ansid=min(ansid,tmp.first);
		if(ansstep<tmp.second){
			ansstep=tmp.second;
			ansid=tmp.first;
		}
		for(int i=0; i<edge[tmp.first].size(); i++){
			if(!vis[edge[tmp.first][i]]){
				que.push(p(edge[tmp.first][i],tmp.second+1));
				vis[edge[tmp.first][i]]=true;
			}
		}
	}
	if(ansstep==0)
		return 0;
	else
		return ansid;
}
int main(){
	cin>>n>>m>>k;
	int u,v;
	for(int i=0; i<m; i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=0; i<k; i++){
		memset(vis,false,sizeof vis);
		int tmp; cin>>tmp;
		cout<<bfs(tmp)<<endl;
	}
	return 0;
}
