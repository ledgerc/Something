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
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char a[maxn],b[maxn];
int len1,len2;
int c[maxn];
map<int,int> mp;
bool check(int mid){
	mp.clear();
	for(int i=0; i<=mid; i++)
		mp[c[i]-1]=1;
	int tmp1=0,tmp2=0;
	for(int j=0; j<len2; j++){
		while(tmp1<len1){
			if(a[tmp1]==b[j]&&mp[tmp1]==0){
				tmp2++;
				tmp1++;
				break;
			}
			else
				tmp1++;
		}
	}
	if(tmp2==len2)
		return true;
	return false;
}
int main(){
	scanf("%s%s",a,b);
	len1=strlen(a),len2=strlen(b);
	for(int i=0; i<len1; i++)
		scanf("%d",&c[i]);
	int l=0,r=len1-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",r+1);
	return 0;
}
