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

bool cmp(int a,int b){
	return a>b;
}
int main(){
	map<int,bool> mp;
	int n; cin>>n;
	bool flag=false;
	bool maybe=false;
	int a[maxn],b[maxn];
	for(int i=0; i<n; i++){
		int tmpa,tmpb; cin>>tmpa>>tmpb;
		a[i]=b[i]=tmpa;
		if(tmpa!=tmpb)
			flag=true;
	}
	if(flag)
		cout<<"rated"<<endl;
	else{
		sort(b,b+n,cmp);
		for(int i=0; i<n; i++)
			if(a[i]!=b[i])
				maybe=true;
		if(!maybe)
			cout<<"maybe"<<endl;
		else
			cout<<"unrated"<<endl;
	}
	return 0;
}
