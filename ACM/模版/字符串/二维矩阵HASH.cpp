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
const int maxn = 4e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
const int hashmod = 1e6+7;

int n,m;
char a[507][507];
struct HashMap{
	ull a[maxn];
	int size,head[hashmod],nxt[maxn];
	void init(){
		size=0;
		memset(head,-1,sizeof head);
	}
	bool find(ull val){
		int tmp = (val%hashmod+hashmod)%hashmod;
		for(int i = head[tmp]; i!=-1; i=nxt[i]){
			if(val==a[i])
				return true;
		}
		return false;
	}
	void add(ull val){
		int tmp = (val%hashmod+hashmod)%hashmod;
		if(find(val)) return;
		a[size]=val;
		nxt[size]=head[tmp];
		head[tmp]=size++;
	}
}ha;
ull h[507][507];
ull x[507*507];
bool check(int mid){
	ha.init();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int x1=i,y1=j;
            int xx=i+mid-1,yy=j+mid-1;
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
            {
                unsigned long long val=h[xx][yy]+h[x1-1][y1-1]-h[xx][y1-1]-h[x1-1][yy];
                val*=x[(n-i)*m+m-j];
                if(ha.find(val))
					return true;
                else
					ha.add(val);
            }
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%s",a[i]+1);
	x[0]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			h[i][j]=h[i][j-1]+x[(i-1)*m+j-1]*(a[i][j]-'a');
			x[(i-1)*m+j]=x[(i-1)*m+j-1]*19260817;
		}
	for(int j=1; j<=m; j++)
		for(int i=1; i<=n; i++)
			h[i][j]=h[i][j]+h[i-1][j];
	int ans=0,l=0,r=min(n,m);
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
