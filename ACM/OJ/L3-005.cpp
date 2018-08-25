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
const int maxn = 1e3+27;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//Dijkstra 单源最短路，邻接矩阵形式
//权值必须非负
int cost[maxn][maxn];//表示边u,v的权值 
int d[maxn];//从点s出发的最短距离 
bool vis[maxn];
int n,m,k,ds;
void dijkstra(int s){
	for(int i=0; i<=n+m; i++)
		d[i]=inf;
	memset(vis,false,sizeof vis);
	d[s]=0;
	while(true){
		int u=-1;
		//从尚未使用的顶点中选择一个距离最小的顶点 
		for(int i=1; i<=n+m; i++){
			if(vis[i])
				continue;
			if(u==-1||d[i]<d[u])
				u=i;
		}
		if(u==-1)
			break;
		vis[u]=true;
		for(int i=1; i<=n+m; i++){
			d[i]=min(d[i],d[u]+cost[u][i]);
		}
	}
}
int change(char a[]){
	int len=strlen(a);
	int ans=0;
	if(a[0]=='G'){
		for(int i=1; i<len; i++)
			ans=ans*10+a[i]-'0';
		ans+=n;
	}
	else{
		for(int i=0; i<len; i++)
			ans=ans*10+a[i]-'0';
	}
	return ans;
}
int main(){
	memset(cost,inf,sizeof cost);
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	char a[10],b[10]; int u,v,w;
	for(int i=0; i<k; i++){
		scanf("%s%s%d",a,b,&w);
		u=change(a),v=change(b);
		cost[u][v]=cost[v][u]=w;
	}
	int ansnum=0,ans;
	double mindistance,minaver=inf;
	for(int i=n+1; i<=n+m; i++){
		dijkstra(i);
		double flag=false;//over ds
		double sum=0;//sum of the distance
		double tmin=inf;//minnum distance
		for(int j=1; j<=n; j++){
			if(d[j]>ds){
				flag=true;
				break;
			}
			if(d[j]<tmin)
				tmin=d[j];
			sum+=d[j];
		}
		if(flag)
			continue;
		ansnum++;
		sum/=n;
		if(tmin>mindistance){
			minaver=sum;
			mindistance=tmin;
			ans=i-n;
		}
		else if(tmin==mindistance){
			if(minaver>sum){
				minaver=sum;
				ans=i-n;
			}
		}
	}
	if(ansnum==0)
		cout<<"No solution"<<endl;
	else{
		cout<<"G"<<ans<<endl;
		printf("%.1f %.1f\n",mindistance,minaver);
	}
	return 0;
}
