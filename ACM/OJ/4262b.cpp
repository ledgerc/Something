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
const int maxn = 2e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct Bit{
	int n,treenum[maxn];
	void init(int k){
		n=k;
		memset(treenum,0,sizeof treenum);
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int i,int add){
		while(i<=n){
			treenum[i]+=add;
			i+=lowbit(i);
		}
	}
	int Sum(int i){
		int sum=0;
		while(i){
			sum+=treenum[i];
			i-=lowbit(i);
		}
		return sum;
	}
}bit;
int last[maxn];
char s[maxn];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	bit.init(n+10);
	memset(last,0,sizeof last);
	for(int i=1; i<=n; i++){
		int id = s[i]-'A';
		if(last[id]==0)
			bit.add(i,1);
		last[id]=i;
	}
	for(int i=0; i<26; i++){
		if(last[i]!=0)
			bit.add(last[i]+1,-1);
	}
	bool flag=false;
	for(int i=1; i<=n; i++){
		if(bit.Sum(i)>k){
			flag=true;
		}
	}
	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}
