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
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
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

string a[maxn];
int main(){
	int n; scanf("%d",&n);
	string tmp; int len=-1;
	for(int i=1; i<=n; i++){
		cin>>tmp;
		int num; scanf("%d",&num);
		for(int j=1; j<=num; j++){
			int pos; scanf("%d",&pos);
			int tmplen=tmp.length();
			len=max(len,pos+tmplen-1);
			if(tmp.length()>a[pos].length())
				a[pos]=tmp;
		}
	}
	int pos;
	prln(len)
	for(int i=1; i<=len ;i++)
		cout<<"i: "<<i<<" "<<a[i]<<endl;
	
	for(pos=1; pos<=len; ){
		cout<<a[pos]<<endl;
		cout<<pos<<" "<<a[pos].length()<<endl;
		pos+=a[pos].length();
		if(pos>=6)
			break;
	}
	
	puts("");
	return 0;
}
