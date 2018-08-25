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

priority_queue<int,vector<int>,greater<int> > que;
vector<int> ans[105];
bool a[maxn];
int main(){
	int n,m,tmp; cin>>n>>m;
	memset(a,false,sizeof a);
	for(int i=0; i<n; i++){
		scanf("%d",&tmp);
	//	a[tmp]=true;
		que.push(tmp);
	//	ans[tmp].push_back(tmp);
	}
	int tmp1,tmp2;
	tmp1=que.top(); que.pop(); ans[tmp1].push_back(tmp1);
	a[tmp1]=true;
	tmp2=que.top(); que.pop(); ans[tmp2].push_back(tmp2);
	a[tmp2]=true;
	que.push(tmp1); que.push(tmp2);
	while(que.size()>1){
		tmp1=que.top(); que.pop();
		tmp2=que.top(); que.pop();
		if(ans[tmp1].size()==0)
			ans[tmp1].push_back(tmp1);
		if(ans[tmp2].size()==0)
			ans[tmp2].push_back(tmp2);
		int tmp3=tmp1+tmp2;
		if(!a[tmp3]){
			a[tmp3]=true;
			for(int i=0; i<ans[tmp1].size(); i++)
				ans[tmp3].push_back(ans[tmp1][i]);
			for(int i=0; i<ans[tmp2].size(); i++)
				ans[tmp3].push_back(ans[tmp2][i]);
		}
		if(tmp3>100)
			break;
		que.push(tmp3);
	}
	if(a[m]){
		printf("%d",ans[m][0]);
		for(int i=1; i<ans[m].size(); i++)
			printf(" %d",ans[m][i]);
	}
	else
		cout<<"No Solution"<<endl;
	return 0;
}
