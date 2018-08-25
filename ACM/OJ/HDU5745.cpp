#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<bitset>
#include<set>
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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char a[maxn],b[maxn];
bitset <maxn> dp[2][3];
bitset <maxn> w[30];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int lena,lenb; scanf("%d%d",&lena,&lenb);
		scanf("%s%s",a,b);
		for(int i=0; i<26; i++)
			w[i].reset();
		for(int i=0; i<lena; i++)
			w[a[i]-'a'][i]=1;
		for(int i=0; i<2; i++)
			for(int j=0; j<3; j++)
				dp[i][j].reset();
		dp[0][1]=w[b[0]-'a'];
        if(lenb>1)
			dp[0][2]=w[b[1]-'a'];
		int now=0;
		for(int j=1; j<lenb; j++){
			now^=1;
			dp[now][0]=((dp[now^1][2])<<1)&w[b[j-1]-'a'];
            dp[now][1]=((dp[now^1][0]|dp[now^1][1])<<1) & w[b[j]-'a'];
            if(j<lenb-1)
				dp[now][2]=((dp[now^1][0]|dp[now^1][1])<<1)&w[b[j+1]-'a'];
		}
		for(int i=0; i<lena; i++){
			if(dp[now][0][i+lenb-1]||dp[now][1][i+lenb-1])
				printf("1");
			else
				printf("0");
		}
		cout<<endl;
	}
	return 0;
}
