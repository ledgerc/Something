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

vector<int> v[maxn];//Լ�� 
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
		/*ö�� a == i, �� 1 �� n/2��Ȼ��ö�� x���� ax = i * j,
		�����������i * j < n ���У�������Ȼ����ȥ2��forѭ����ʵ���Ӷ��� 1/x ��1��n���֣����Ӷ� nln(n)
		Ȼ�����ÿ��ij��ɨһ���Ѿ�Ԥ�������vector[n - i*j]��
		������ڵ�ǰi�����Ԫ��vector[n - i*j][k] ����i ��û�б����Ϊi
		(�����ڵ�ǰa == iʱ�����b��û�г��ֹ�)����ans++��Ȼ����Ϊ f[..] = i; 
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
