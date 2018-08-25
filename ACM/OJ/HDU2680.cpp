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

//Dijkstra ��Դ���·���ڽӾ�����ʽ
//Ȩֵ����Ǹ�
int cost[maxn][maxn];//��ʾ��u,v��Ȩֵ 
int d[maxn];//�ӵ�s��������̾��� 
bool used[maxn];
int V;//������ 
void dijkstra(int s){
	for(int i=0; i<=V; i++)
		d[i]=cost[0][i];
	memset(used,false,sizeof used);
	d[s]=0;
	for(int i=0; i<=V; i++){
		int v=-1;
		//����δʹ�õĶ�����ѡ��һ��������С�Ķ��� 
		for(int u=0; u<=V; u++){
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		}
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0; u<=V; u++){
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
}
int main(){
	int n,m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		V=n;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				if(i==j)
					cost[i][j]=0;
				else
					cost[i][j]=inf;
		int u,v,w;
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&u,&v,&w);
			cost[u][v]=min(cost[u][v],w);
		}
		int tmp; cin>>tmp;
		for(int i=0; i<tmp; i++){
			scanf("%d",&v);
			cost[0][v]=0;
		}
		dijkstra(0);
		if(d[s]==inf)
			cout<<"-1"<<endl;
		else
			cout<<d[s]<<endl;
	}
	return 0;
}
