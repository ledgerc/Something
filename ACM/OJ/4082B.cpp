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
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,k;
int vis[maxn];
int main(){
	memset(vis,false,sizeof vis);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0; i<m; i++){
		int tmp; scanf("%d",&tmp);
		vis[tmp]=true;
	}
	int pos=1;
	while(k--){
		int u,v; scanf("%d%d",&u,&v);
		if(vis[pos])
			break;
		if(pos==u)
			pos=v;
		else if(pos==v)
			pos=u;
	}
	cout<<pos<<endl;
	return 0;
}
