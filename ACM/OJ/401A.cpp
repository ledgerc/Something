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

int n,x;
int main(){
	cin>>n>>x;
	n%=6;
	int a[10][10]={{0,1,2,2,1,0},{1,0,0,1,2,2},{2,2,1,0,0,1}};
	for(int i=0; i<3; i++){
		if(a[i][n]==x){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
