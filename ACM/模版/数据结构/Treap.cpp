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
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);



struct Treap{
	int l,r;
};



struct data{
    int l,r,v,size,rnd,w;
}tr[100005];
int n,size,root,ans;
void update(int k)//更新结点信息
{
    tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].w;
}
void rturn(int &k)
{
    int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;
    tr[t].size=tr[k].size;update(k);k=t;
}
void lturn(int &k)
{
    int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;
    tr[t].size=tr[k].size;update(k);k=t;
}
void insert(int &k,int x)
{
    if(k==0)
    {
        size++;k=size;
        tr[k].size=tr[k].w=1;tr[k].v=x;tr[k].rnd=rand();
        return;
    }
    tr[k].size++;
    if(tr[k].v==x)tr[k].w++;
    else if(x>tr[k].v)
    {
        insert(tr[k].r,x);
        if(tr[tr[k].r].rnd<tr[k].rnd)lturn(k);
    }
    else 
    {
        insert(tr[k].l,x);
        if(tr[tr[k].l].rnd<tr[k].rnd)rturn(k);
    } 
}
void del(int &k,int x)
{
    if(k==0)return; 
    if(tr[k].v==x)
    {
        if(tr[k].w>1)
        {
            tr[k].w--;tr[k].size--;return;
        }
        if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;
        else if(tr[tr[k].l].rnd<tr[tr[k].r].rnd)
            rturn(k),del(k,x);
        else lturn(k),del(k,x);
    }
    else if(x>tr[k].v)
        tr[k].size--,del(tr[k].r,x);
    else tr[k].size--,del(tr[k].l,x);
}
int query_rank(int k,int x)
{
    if(k==0)return 0;
    if(tr[k].v==x)return tr[tr[k].l].size+1;
    else if(x>tr[k].v)
        return tr[tr[k].l].size+tr[k].w+query_rank(tr[k].r,x);
    else return query_rank(tr[k].l,x);
}
int query_num(int k,int x)
{
    if(k==0)return 0;
    if(x<=tr[tr[k].l].size)
        return query_num(tr[k].l,x);
    else if(x>tr[tr[k].l].size+tr[k].w)
        return query_num(tr[k].r,x-tr[tr[k].l].size-tr[k].w);
    else return tr[k].v;
}
void query_pro(int k,int x)
{
    if(k==0)return;
    if(tr[k].v<x)
    {
        ans=k;query_pro(tr[k].r,x);
    }
    else query_pro(tr[k].l,x);
}
void query_sub(int k,int x)
{
    if(k==0)return;
    if(tr[k].v>x)
    {
        ans=k;query_sub(tr[k].l,x);
    }
    else query_sub(tr[k].r,x);
}
int main()
{
    scanf("%d",&n);
    int opt,x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&opt,&x);
        switch(opt)
        {
        case 1:insert(root,x);break;
        case 2:del(root,x);break;
        case 3:printf("%d\n",query_rank(root,x));break;
        case 4:printf("%d\n",query_num(root,x));break;
        case 5:ans=0;query_pro(root,x);printf("%d\n",tr[ans].v);break;
        case 6:ans=0;query_sub(root,x);printf("%d\n",tr[ans].v);break;
        }
    }
    return 0;
}












/*
ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int num[maxn],st[maxn];
struct Treap{
	int tot1;
	int s[maxn],tot2;//内存池和容量
	int ch[maxn][2];
	int key[maxn],size[maxn];
	int sum0[maxn],sum1[maxn];
	int status[maxn];
	void init(){
		tot1=tot2=0;
		size[0]=0;
		ch[0][0]=ch[0][1]=0;
		sum0[0]=sum1[0]=0;
	}
	bool random(double p){
		return (double)rand()/RAND_MAX<p;
	}
	int newnode(int val,int _status){
		int r;
		if(tot2)
			r=s[tot2--];
		else
			r=++tot1;
		size[r]=1;
		key[r]=val;
		status[r]=_status;
		ch[r][0]=ch[r][1]=0;
		sum0[r]=sum1[r]=0;
		return r;
	}
	void del(int r){
		if(!r)
			return;
		s[++tot2]=r;
		del(ch[r][0]);
		del(ch[r][1]);
	}
	void push_up(int r){
		int lson=ch[r][0],rson=ch[r][1];
		size[r]=size[lson]+size[rson]+1;
		sum0[r]=gcd(sum0[lson],sum0[rson]);
		sum1[r]=gcd(sum1[lson],sum1[rson]);
		if(status[r]==0)
			sum0[r]=gcd(sum0[r],key[r]);
		else
			sum1[r]=gcd(sum1[r],key[r]);
	}
	void merge(int &p,int x,int y){
		if(!x||!y)
			p=x|y;
		else if(random((double)size[x]/(size[x]+size[y]))){
			merge(ch[x][1],ch[x][1],y);
			push_up(p=x);
		}
		else{
			merge(ch[y][0],x,ch[y][0]);
			push_up(p=y);
		}
	}
	void split(int p,int &x,int &y,int k){
		if(!k){
			x=0; y=p;
			return;
		}
		if(size[ch[p][0]]>=k){
			y=p;
			split(ch[p][0],ch[y][0],k);
			push_up(y);
		}
		else{
			x=p;
			split(ch[p][1],ch[x][1],y,k-size[ch[p][0]]-1);
			push_up(x);
		}
	}
	void build(int &p,int l,int r){
		if(l>r)
			return;
		int mid=(l+r)/2;
		p=newnode(num[mid],st[mid]);
		build(ch[p][0],l,mid-1);
		build(ch[p][1],mid+1,r);
		push_up(p);
	}
	void debug(int root){
		if(root==0)
			return;
		printf("%d   左儿子：%d  右儿子: %d  size = %d  key = %d\n",root,ch[root][0],ch[root][1],size[root],key[root]);
		debug(ch[root][0]);
		debug(ch[root][1]);
	}
};
*/
