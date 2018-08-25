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

#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)

int a[maxn];


void add(int k,int val){
	int l=LC(k),r=RC(k);
    if(a[k]==inf)
        a[k]=val;
    else{
        if(val>a[k])
            add(l,val);
        else
            add(r,val);
    }
}
int main(){
	int n; scanf("%d",&n);
	for(int i=0; i<=(1<<n); i++)
		a[i]=inf;
	int tmp;
	for(int i=1; i<=n; i++){
		scanf("%d",&tmp);
		add(1,tmp);
	//	cout<<"!"<<endl;
	}
	bool flag=false;
	tmp=1<<n;
	for(int i=0; i<tmp; i++){
		if(a[i]!=inf)
			printf("%s%d",i==1?"":" ",a[i]);
		else{
			if(i<=n)
				flag=true;
		}
	}
	cout<<endl;
	if(!flag)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}
