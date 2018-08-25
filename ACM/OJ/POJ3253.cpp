#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1000001;
int n,a[maxn],i,j,k,b;
long long sum,ans=0;
int main()
{
	scanf("%d",&n);
	int l=n;
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	k=1;
	for(i=1;i<n;++i)
	{
		sum=a[k]+a[k+1];
		ans+=sum;
		k+=2;
		b=k;
		while(a[k]<sum&&k<=l)k++;
		for(j=l+1;j>k;--j)a[j]=a[j-1];
		a[k]=sum;
		l++;
		k=b;
	}
	printf("%lld\n",ans);
}

