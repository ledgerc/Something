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

int main(){
	int T; cin>>T;
	while(T--){
		char s[maxn]; scanf("%s",s);
		int len=strlen(s);
		int cnt=0;
		for(int i=0; i<len-2; i++){
			if(s[i]=='c'&&s[i+1]=='a'&&s[i+2]=='t')
				cnt++;
			if(s[i]=='d'&&s[i+1]=='o'&&s[i+2]=='g')
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
