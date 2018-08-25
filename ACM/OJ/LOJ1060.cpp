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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,cnt[30];
ll k,fac[30]={1};
char s[30];
int main(){
	int T; cin>>T;
	for(int i=1; i<=25; i++)
		fac[i]=fac[i-1]*i;
	for(int kase=1; kase<=T; kase++){
		scanf("%s%d",s+1,&k);
		n=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		for(int i=1; i<=n; i++)
			cnt[s[i]-'a']++;
		printf("Case %d: ",kase);
		
		ll maxk=fac[n];
		for(int i=0; i<26; i++)
			maxk/=fac[cnt[i]];
		if(k>maxk){
			cout<<"Impossible"<<endl;
			continue;
		}
		for(int i=1; i<=n; i++){
			for(int j=0; j<26; j++){
				if(!cnt[j])
					continue;
				cnt[j]--;
				ll tmp=fac[n-i];
				for(int k=0; k<26; k++)
					tmp/=fac[cnt[k]];
				if(k<=tmp){
					printf("%c",'a'+j);
					break;
				}
				cnt[j]++;
				k-=tmp;
			}
		}
		cout<<endl;
	}
	return 0;
}
