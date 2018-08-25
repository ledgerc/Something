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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

/*
*Suffix Array
*�����㷨 O(n*logn)
*���������鳤��Ϊn,����0~n-1�У�������油һ��0
*da(str ,n+1,sa,rank,height,  ,   );//ע����n+1;
*���磺 *n   = 8; *num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };ע��num���һλΪ0����������0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]Ϊ��Чֵ��rank[n]�ض�Ϊ0��Чֵ
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]Ϊ��Чֵ��sa[0]�ض�Ϊn����Чֵ
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]Ϊ��Чֵ
*/
int t1[maxn],t2[maxn],c[maxn];;//��SA������Ҫ���м����������Ҫ��ֵ
//��������ַ�������str�����У���str[0]��str[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������ 
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i,j,p,*x=t1,*y=t2;
	//��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
	for(i=0; i<m; i++)
		c[i]=0;
	for(i=0; i<n; i++)
		c[x[i]=str[i]]++;
	for(i=1; i<m; i++)
		c[i]+=c[i-1];
	for(i=n-1; i>=0; i--)
		sa[--c[x[i]]]=i;
	for(j=1; j<=n; j<<=1){
		p=0;
		//ֱ������sa��������ڶ��ؼ���
		for(i=n-j; i<n; i++)
			y[p++]=i;//�����j�����ڶ��ؼ���Ϊ�յ���С
		for(i=0; i<n; i++)
			if(sa[i]>=j)
				y[p++]=sa[i]-j;
		//��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
		//���������һ�ؼ���
		for(i=0; i<m; i++)
			c[i]=0;
		for(i=0; i<n; i++)
			c[x[y[i]]]++;
		for(i=1; i<m; i++)
			c[i]+=c[i-1];
		for(i=n-1; i>=0; i--)
			sa[--c[x[y[i]]]]=y[i];
		//����sa��x��������µ�x����
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(i=1; i<n; i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p>=n)
			break;
		m=p;//�´λ�����������ֵ
	}
	int k=0;
	n--;
	for(i=0; i<=n; i++)
		rank[sa[i]]=i;
	for(i=0; i<n; i++){
		if(k)
			k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])
			k++;
		height[rank[i]]=k;
	}
}
int sa[maxn],rankx[maxn],height[maxn];
int s[maxn];
bool check(int n,int k,int t){
	int cnt=1;
	for(int i=2; i<=n; i++){
		if(height[i]>=t){
			cnt++;
			if(cnt>=k)
				return true;
		}
		else
			cnt=1;
	}
	return false;
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		int Max=0;
		for(int i=0; i<n; i++){
			scanf("%d",&s[i]);
			Max=max(Max,s[i]);
		}
		s[n]=0;
		da(s,sa,rankx,height,n,Max+1);
		int l=0,r=n;
		int ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(n,k,mid)){
				ans=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
