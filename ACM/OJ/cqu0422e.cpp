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
const int maxn = 3e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

vector<int> v[maxn];//约数 
int f[maxn];
void init(){
	for(int i=2; i<maxn; i++)
		for(int j=i; j<maxn; j+=i)
			v[j].push_back(i);
}
int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		/*枚举 a == i, 从 1 到 n/2，然后枚举 x，即 ax = i * j,
		这个必须满足i * j < n 才行，所以虽然看上去2层for循环其实复杂度是 1/x 从1到n积分，复杂度 nln(n)
		然后对于每个ij，扫一遍已经预处理出的vector[n - i*j]，
		如果对于当前i，这个元素vector[n - i*j][k] 大于i 且没有被标记为i
		(即对于当前a == i时，这个b还没有出现过)，就ans++，然后标记为 f[..] = i; 
		*/int ans=0;
		for(int i=1; i<=n/2; i++){
			for(int j=1; j<n; j++){
				if(i*j>n)
					break;
				int tmp=n-i*j;
				if(tmp<=i)
					break;
				for(int k=0; k<v[tmp].size(); k++){
					if(v[tmp][k]>i&&f[v[tmp][k]]!=i){
						f[v[tmp][k]]=i;
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
		/*
		ll sum=n-2;
		memset(flag,0,sizeof flag);
		for(int i=2; i<n; i++)
			for(int j=n-i; j>i; j-=i){
				for(auto &x:v[j]){
					if(x<=i)
						continue;
					if(flag[x]==i)
						continue;
					flag[x]=i;
					sum++;
				}
			}
		cout<<sum<<endl;*/
	}
	return 0;
}
