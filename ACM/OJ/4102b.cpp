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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int count(string a,string b){//b->a
	int cnt=0;
	int len=a.size();
	while(a!=b){
		char tmp=b[0];
		b.erase(b.begin());
		b.append(1,tmp);
		cnt++;
		if(cnt>len)
			return -1;
	}
	return cnt;
}
int main(){
	int n; cin>>n;
	string a[maxn];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int ansid,anscnt=inf;
	for(int i=0; i<n; i++){
		int sum=0;
		for(int j=0; j<n; j++){
			int tmp=count(a[i],a[j]);
			if(tmp==-1){
				cout<<"-1"<<endl;
				return 0;
			}
			sum+=tmp;
		}
		if(sum<anscnt){
			anscnt=sum;
			ansid=i;
		}
	}
	cout<<anscnt<<endl;
	return 0;
}
