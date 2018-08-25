//kuangbin ��С������ Kruskal�㷨 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 200+1;//������ 
const int maxm = 20000+1;//������ 
int F[maxn];//���鼯 
struct Edge{
	int u,v,w;
}edge[maxm];//�洢�ߵ���Ϣ ���/�յ�/Ȩֵ 
int tol;//�������ӱ�ǰ��ֵΪ0
void addedge(int u,int v,int w){
	edge[tol].u=u;
	edge[tol].v=v;
	edge[tol++].w=w;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	if(F[x]==-1)
		return x;
	else
		return F[x]=find(F[x]);
}
int Kruskal(int n){//���������������С��������Ȩֵ���������ͨ����-1 
	memset(F,-1,sizeof F);
	sort(edge,edge+tol,cmp);
	int cnt=0;//�������ı��� 
	int ans=0;
	for(int i=0; i<tol; i++){
		int u=edge[i].u; int v=edge[i].v; int w=edge[i].w;
		int t1=find(u); int t2=find(v);
		if(t1!=t2){
			ans+=w;
			F[t1]=t2;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	if(cnt<n-1)
		return -1;//����ͨ 
	else
		return ans;
}
int main(){
	int n,m;
	int ans;
	while(cin>>n&&n){
		cin>>m;
		ans=tol=0;
		for(int i=0; i<m; i++){
			int u,v,w; cin>>u>>v>>w;
			addedge(u,v,w);
			addedge(v,u,w);
		}
		ans=Kruskal(n);
		cout<<ans<<endl;
	}
	return 0;
}
