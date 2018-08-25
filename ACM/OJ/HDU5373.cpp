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


int a[maxn];
int main(){
	int n,t; int kase=1;
	while(scanf("%d%d",&n,&t)!=EOF){
		if(n==-1) break;
		int sum=0,sum0=0,sum1=0,cnt=0;
		int flag=0;
		while(n>0){
			sum+=n%10;
			a[cnt++]=n%10;
			n/=10;
		}
		for(int i=cnt-1; i>=0; i--){
			if(flag%2==0) sum0+=a[i];
			else sum1+=a[i];
			flag++;
		}
		while(t--){
			cnt=0;
			int tmp=sum;
			while(tmp>0){
				sum+=tmp%10;
				a[cnt++]=tmp%10;
				tmp/=10;
			}
			for(int i=cnt-1; i>=0; i--){
				if(flag%2==0) sum0+=a[i];
				else sum1+=a[i];
				flag++;
			}
		}
		int ans=abs(sum0-sum1);
		if(ans%11==0) printf("Case #%d: Yes\n",kase++);
		else printf("Case #%d: No\n",kase++);
	}
	return 0;
}
