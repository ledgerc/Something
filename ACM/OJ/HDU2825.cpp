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
const int mod = 20090717;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,k;
int dp[30][110][1<<10];
int num[5000];
struct Trie{
	int next[110][26],fail[110],end[110];
	int root,L;
	int newnode(){
		for(int i=0; i<26; i++)
			next[L][i]=-1;
		end[L++]=0;
		return L-1;
	}
	void init(){
		L=0;
		root=newnode();
	}
	void insert(char buf[],int id){
		int len=strlen(buf);
		int now=root;
		for(int i=0; i<len; i++){
			if(next[now][buf[i]-'a']==-1)
				next[now][buf[i]-'a']=newnode();
			now=next[now][buf[i]-'a'];
		}
		end[now]|=(1<<id);
	}
	void build(){
		queue<int> Q;
		fail[root]=root;
		for(int i=0; i<26; i++)
			if(next[root][i]==-1)
				next[root][i]=root;
			else{
				fail[next[root][i]]=root;
				Q.push(next[root][i]);
			}
		while(!Q.empty()){
			int now=Q.front();
			Q.pop();
			end[now]|=end[fail[now]];
			for(int i=0; i<26; i++){
				if(next[now][i]==-1)
					next[now][i]=next[fail[now]][i];
				else{
					fail[next[now][i]]=next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	int solve(){
		for(int i=0; i<=n; i++)
			for(int j=0; j<L; j++)
				for(int p=0; p<(1<<m); p++)
					dp[i][j][p]=0;
		dp[0][0][0]=1;
		for(int i=0; i<n; i++)
			for(int j=0; j<L; j++)
				for(int p=0; p<(1<<m); p++){
					if(dp[i][j][p]>0){
						for(int x=0; x<26; x++){
							int newi=i+1,newj=next[j][x],newp=(p|end[newj]);
							dp[newi][newj][newp]+=dp[i][j][p];
							dp[newi][newj][newp]%=mod;
						}
					}
				}
		int ans=0;
		for(int p=0; p<(1<<m); p++){
			if(num[p]<k)
				continue;
			for(int i=0; i<L; i++)
				ans=(ans+dp[n][i][p])%mod;
		}
		return ans;
	}
};
char buf[20];
Trie ac;
int main(){
	for(int i=0; i<(1<<10); i++){
		num[i]=0;
		for(int j=0; j<10; j++)
			if(i&(1<<j))
				num[i]++;
	}
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		if(n==0&&m==0&&k==0)
			break;
		ac.init();
		for(int i=0; i<m; i++){
			scanf("%s",buf);
			ac.insert(buf,i);
		}
		ac.build();
		printf("%d\n",ac.solve());
	}
	return 0;
}

