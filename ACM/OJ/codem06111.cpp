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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int m;
map<int,int> mp;
int main(){
	while(scanf("%d",&m)!=EOF){
		mp.clear();
		int cnt=0;
		char op[2]; int x;
		bool flag=false;
		int ans;
		for(int i=0; i<m; i++){
			scanf("%s",op);
			if(op[0]=='?')
				cnt++;
			else if(op[0]=='I'){
				scanf("%d",&x);
                if(mp[x]==0)
					mp[x]++;
               	else if(!flag){
               		ans=i+1;
                    flag=true;
                }
			}
			else if(op[0]=='O'){
				scanf("%d",&x);
				if(mp[x]==0){
					if(cnt>0)
						cnt--;
					else if(!flag){
						ans=i+1;
						flag=true;
					}
				}
				else
					mp[x]--;
			}
		}
		if(!flag)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

