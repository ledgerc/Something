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
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
int dp[maxn];//以ai为末尾的LCS的长度
int a[maxn];
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0; i<n; i++)
			cin>>a[i];
		dp[0]=a[0];
		int mx=dp[0];
		for(int i=1; i<n; i++){
			int sum=a[i];
			for(int j=0; j<i; j++)
				if(a[i]>a[j])
					sum=max(sum,dp[j]+a[i]);
			dp[i]=sum;
			mx=max(mx,dp[i]);
		}
		cout<<mx<<endl;
	}
	return 0;
}
