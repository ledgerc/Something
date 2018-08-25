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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int c[maxn][maxn];
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y,int val){
    for(int i=x;i<=n;i+=lowbit(i))
      for(int j=y;j<=n;j+=lowbit(j))
         c[i][j]+=val;
}
int sum(int x,int y){
    int s=0;
    for(int i=x;i>0;i-=lowbit(i))
      for(int j=y;j>0;j-=lowbit(j))
         s+=c[i][j];
    return s;
}
int main(){
	int q;
    while(scanf("%d%d",&n,&q)!=EOF){
    	memset(c,0,sizeof c);
        int tmp;
     //   cout<<"=="<<c[1][1]<<endl;
        for(int i=1; i<=n; i++)
        	for(int j=1; j<=n; j++){
        		scanf("%d",&tmp);
        		add(i,j,tmp);
			}
		int L,B,R,T;
		while(q--){
            scanf("%d%d%d%d",&L,&B,&R,&T);
            L--,R--,B--,T--;
			printf("%d\n",sum(R+1,T+1)-sum(R+1,B)-sum(L,T+1)+sum(L,B));
		}
    }
    return 0;
}
