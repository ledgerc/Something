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
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
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

int n,a,b,c;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	int tmp,ans=0; c=0;
	for(int i=1; i<=n; i++){
		cin>>tmp;
		if(tmp==1){
			if(a>0)
				a--;
			else if(b>0)
				b--,c++;
			else if(c>0)
				c--;
			else
				ans++;
		}
		else{
			if(b>0)
				b--;
			else
				ans+=2;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
