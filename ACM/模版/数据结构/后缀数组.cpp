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
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
*suffix array
*倍增算法  O(n*logn)
*待排序数组长度为n,放在0~n-1中，在最后面补一个0
*da(str ,n+1,sa,rank,height,  ,  );注意是n+1;
*例如
*n = 8;
*num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]为有效值，rank[n]必定为0无效值--你排第几 
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值------排第几的是谁
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值
*/
int t1[maxn],t2[maxn],c[maxn];
//求SA数组需要的中间变量，不需要赋值
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i,j,p,*x=t1,*y=t2;
	//第一轮基数排序，如果s的最大值很大，可改为快速排序
	for(i=0; i<m; i++) c[i]=0;
	for(i=0; i<n; i++) c[x[i]=str[i]]++;
	for(i=1; i<m; i++) c[i]+=c[i-1];
	for(i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
	for(j=1; j<=n; j<<=1){
		p = 0;
		 //直接利用sa数组排序第二关键字
		for(i=n-j; i<n; i++) y[p++]=i;//后面的j个数第二关键字为空的最小
		for(i=0; i<n; i++)
			if(sa[i]>=j)
				y[p++]=sa[i]-j;
		//这样数组y保存的就是按照第二关键字排序的结果
		//基数排序第一关键字
		for(i=0; i<m; i++) c[i]=0;
		for(i=0; i<n; i++) c[x[y[i]]]++;
		for(i=1; i<m; i++) c[i]+=c[i-1];
		for(i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
		//根据sa和x数组计算新的x数组
		swap(x,y);
		p=1; x[sa[0]]=0;
		for(i=1; i<n; i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p>=n)
			break;
		m=p;//下次基数排序的最大值
	}
	int k=0;
	n--;
	for(i=0; i<=n; i++) rank[sa[i]]=i;
	for(i=0; i<=n; i++){
		if(k)
			k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k]) k++;
		height[rank[i]]=k;
	}
}
int mm[maxn];
int best[20][maxn];
void initRMQ(int n){
	mm[0]=-1;
	for(int i=1; i<=n; i++)
		mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
	for(int i=1; i<=n; i++)
		best[0][i]=i;
	for(int i=1; i<=mm[n]; i++)
		for(int j=1; j+(1<<j)-1<=n; j++){
			int a=best[i-1][j],b=best[i-1][j+(1<<(i-1))];
			if(height[a]<height[b])
				best[i][j]=a;
			else
				best[i][j]=b;
		}
}
int askRMQ(int a,int b){
	int t; t=mm[b-a+1];
	b-=(1<<t)-1;
	a=best[t][a]; b=best[t][b];
    return height[a]<height[b]?a:b;
}
int lcp(int a,int b){
	a=rank[a],b=rank[b];
	if(a>b)
		swap(a,b);
	return height[askRMQ(a+1,b)];
}








/*
* 5.2 DC3 算法  da[]和str[]数组要开大三倍，相关数组也是三倍
* da[]和str[]数组要开大三倍，相关数组也是三倍
* 后缀数组
* DC3算法，复杂度O(n)
* 所有的相关数组都要开三倍
*/
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[maxn*3],wb[maxn*3],wv[maxn*3],wss[maxn*3];
int c0(int *r,int a,int b){
	return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b){
	if(k==2)
		return  r[a]<r[b]||(r[a]==r[b]&&c12(1,r,a+1,b+1));
	else
		return  r[a]<r[b]||(r[a]==r[b]&&wv[a+1]<wv[b+1]);
}
void sort(int *r,int *a,int *b,int n,int m){
	for(int i=0; i<n; i++) wv[i]=r[a[i]];
	for(int i=0; i<m; i++) wss[i]=0;
	for(int i=0; i<n; i++) wss[wv[i]]++;
	for(int i=0; i<m; i++) wss[i]+=wss[i-1];
	for(int i=n-1; i>=0; i--) b[--wss[wv[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m){
	int i,j,*rn=r+n;
	int *san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
	r[n]=r[n+1]=0;
	for(i=0; i<n; i++) if(i%3!=0) wa[tbc++]=i;
	sort(r+2,wa,wb,tbc,m);
	sort(r+1,wb,wa,tbc,m);
	sort(r,wa,wb,tbc,m);
	for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)
		rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
	if(p<tbc) dc3(rn,san,tbc,p);
	else for(i=0; i<tbc; i++) san[rn[i]]=i;
	for(i=0; i<tbc; i++) if(san[i]<tb) wb[ta++]=san[i]*3;
	if(n%3==1) wb[ta++]=n-1;
	sort(r,wb,wa,ta,m);
	for(i=0; i<tbc; i++) wv[wb[i]=G(san[i])]=i;
	for(i=0,j=0,p=0; i<ta&&j<tbc; p++) sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
	for(; i<ta; p++) sa[p]=wa[i++];
	for(; j<tbc; p++) sa[p]=wb[j++];
}
//str sa也要三倍
void da(int str[],int sa[],int rank[],int n,int m){
	for(int i=n; i<n*3; i++)
		str[i]=0;
	dc3(str,sa,n+1,n);
	int i,j,k=0;
	for(i=0; i<=n; i++) rank[sa[i]]=i;
	for(i=0; i<n; i++){
		if(k) k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k]) k++;
		height[rank[i]]=k;
	}
}



//http://blog.csdn.net/queuelovestack/article/details/53031731
