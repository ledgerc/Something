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
*倍增算法 O(n*logn)
*待排序数组长度为n,放在0~n-1中，在最后面补一个0
*da(str ,n+1,sa,rank,height,  ,   );//注意是n+1;
*例如： *n   = 8; *num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]为有效值，rank[n]必定为0无效值
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值
*/
int t1[maxn],t2[maxn],c[maxn];;//求SA数组需要的中间变量，不需要赋值
//待排序的字符串放在str数组中，从str[0]到str[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中 
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i,j,p,*x=t1,*y=t2;
	//第一轮基数排序，如果s的最大值很大，可改为快速排序
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
		//直接利用sa数组排序第二关键字
		for(i=n-j; i<n; i++)
			y[p++]=i;//后面的j个数第二关键字为空的最小
		for(i=0; i<n; i++)
			if(sa[i]>=j)
				y[p++]=sa[i]-j;
		//这样数组y保存的就是按照第二关键字排序的结果
		//基数排序第一关键字
		for(i=0; i<m; i++)
			c[i]=0;
		for(i=0; i<n; i++)
			c[x[y[i]]]++;
		for(i=1; i<m; i++)
			c[i]+=c[i-1];
		for(i=n-1; i>=0; i--)
			sa[--c[x[y[i]]]]=y[i];
		//根据sa和x数组计算新的x数组
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(i=1; i<n; i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p>=n)
			break;
		m=p;//下次基数排序的最大值
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
