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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

using namespace std;
int n;
struct point{
    int x,y;
}a[maxn];
struct midpoint{
    int midx,midy;
}b[maxm];
bool cmp(midpoint x,midpoint y){
    if(x.midx!=y.midx)
    	return x.midx<y.midx;
    else
    	return x.midy<y.midy;
}
int main(){
	int T; cin>>T;
    for(int kase=1; kase<=T; kase++){
    	cin>>n;
        long long ans=0;
    	for(int i=0;i<n;i++){
    	    cin>>a[i].x>>a[i].y;
    	}
    	int cnt=0;
    	for(int i=0;i<n-1;i++){
    	    for(int j=i+1;j<n;j++){
    	        b[cnt].midx=a[i].x+a[j].x;
    	        b[cnt].midy=a[i].y+a[j].y;
    	        cnt++;
    	    }
    	}
    	sort(b,b+cnt,cmp);
    	vector<int> c;
    	int cntb=1;
    	for(int i=0; i<cnt-1; i++){
    		if(b[i].midx==b[i+1].midx&&b[i].midy==b[i+1].midy)
    			cntb++;
    		else{
    			c.push_back(cntb);
    			cntb=1;
    		}
		}
		for(int i=0; i<c.size(); i++){
			ans+=c[i]*(c[i]-1)/2;
		}
		printf("Case %d: %d\n",kase,ans);
	}
    return 0;
 }
