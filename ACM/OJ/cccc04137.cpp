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
#include<iostream>
using namespace std;


int s[maxn];
int n,top,total;
int cnt;
void dfs(int now){
	if(total==n){
		cout<<n<<"=";
		for(int i=0; i<top-1; i++)
			cout<<s[i]<<"+";
		cnt++;
		if(cnt%4==0||top==1){
			cout<<s[top-1]<<endl;
		}
		else
			cout<<s[top-1]<<";";
	}
	if(total>n)
		return;
	for(int i=now; i<=n; i++){
        total+=i;
		s[top]=i; top++;
		dfs(i);
		total-=i;
		top--;
	}
}
int main(){
 	cin>>n;
	cnt=0; top=0; total=0;
	dfs(1);
}
