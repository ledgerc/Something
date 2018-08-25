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
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int a[maxn];
int main(){
	int b,q,l,m,tmp;
	scanf("%d%d%d%d",&b,&q,&l,&m);
	map<int,bool> mp;
	for(int i=0; i<m; i++){
		sc(tmp);
		mp[tmp]=true;
	}
	if(b==0){
		if(mp[0]) cout<<"0"<<endl;
		else cout<<"inf"<<endl;
		return 0;
	}
	if(abs(b)>l){
		cout<<"0"<<endl;
		return 0;
	}
	if(q==0){
		if(!mp[0]) cout<<"inf"<<endl;
		else if(abs(b)<=l&&!mp[b]) cout<<"1"<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	if(q==1){
		if(abs(b)<=l&&!mp[b]) cout<<"inf"<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	if(q==-1){
		int cnt=0;
		if(abs(b)<=l&&!mp[b]) cnt++;
		if(abs(b)<=l&&!mp[-b]) cnt++;
		if(cnt==0) cout<<"0"<<endl;
		else cout<<"inf"<<endl;
		return 0;
	}
	int cnt=0;
	if(abs(b)<=l&&!mp[b]) cnt++;
	while(1LL*abs(q)*abs(b)<=(ll)l){
		b*=q;
		if(abs(b)<=l&&!mp[b]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
