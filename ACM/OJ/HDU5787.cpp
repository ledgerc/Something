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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
��λDP����ΪK<=5�����������Ҫ����������ǰλ��ǰ4λ���㹻�ˡ�
��Ϊdp[pos][p1][p2][p3][p4]��ʾ������ö��ȡ��posλ��posλ֮ǰ����λ�ֱ�Ϊp1,p2,p3,p4,p4��pos����һλ��
��ôp1~p4�ķ�Χ����0~9����������û��ǰ��0�ģ�
����k����Ϊ2,3,4������Ҫ���浽ǰ4λ��
����������p = 10����ʾ��һλ����Ҫ���棬
Ҳ�������ǰ��0��Ҳ���ǲ���Ҫ���档
��ôdfs��������д�� dfs(int pos,int p1,int p2,int p3,int p4,bool flag)
flag��ʾposλ�ܷ�ȡ��ȫ������λ(0~9)���ǻ��ܵ�ǰ�����λ��Ӱ��ֻ��ȡһ���֡�
��ôͳ����һλ��ʱ��Ϳ��Է�Ϊ���������
1��posλ֮ǰ��ȡ��0����posλҲȡ0��һֱ����ǰ���㡣
2��posλȡ��iȥ��p�ж�һ����û���ظ�������k���ж���Ҫ�Ƚϼ���p��,
�������������K = 3,��������������ȡ�ڶ�λ��i���p4��p3ȥ�Ƚ�һ�£�
����ֻ��p4������ȡ����ֵ������p3��ʱ��10������Ҳ�ǿ�������ͳ�Ƶġ�
*/
ll L,R;
int K;
ll dp[20][11][11][11][11];
int bit[20];
//����K���ж���Ҫ����Щp���Ƚ�
bool check(int a,int b,int c,int d,int now){
	if(K==2)
		return now!=d;
	else if(K==3)
		return now!=d&&now!=c;
	else if(K==4)
		return now!=d&&now!=c&&now!=b;
	else
		return now!=d&&now!=c&&now!=b&&now!=a;
}
ll dfs(int pos,int p1,int p2,int p3,int p4,bool flag){
	if(pos==0)//ȫ��ȡ�꣬��p4����10��˵��ȫ��ȡ��0����ȫ��Ϊǰ����
		return p4!=10;
	if(!flag&&dp[pos][p1][p2][p3][p4]!=-1)
		return dp[pos][p1][p2][p3][p4];
	int end=flag?bit[pos]:9;
	ll ans=0;
	for(int i=0; i<=end; i++){
		if(i==0&&p4==10)//posλ����֮ǰȫ��Ϊ0
			ans+=dfs(pos-1,10,10,10,10,flag&&i==end);
		else
			if(check(p1,p2,p3,p4,i))
				ans+=dfs(pos-1,p2,p3,p4,i,flag&&i==end);
	}
	if(!flag)
		dp[pos][p1][p2][p3][p4]=ans;
	return ans;
}
ll calc(ll x){
	if(x<=0)
		return 0;
	int len=0;
	while(x){
		bit[++len]=x%10;
		x/=10;
	}
	return dfs(len,10,10,10,10,1);
}
int main(){
	while(scanf("%lld%lld%lld",&L,&R,&K)!=EOF){
		memset(dp,-1,sizeof dp);
		printf("%lld\n",calc(R)-calc(L-1));
	}
	return 0;
}
