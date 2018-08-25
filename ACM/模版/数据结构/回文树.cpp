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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
const int sigma_size = 26;

struct PalindromicTree{
	//表示编号为i的节点表示的回文串在两边添加字符c以后变成的回文串的编号
	int next[maxn][sigma_size];
	//表示节点i失配以后跳转不等于自身的节点i表示的回文串的最长后缀回文串
	int fail[maxn];
	int cnt[maxn];//表示节点i表示的本质不同的串的个数
	//表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
	int num[maxn];
	int len[maxn];//表示结点i表示的回文串长度 
	int s[maxn];//存放添加的字符 
	int last;//指向上一个字符所在的节点
	int n,p;//字符数组指针 节点指针
	
	int newnode(int l){
		for(int i=0; i<sigma_size; i++)
			next[p][i]=0;
		cnt[p]=num[p]=0;
		len[p]=l;
		return p++;
	}
	void init(){
		p=0;
		//0表示偶数长度串的根和1表示奇数长度串的根
		newnode(0);
		newnode(-1);
		last=0;
		n=0;
		s[n]=-1;////开头放一个字符集中没有的字符，减少特判
		fail[0]=1;
	}
	int Getfail(int x){
		while(s[n-len[x]-1]!=s[n])
			x=fail[x];
		return x;
	}
	void insert(int c){
		c-='a';
		s[++n]=c;
		int cur=Getfail(last);//通过上一个回文串找这个回文串的匹配位置
		if(!next[cur][c]){//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
			int now=newnode(len[cur]+2);
			fail[now]=next[Getfail(fail[cur])][c];
			next[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last=next[cur][c];
		cnt[last]++;
	}
	void count(){
		//父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串
		for(int i=p-1; i>=0; i--)
			cnt[fail[i]]+=cnt[i];
	}
};
int main(){
	
}
