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
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
#define bug() cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//求最长回文子串
/*
* abaaba len=6
* i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
* Ma[i]: $ # a # b # a # a $ b  #  a  #
* Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1
*/ 
int Ma[2*maxn];
int Mp[2*maxn];
void Manacher(int s[],int len){
	int l=0;
	Ma[l++]=-1; 
 	Ma[l++]=-1;
	for(int i=0; i<len; i++){
	 	Ma[l++]=s[i];
		Ma[l++]=-1;
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0; i<l; i++){
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])
			Mp[i]++;
		if(i+Mp[i]>mx){
			mx=i+Mp[i];
			id=i;
		}
	}
}
int s[maxn];
int main(){
//	freopen("in.txt","r",stdin);
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		int n; cin>>n;
		for(int i=0; i<n; i++)
			scanf("%d",&s[i]);
		Manacher(s,n);
		int ans=1;
		for(int i=2*1+1; i<=2*n-1; i+=2){
			for(int j=ans; j<=Mp[i]; j+=2){
				if(Mp[j+i-1]>=j)
					ans=j;
			}
		}
		printf("Case #%d: %d\n",kase,ans/2*3);
	}
	return 0;
}
