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
void update(int x,int a,int w,double &l,double &r){
	if(a==0){
		if(x<=0||x>=w)
			r=l-1;
	}
	else if(a>0){
		l=max(l,-(double)x/a);
		r=min(r,double(w-x)/a);
	}
	else{
		l=max(l,(double)(w-x)/a);
		r=min(r,-(double)x/a);
	}
}
struct Event{
	double x;
	int type;
	bool operator < (const Event &a){
		return x<a.x||(x==a.x&&type > a.type);
	}
}event[maxn*2];
int main(){
	int T; cin>>T;
	while(T--){
		int w,h,n,e=0;
		cin>>w>>h>>n;
		for(int i=0; i<n; i++){
			int x,y,a,b;
			cin>>x>>y>>a>>b;
			double l=0,r=1e9;
			update(x,a,w,l,r);
			update(y,b,h,l,r);
			if(r>l){
				event[e++]=(Event){l,0};
				event[e++]=(Event){r,1};
			}
		}
		sort(event,event+e);
		int cnt=0,ans=0;
		for(int i=0; i<e; i++){
			if(event[i].type==0)
				ans=max(ans,++cnt);
			else
				cnt--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
