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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

void kmp_pre(char x[],int m,int nexts[]){
	int i,j;
	j=nexts[0]=-1;
	i=0;
	while(i<m){
		while(-1!=j&&x[i]!=x[j])
			j=nexts[j];
		if(x[++i]==x[++j])
			nexts[i]=nexts[j];
		else
			nexts[i]=j;
	}
}
int nexts[maxn];
int main(){
	char s[maxn]; ll m;
	scanf("%s%lld",s,&m);
	int len=strlen(s);
	kmp_pre(s,len,nexts);
	ll tmp=len-nexts[len];
	if(len%tmp!=0)
		tmp=len;
	cout<<(m/tmp)%mod<<endl;
}
