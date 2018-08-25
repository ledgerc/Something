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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
int main(){
	int n,a[110];
	while(scanf("%d",&n)&&n){
		memset(a,0,sizeof a);
		int tmp;
		for(int i=0; i<n; i++){
			scanf("%d",&tmp);
			a[tmp]++;
		}
		bool flag=false;
		for(int i=0; i<100; i++){
			if(a[i]!=0){
				for(int j=0; j<a[i]; j++){
					if(flag)
						printf(" ");
					flag=true;
					printf("%d",i);
				}
			}
		}
		printf("\n");
	}
	return 0;
} 
