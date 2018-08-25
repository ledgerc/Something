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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

const int MAXN = 50010;
const int MAXM = 50010;
struct Query{
	int L,R,id;
}node[MAXM];
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
struct Ans{
	long long a,b;
	void reduce(){
		long long d=gcd(a,b);
		a/=d; b/=d;
	}
}ans[MAXM];
int a[MAXN];
int num[MAXN];
int n,m,unit;
bool cmp(Query a,Query b){
	if(a.L/unit != b.L/unit)
		return a.L/unit < b.L/unit;
	else
		return a.R<b.R;
}
void work(){
	long long tmp=0;
	memset(num,0,sizeof num);
	int L=1,R=0;
	for(int i=0; i<m; i++){
		while(R<node[i].R){
			R++;
			tmp-=(long long)num[a[R]]*num[a[R]];
			num[a[R]]++;
			tmp+=(long long)num[a[R]]*num[a[R]];
		}
		while(R>node[i].R){
			tmp-=(long long)num[a[R]]*num[a[R]];
			num[a[R]]--;
			tmp+=(long long)num[a[R]]*num[a[R]];
			R--;
		}
		while(L<node[i].L){
			tmp-=(long long)num[a[L]]*num[a[L]];
			num[a[L]]--;
			tmp+=(long long)num[a[L]]*num[a[L]];
			L++;
		}
		while(L>node[i].L){
			L--;
			tmp-=(long long)num[a[L]]*num[a[L]];
			num[a[L]]++;
			tmp+=(long long)num[a[L]]*num[a[L]];
		}
		ans[node[i].id].a=tmp-(R-L+1);
		ans[node[i].id].b=(long long)(R-L+1)*(R-L);
		ans[node[i].id].reduce();
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=0; i<m; i++){
			node[i].id=i;
			scanf("%d%d",&node[i].L,&node[i].R);
		}
		unit=(int)sqrt(n);
		sort(node,node+m,cmp);
		work;
		for(int i=0; i<m; i++)
			printf("%lld/%lld\n",ans[i].a,ans[i].b);
	}
	return 0;
}
