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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


//c1是保存各项质量砝码可以组合的数目
//c2是中间量，保存每一次的情况
int c1[maxn],c2[maxn];
int infinitecalc(int n){
	for(int i=0; i<=n; i++){
		c1[i]=1; c2[i]=0;
	}
	for(int i=2; i<=n; i++){
		for(int j=0; j<=n; j++)
			for(int k=0; j+k<=n; k+=i){
				c2[k+j]+=c1[j];
			}
		for(int j=0; j<=n; j++){
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	return c1[n];
}
