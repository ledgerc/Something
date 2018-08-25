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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
char s[maxn];
int main(){
	scanf("%s",s+3);
	s[1]=s[2]='0';
	for(int i=1; s[i]>='0'; i++)
		for(int j=i+1; s[j]>='0'; j++)
			for(int k=j+1; s[k]>='0'; k++){
				int tmp=(100*(s[i]-'0'))+(10*(s[j]-'0'))+s[k]-'0';
				if(tmp%8==0){
					cout<<"YES"<<endl;
					cout<<tmp<<endl;
					return 0;
				}
			}
	cout<<"NO"<<endl;
	return 0;
}
