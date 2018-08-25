#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
//http://blog.csdn.net/u012288458/article/details/45937799
//http://www.cnblogs.com/ditoly/p/20170331P.html
int n,m,root,ans,cur;
struct Node{
	int d[2];
	int mn[2],mx[2];//记录边界
	int lch,rch;
	int & operator[](int x){
		return d[x];
	}
	friend bool operator < (Node a,Node b){ 
		return a[cur]<b[cur];
	}
	friend int dis(Node x,Node y){//曼哈顿距离
		return fabs(x[0]-y[0])+fabs(x[1]-y[1]);
	}
}point[maxn];
struct Kdtree{
	Node t[maxn],T;//树上节点 
	int ans; 
    void update(int k){//更新信息
        int l=t[k].lch,r=t[k].rch;
        for(int i=0; i<2; i++){
            t[k].mn[i]=t[k].mx[i]=t[k][i];
            if(l) t[k].mn[i]=min(t[k].mn[i],t[l].mn[i]);
            if(r) t[k].mn[i]=min(t[k].mn[i],t[r].mn[i]);
            if(l) t[k].mx[i]=max(t[k].mx[i],t[l].mx[i]);
            if(r) t[k].mx[i]=max(t[k].mx[i],t[r].mx[i]);
        }
    }
	int build(int l,int r,int now){ 
		cur=now;//排序的维度
		int mid=(l+r)>>1;
		nth_element(point+l,point+mid,point+r+1);//根据cur的值确定排序维度来排序
		t[mid]=point[mid];//更新中点的信息 
		for(int i=0; i<2; i++)
			t[mid].mn[i]=t[mid].mx[i]=t[mid][i];
		if(l<mid)//递归建树 
			t[mid].lch=build(l,mid-1,now^1);
		if(r>mid)
			t[mid].rch=build(mid+1,r,now^1);
		update(mid);//维护中点信息 
		return mid;
	}
	int getmn(Node a){
		int tmp=0;
		for(int i=0; i<2; i++){
			tmp+=max(T[i]-a.mx[i],0);
			tmp+=max(a.mn[i]-T[i],0);
		}
		return tmp;
	}
	void querymn(int k){
		ans=min(ans,dis(t[k],T));
		int l=t[k].lch,r=t[k].rch,dl=inf,dr=inf;
		if(l)
			dl=getmn(t[l]);
		if(r)
			dr=getmn(t[r]);
		if(dl<dr){
			if(dl<ans)
				querymn(l);
			if(dr<ans)
				querymn(r);
		}
		else{
			if(dr<ans)
				querymn(r);
			if(dl<ans)
				querymn(l);
		}
	}
	int getmx(Node b){
		int ans=0;
		for(int i=0; i<2; i++)
			ans+=max(abs(T[i]-x.mn[i]),abs(T[i]-x.mx[i]));
		return ans;
	}
	void querymx(int k){
		ans=max(ans,dis(t[k],T));
		int l=t[k].lch,r=t[k].rch,dl=-inf,dr=-inf;
		if(l)
			dl=getmx(t[l]);
		if(r)
			dr=getmx(t[r]);
		if(dl>dr){
			if(dl>ans)
				querymx(l);
			if(dr>ans)
				querymx(r);
		}
		else{
			if(dr>ans)
				querymx(r);
			if(dl>ans)
				querymx(l);
		}
	}
	void insert(int k,int now){//树上第k个节点
        if(T[now]>=t[k][now]){
            if(t[k].rch)//已有节点 递归插入 
                insert(t[k].rch,now^1);
            else{//创建新的节点 
                t[k].rch=++n; t[n]=T;
                for(int i=0; i<2; i++)
                    t[n].mx[i]=t[n].mn[i]=t[n][i];
            }
        }
        else{
            if(t[k].lch)
                insert(t[k].lch,now^1);
            else{ 
                t[k].lch=++n; t[n]=T;
                for(int i=0; i<2; i++)
					t[n].mx[i]=t[n].mn[i]=t[n][i];
            }
        }
        update(k);
	}
	int query(int x,int y){//查询距离(x,y)曼哈顿距离最近的点队 
        ans=inf;
        T[0]=x; T[1]=y; T.lch=0; T.rch=0;
        querymn(root);
        return ans;
	}
	void Insert(int x,int y){//插入(x,y) 
        T[0]=x; T[1]=y; T.lch=0; T.rch=0;
		insert(root,0);
	}
}kdtree;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&point[i][0],&point[i][1]);
	root=kdtree.build(1,n,0);
	while(m--){
		int op,x,y; scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			kdtree.Insert(x,y);
		}
		else{
			printf("%d\n",kdtree.query(x,y));
		}
	}
	return 0;
}
