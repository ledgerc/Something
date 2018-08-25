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
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 5e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
ĳ�죬Lostmonkey������һ�ֳ�������װ�ã�Ϊ������������������ǰ�԰ڣ�
������С����һ�������Ϸ��
��Ϸһ��ʼ��Lostmonkey�ڵ�������һ��ֱ�߰���n��װ�ã�
ÿ��װ���趨��ʼ����ϵ��ki��������ﵽ��i��װ��ʱ��
��������ki�����ﵽ��i+ki��װ�ã��������ڵ�i+ki��װ�ã�

i=1����Ҫ�����j�����������κ󱻵��ɣ�
��i=2�򻹻�������һ��������k����ʾ��j������װ�õ�ϵ�����޸ĳ�k��
*/ 
int n,q;
//�����ÿ���Ҫ�Ĳ��� ������һ������ĸ��� 
int a[maxn],cnt[maxn],to[maxn];
//�����ڵڼ�����/�鳤/���� �����  ���Ҷ� 
int belong[maxn],block,num,l[maxn],r[maxn];
//�±��1��ʼ 
void Build(){
	block=(int)sqrt(n+0.5);
	num=n/block;
	if(n%block)
		num++;
	for(int i=1; i<=num; i++){
		l[i]=(i-1)*block+1;
		r[i]=i*block;
	}
	r[num]=n;//���Ҷ˶˵����
	for(int i=1; i<=n; i++)
		belong[i]=((i-1)/block)+1;
	for(int i=num; i>0; i--){
		for(int j=r[i]; j>=l[i]; j--){
			if(j+a[j]>r[i]){
				cnt[j]=1; to[j]=min(n+1,j+a[j]);
			}
			else{
				cnt[j]=cnt[j+a[j]]+1;
				to[j]=min(n+1,to[j+a[j]]);
			}
		}
	}
}
void modify(int pos,int val){
	a[pos]=val;
	for(int i=pos; i>=l[belong[pos]]; i--){
		if(i+a[i]>r[belong[pos]]){
			cnt[i]=1;
			to[i]=min(n+1,i+a[i]);
		}
		else{
			cnt[i]=cnt[i+a[i]]+1;
			to[i]=min(n+1,to[i+a[i]]);
		}
	}
}
int query(int pos){
	int ans=0;
	for(int i=pos; i<=n; i=to[i])
		ans+=cnt[i];
	return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		Build();
		scanf("%d",&q);
		int op,pos,v;
		for(int i=0; i<q; i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%d",&pos); pos++;
				printf("%d\n",query(pos));
			}
			else{
				scanf("%d%d",&pos,&v); pos++;
				modify(pos,v);
			}
		}
	}
	return 0;
}
