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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
char s[maxn];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int a[30];
	for(int i=0; i<30; i++)
		a[i]=inf;
	for(int i=1; i<=n; i++){
		int tmp=s[i]-'a';
		if(a[tmp]==inf)
			a[tmp]=i;
	}
	for(int i=1; i<26; i++)
		if(a[i]<a[i-1]){
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
