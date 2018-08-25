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

int n,k;
int a[maxn],pos[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	if(k>=n){
		for(int i=n; i>1; i--)
			printf("%d ",i);
		printf("1\n");
		return 0;
	}
	int now=n;
	for(int i=1; i<=n; i++){
		if(a[i]==now){
			now--;
			continue;
		}
		else{
			int j=pos[now];
			a[j]=a[i];
			a[i]=now;
			pos[a[i]]=i; pos[a[j]]=j;
			now--; k--;
			if(k==0)
				break;
		}
	}
	for(int i=1; i<n; i++)
		printf("%d ",a[i]);
	printf("%d",a[n]);
	return 0;
}
