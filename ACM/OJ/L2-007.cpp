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

int f[maxn];
bool vis[maxn],la[maxn];
struct Node{
	int id,people;
	double sum,num;
}person[maxn],ans[maxn],p2[maxn];
bool cmp(Node a,Node b){
	if(a.sum==b.sum)
		return a.id<b.id;
	return a.sum>b.sum;
}
int find(int x){
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
void unite(int x,int y){
	int t1=find(x),t2=find(y);
	if(t1!=t2){
		if(t1>t2)
			f[t1]=t2;
		else
			f[t2]=t1;
	}
}
void init(){
	for(int i=0; i<maxn; i++)
		f[i]=i;
	memset(vis,false,sizeof vis);
	memset(la,false,sizeof la);
}
int main(){
	int n,id,fa,ma; scanf("%d",&n);
	init();
	for(int i=0; i<n; i++){
		scanf("%d%d%d",&id,&fa,&ma);
		vis[id]=true;
		if(fa!=-1){
			unite(fa,id);
			vis[fa]=true;
		}
		if(ma!=-1){
			unite(ma,id);
			vis[ma]=true;
		}
		int k,tmp; scanf("%d",&k);
		for(int j=0; j<k; j++){
			scanf("%d",&tmp);
			if(tmp!=-1){
				unite(tmp,id);
				vis[tmp]=true;
			}
		}
		scanf("%lf%lf",&person[i].num,&person[i].sum);
		person[i].id=id;
	}
	for(int i=0; i<n; i++){
		int tmp; tmp=find(person[i].id);
		p2[tmp].id=tmp;
		p2[tmp].num+=person[i].num;
		p2[tmp].sum+=person[i].sum;
	}
	int ren=0;
	for(int i=0; i<maxn; i++)
		if(vis[i])
			p2[find(i)].people++;
	for(int i=0; i<maxn; i++){
		if(vis[i]){
			int ttt=find(i);
			if(!la[ttt]){
				la[ttt]=1;double xx = double(p2[ttt].people);
                ans[ren].id = ttt;
                ans[ren].num = p2[ttt].num*1.0/xx;
                ans[ren].sum = p2[ttt].sum*1.0/xx;
                ans[ren++].people = int(xx) ;
			}
		}
	}
	printf("%d\n",ren);
	sort(ans,ans+ren,cmp);
	for(int i=0; i<ren; i++)
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].sum);
		return 0;
}
