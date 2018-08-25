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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1000000;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

set<int> s;
queue<int> que;
int main(){
	s.clear(); s.insert(inf); s.insert(-inf);
	int ans=0;
	while(!que.empty())
		que.pop();
	int n,t; scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int a,b; scanf("%d%d",&a,&b);
		if(s.size()==2){
			t=a;
			s.insert(b);
		}
		else if(a==t)
			s.insert(b);
		else{
			int tmp=b;
			set<int>::iterator l,r;
			l=--s.lower_bound(tmp); r=s.lower_bound(tmp);
			int tmpl=*l,tmpr=*r;
			if(tmp-tmpl<=tmpr-tmp&&tmpl!=-inf){
				ans+=tmp-tmpl;
				s.erase(l);
			}
			else{
				ans+=tmpr-tmp;
				s.erase(r);
			}
			ans%=mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
