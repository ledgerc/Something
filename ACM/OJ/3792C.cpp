#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
unsigned long long int n,m,k,a[200002],b[200002],c[200002],d[200002],x,s,i,j,l,r,mid,an;
int main(){
    cin>>n>>m>>k;
    cin>>x>>s;
    for(i=1;i<=m;i++)
    	cin>>a[i];
    for(i=1;i<=m;i++)
    	cin>>b[i];
    for(i=1;i<=k;i++)
    	cin>>c[i];
    for(i=1;i<=k;i++)
    	cin>>d[i];
    b[0]=c[0]=d[0]=0;
    a[0]=x;
    an=x*n;
    for(i=0;i<=m;i++){
        if(a[i]>x||b[i]>s)
            continue;
        l=1;r=k;
        j=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(d[mid]+b[i]>s)
                r=mid-1;
        else{
            l=mid+1;
            j=max(mid,j);
            }
        }
                an=min(an,(n-c[j])*a[i]);
    }
    cout<<an;
    return 0;
}
