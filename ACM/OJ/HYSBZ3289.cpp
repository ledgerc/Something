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
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 5e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,unit;
int a[maxn],b[maxn];
int num[maxn];

struct Bit{
	int n,treenum[maxn];
	void init(int k){
		n=k;
		memset(treenum,0,sizeof treenum);
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int i,int add){
		while(i<=n){
			treenum[i]+=add;
			i+=lowbit(i);
		}
	}
	int sum(int i){
		int sum=0;
		while(i){
			sum+=treenum[i];
			i-=lowbit(i);
		}
		return sum;
	}
}bit;

struct Query{
	int l,r,id;
}node[maxn];
ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
bool cmp(Query a,Query b){
	if(a.l/unit!=b.l/unit)
		return a.l/unit<b.l/unit;
	else
		return a.r<b.r;
}


int ans[maxn];
void solve(){
	ll temp=0;
	memset(num,0,sizeof num);
	int l=1,r=0;
	for(int i=0; i<m; i++){
		while(r<node[i].r){
			r++;
			temp+=r-l-bit.sum(a[r]);
			bit.add(a[r],1);
		}
		while(r>node[i].r){
			bit.add(a[r],-1);
			temp-=r-l-bit.sum(a[r]);
			r--;
		}
		while(l<node[i].l){
			bit.add(a[l],-1);
			temp-=bit.sum(a[l]-1);
			l++;
		}
		while(l>node[i].l){
			l--;
			temp+=bit.sum(a[l]-1);
			bit.add(a[l],1);
		}
	//	printf("Debug: %d %d %d\n",l,r,temp);
		ans[node[i].id]=temp;
	}
}
int main(){
	scanf("%d",&n);
	bit.init(n);
	int cnt=0; vector<int> g;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1])
			g.push_back(a[i]);
	}
	sort(g.begin(),g.end());
	for(int i=1; i<=n; i++)
		a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+1;
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d%d",&node[i].l,&node[i].r);
		node[i].id=i;
	}
	unit=(int)sqrt(n);
	sort(node,node+m,cmp);
	solve();
	for(int i=0; i<m; i++)
		printf("%d\n",ans[i]);
	return 0;
}
