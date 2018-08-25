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
const int maxn = 1e4+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
//bsaaabbbsa
int main(){
	int T; scanf("%d",&T);
	while(T--){
		char s[maxn]; scanf("%s",s);
		int count[30]; memset(count,0,sizeof count);
		int len=strlen(s),cnt=0;
		for(int i=0; i<len; i++)
			count[s[i]-'a']++;
		for(int i=0; i<26; i++)
			if(count[i]%2!=0)
				cnt++;
		if(cnt>1)
			puts("Impossible");
		else{
			int step=0;
			for(int i=0,j=len-1; i<j; i++,j--){
				int l,r;
				for(r=j; r>i; r--)
					if(s[r]==s[i])
						break;
				for(l=i; l<j; l++)
					if(s[l]==s[j])
						break;
				if(l-i<j-r){
					step+=l-i;
					for(int k=l-1; k>=i; k--)
						swap(s[k],s[k+1]);
				}
				else{
					step+=j-r;
					for(int k=r+1; k<=j; k++)
						swap(s[k],s[k-1]);
				}
			}
			printf("%d\n",step);
		}
	}
	return 0;
}
