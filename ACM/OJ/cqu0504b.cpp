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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int main(){
	int T; cin>>T;
	while(T--){
		char a[maxn],b[maxn];
		scanf("%s%s",a+1,b+1);
		int lena=strlen(a+1),lenb=strlen(b+1);
		bool dp[maxn][maxn];//a[i]=====b[j]
		memset(dp,false,sizeof dp);
		for(int i=0; i<=lena; i++)
			dp[i][0]=true;
	//	for(int j=0; j<=lenb; j++)
	//		dp[0][j]=true;
		for(int i=1; i<=lena; i++){
			for(int j=1; j<=lenb+1; j++){
				//can a[i] change into b[j]?
				//only on the base that a[i-1] can change into b[j-1]
				if(dp[i-1][j-1]){
					//if can
					if('a'<=a[i]&&a[i]<='z')
						dp[i][j-1]=true;
					if(a[i]==b[j])
						dp[i][j]=true;
					if(a[i]-32==b[j])
						dp[i][j]=true;
				}
			}
		}
	//	for(int i=1; i<=lena; i++){
	//		for(int j=1; j<=lenb; j++)
	//			cout<<dp[i][j]<<" ";
	//		cout<<endl;
	//	}
		if(dp[lena][lenb])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
