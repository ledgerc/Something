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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m;
char s[maxn],t[maxn];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	int mn=inf,mnid;
	for(int i=0; i<=m-n; i++){
		int cnt=0;
		for(int j=1; j<=n; j++){
			if(s[j]!=t[j+i])
				cnt++;
		}
		if(mn>cnt){
			mn=cnt;
			mnid=i;
		}
	}
	printf("%d\n",mn);
	vector<int> ans;
	for(int j=1; j<=n; j++){
		if(s[j]!=t[j+mnid])
			ans.push_back(j);
	}
	for(int i=0; i<ans.size()-1; i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[ans.size()-1]);
}
