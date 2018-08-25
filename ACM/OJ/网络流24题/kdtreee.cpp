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

int n,K,cmpno;
struct Node{
    int x[10],l,r,id;
    bool operator < (const Node & b)const{
        return x[cmpno]<b.x[cmpno];
    }
};
ll dis(const Node &a,const Node &b){
    ll res=0;
    for(int i=0; i<K; i++)
        res+=(a.x[i]-b.x[i])*(a.x[i]-b.x[i]);
    return res;
}
struct kdtree{
    Node p[maxn];
    int build(int l,int r,int d){//d:????
        if(l>r)
            return 0;
        int mid=l+r>>1;
        nth_element(p+1,p+mid,p+r+1);
        p[mid].l=build(l,mid-1,(d+1)%K);
        p[mid].r=build(mid+1,r,(d+1)%K);
        return mid;
    }
    priority_queue<pair<ll,int> >que;
    void kth(int l,int r,Node tar,int k,int d){
        if(l>r)
            return;
        int mid=l+r>>1;
    	pr(l) pr(r) prln(mid)
        pair<ll,int> v = make_pair(dis(p[mid],tar),p[mid].id);
        if(que.size()==k&&v<que.top())
            que.pop();
        if(que.size()<k){
        	pr(v.first) prln(v.second)
            que.push(v);
		} 
        ll t=tar.x[d]-p[mid].x[d];
        if(t<=0){
            kth(l,mid-1,tar,k,(d+1)%K);
            if(que.top().first>t*t)
                kth(mid+1,r,tar,k,(d+1)%K);
        }
        else{
            kth(mid+1,l,tar,k,(d+1)%K);
            if(que.top().first>t*t)
                kth(l,mid-1,tar,k,(d+1)%K);
        }
    }
}kdt;
int k,ans[20];
Node a[maxn];
int main(){
    while(scanf("%d%d",&n,&K)!=EOF){
        for(int i=1; i<=n; i++){
            for(int j=0; j<K; j++)
                scanf("%d",&kdt.p[i].x[j]);
            kdt.p[i].id=i;
            a[i]=kdt.p[i];
        }
        kdt.build(1,n,0);
        int q,tot; scanf("%d",&q);
        Node tar;
        while(q--){
            for(int i=0; i<K; i++)
                scanf("%d",&tar.x[i]);
            scanf("%d",&k);
            printf("the closest %d point are:\n",k);
            for(int i=1; i<=k; i++)
                kdt.que.push(make_pair(1e18,-1));
            kdt.kth(1,n,tar,k,0);
            tot=0;
            while(!kdt.que.empty()){
                int id=(kdt.que.top()).second; kdt.que.pop();
                ans[tot++]=id;
            }
            for(int i=tot-1; i>=0; i--)
                for(int j=0; j<K; j++)
                    printf("%d%c",a[ans[i]].x[j],j==K-1?'\n':' ');
        }
    }
    return 0;
}
