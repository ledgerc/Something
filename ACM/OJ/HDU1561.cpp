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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//����״̬dp[i][j] : ��ǰi�ڵ㼰�����������ѡ��j�����е����ֵΪdp[i][j];

/*
1. �жϵ�ǰ�ڵ�P��û�к��ӣ���������ǰ�ڵ�ΪP�ظ�(1)���������û����(2)������ 
2. ����ǰ�ڵ�P��״̬���µ��ڸ��ڵ��ϣ� 
���²���Ϊdp[P'father][i] = max(dp[P'father][i], dp[P'father][j]+dp[P][k])    (j + k = i ,j>0,k>0,2<=i<=max_cost,����ÿһ��i����ÿһ��(j,k)���) 
�����dp[P'father][j] j������һ����û�а���P���е�����j�����е����ֵ  
ֱ��������root�ڵ㼴��(dp[0][i]) 
3.���dp[0][max_cost] 
max_cost Ϊ��Ŀ�������������ȡ��������
*/
vector<int> list[maxn];
int dp[maxn][maxn];
int n,m;

void dfs(int u){
	for(int i=0; i<list[u].size(); i++){
		int v=list[u][i];
		if(list[v].size()>0)
			dfs(v);
		for(int j=m; j>1; j--){
			for(int k=1; k<j; k++)
				dp[u][j]=max(dp[u][j],dp[u][k]+dp[v][j-k]);
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0)
			break;
		m++;
		memset(dp,0,sizeof dp);
		for(int i=0; i<=n; i++)
			list[i].clear();
		for(int i=1; i<=n; i++){
			int u,v; cin>>u>>v;
			list[u].push_back(i);
			for(int j=1; j<=m; j++)
				dp[i][j]=v;
		}
		dfs(0);
		cout<<dp[0][m]<<endl;
	}
	return 0;
}
