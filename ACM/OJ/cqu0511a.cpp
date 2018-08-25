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
//返回x在y中出现的次数，可以重叠 
int nexts[maxn];
int KMP(char x[],int m,char y[],int n){//x是模式串，y是主串 
	int i,j;
	int ans=0;
	kmp_pre(x,m,nexts);
	i=j=0;
	int tmp=0;
	while(i<n){
		while(-1!=j && y[i]!=x[j])
			j=nexts[j];
		i++;j++;
		if(j>tmp){
			tmp=j;
			ans=i-j;
		}
		if(j>=m){
			break;
		}
	}
	return ans;
}
int main(){
	int n; cin>>n;
	char a[maxn],b[maxn*2];
	scanf("%s%s",a,b);
	copy(b,b+n,b+n);
	cout<<KMP(a,n,b,2*n)<<endl;
	return 0;
}
