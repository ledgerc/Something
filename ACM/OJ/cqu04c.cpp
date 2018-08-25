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
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


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
	int Sum(int i){
		int sum=0;
		while(i){
			sum+=treenum[i];
			i-=lowbit(i);
		}
		return sum;
	}
}L,R;
int n;
int op[maxn],l[maxn],r[maxn],id[maxn];
int cntid,cntl,cntr;
pair<int,int> a[maxn];
vector<int> G;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		G.clear();
		cntid=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d%d",&op[i],&l[i]);
			if(op[i]==0){
				r[i]=l[i]+(++cntid);
				G.push_back(l[i]); G.push_back(r[i]);
			}
		}
		sort(G.begin(),G.end()); G.erase(unique(G.begin(),G.end()),G.end());
		cntid=0;
		for(int i=1; i<=n; i++)
			if(op[i]==0){
				l[i]=lower_bound(G.begin(),G.end(),l[i])-G.begin()+1;
                r[i]=lower_bound(G.begin(),G.end(),r[i])-G.begin()+1;
				a[++cntid]={l[i],r[i]};
			}
		L.init(G.size()); R.init(G.size());
		for(int i=1; i<=n; i++){
			if(op[i]==0){
				printf("%d\n",R.Sum(r[i])-L.Sum(l[i]-1));
				L.add(l[i],1); R.add(r[i],1);
			}
			else{
			//	printf("%d %d\n",a[l[i]].first,a[l[i]].second);
				L.add(a[l[i]].first,-1);
				R.add(a[l[i]].second,-1);
			}
		}
	}
	return 0;
}
