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
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 20071027;
const double EPS = 1e-10;
const double Pi = acos(-1.0);
const int maxn = 1e6+10;
const int MAX = 26;
const int maxnode = maxn;
const int sigma_size = 2;
struct Trie{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	void clear(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
	}
	int idx(int c){
		return c;
	}
	void insert(int s){
		int u=0;
		for(int i=30; i>=0; i--){
			int id=(s>>i)&1;
			if(ch[u][id]==0){
				ch[u][id]=sz;
				memset(ch[sz],0,sizeof ch[sz]);
				val[sz++]=0;
			}
			u=ch[u][id];
			val[u]++;
		}
	}
	int search(int s){
		int u=0,ans=0;
		for(int i=30; i>=0; i--){
			int tmp=(s>>i)&1;
			if(tmp==0){
				if(ch[u][1]){
					u=ch[u][1],ans+=(1<<i);
				}
				else if(ch[u][0])
					u=ch[u][0];
				else
					break;;
			}else{
				if(ch[u][0]){
					u=ch[u][0],ans+=(1<<i);
				}
				else if(ch[u][1])
					u=ch[u][1];
				else
					break;
			}
		}
		return ans;
	}
};
Trie trie1;
Trie trie2;
int main(){
	trie1.clear();
	trie2.clear();
	int n; int a[maxn],b[maxn];
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		b[n-i+1]=a[i];
	}
	
	int lx[maxn],rx[maxn];
	memset(lx,-1,sizeof lx);
	memset(rx,-1,sizeof rx);
	trie1.insert(0); trie2.insert(0);
	int sum1=0,sum2=0;
	for(int i=1; i<=n; i++){
		sum1^=a[i];
		lx[i]=max(lx[i-1],trie1.search(sum1));
		trie1.insert(sum1);
		
		sum2^=b[i];
		rx[i]=max(rx[i-1],trie2.search(sum2));
		trie2.insert(sum2);
	}
	int ans=-1;
	for(int i=1; i<=n; i++){
	//	cout<<lx[i]<<endl;
		int tmp=lx[i]+rx[n-i];
		ans=max(ans,tmp);
	}
 	cout<<ans<<endl;	
}
/*
4
1 3 1 1
*/
