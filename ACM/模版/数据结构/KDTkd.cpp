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
#define bug() cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

namespace KDT{
	const int maxn = 1e6+7,sigma_size = 5;
	int D,K;
	struct Point{
		int d[sigma_size];
		int &operator[](int k){
			return d[k];
		}
		void read() {
            for(int i=0; i<K; ++i)
				scanf("%d",d+i);
        }
        void write() {
            for(int i=0; i<K; ++i)
				printf("%d%c",d[i]," \n"[i+1==K]);
        }
		bool operator < (const Point & a) const{
			return d[D]<a.d[D];
		}
	}a[maxn];
	struct Node{
		Point key,maxd,mind;
		Node *ch[2];
		void push_up(){
			for(int i=0; i<K; i++){
				maxd[i]=max(maxd[i],ch[0]->maxd[i]);
				maxd[i]=max(maxd[i],ch[1]->maxd[i]);
				mind[i]=min(mind[i],ch[0]->mind[i]);
				mind[i]=min(mind[i],ch[1]->mind[i]);
			}
		}
	}pool[maxn],*ptr,*null;
	struct qnode{
		ll dis; Point p;
		bool operator < (const qnode & a) const{
			return dis<a.dis;
		}
	};
	priority_queue<qnode> que;
	ll f(int x){
		return 1LL*x*x;
	}
	ll dist(Point &a,Point &b){
		ll ret=0;
		for(int i=0; i<K; i++)
			ret+=f(a[i]-b[i]);
		return ret;
	}
	ll h(Node* o,Point &p){
		ll ret=0;
		for(int i=0; i<K; i++){
			if(o->mind[i]>p[i])
				ret+=f(o->mind[i]-p[i]);
			else if(p[i]>o->maxd[i])
				ret+=f(p[i]-o->maxd[i]);
		}
		return ret;
	}
	Node* newnode(const Point &p){
		ptr->key=p;
		ptr->ch[0]=ptr->ch[1]=null;
		for(int i=0; i<K; i++)
			ptr->maxd[i]=ptr->mind[i]=ptr->key[i];
        return ptr++;
	}
	void init(){
		ptr=pool;
		null=ptr++;
		null->ch[0]=null->ch[1]=null;
		for(int i=0; i<K; i++){
			null->mind[i]=inf;
			null->maxd[i]=-inf;
		}
	}
	void build(Node*& o,int l,int r,int dim){
		if(l>r) return;
		int mid=l+r>>1;
		D=dim;
		nth_element(a+l,a+mid,a+r+1);
		o=newnode(a[mid]);
		build(o->ch[0],l,mid-1,(dim+1)%K);
		build(o->ch[1],mid+1,r,(dim+1)%K);
		o->push_up();
	}
	void insert(Node*& o,Point p,int dim){
		if(o==null){
			o=newnode(p);
			return;
		}
		if(p[dim]<o->key[dim])
			insert(o->ch[0],p,(dim+1)%K);
		else
			insert(o->ch[1],p,(dim+1)%K);
		o->push_up();
	}
	void query(Node* o,Point &p,int k){
		ll cur=dist(o->key,p),dis[2]={INF,INF};
		if(que.size()<k)
			que.push({cur,o->key});
		else if(cur<que.top().dis){
			que.pop(); que.push({cur,o->key});
		}
		for(int i=0; i<2; i++)
			if(o->ch[i]!=null)
				dis[i]=h(o->ch[i],p);
		bool t=dis[0]>dis[1];
		for(int i=0; i<2; i++,t^=1)
            if(o->ch[t]!=null&&(que.size()<k)||dis[t]<que.top().dis)
                query(o->ch[t],p,k);
	}
};
KDT::Node* root;
KDT::Point* a = KDT::a;
int n,q,&K=KDT::K;
int main() {
    ios_base::sync_with_stdio(0);
    while(scanf("%d%d", &n, &K)==2) {
        for(int i=1; i<=n; ++i)
            for(int j=0; j<K; ++j)
                scanf("%d",&a[i][j]);
        KDT::init();
        KDT::build(root, 1, n, 0);
        scanf("%d", &q);
        while(q--){
            KDT::Point p; p.read();
            int k; scanf("%d",&k);
            KDT::query(root,p,k);
            printf("the closest %d points are:\n", k);
            vector<KDT::Point> v; v.reserve(k);
            while(KDT::que.size()){
                v.push_back(KDT::que.top().p);
                KDT::que.pop();
            }
            for(int i = k - 1; ~i; --i)
				v[i].write();
        }
    }

    return 0;
}
