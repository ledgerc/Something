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
const int maxn = 2e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m,k=0,l,ans=0;
string str[3];
map<string,int> mp;
map<int,string> pm;
struct Node{
	int fir,sec;
}a[maxn];
struct Edge{
	int to,next;
}edge[maxm];
int tot,head[maxn];
void init(){
	tot=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
bool vis[maxn];//染色标记，为true表示选择
int S[maxn],top;//栈 
bool dfs(int u){
	if(vis[u^1])
		return false;
	if(vis[u])
		return true;
	vis[u]=true;
	S[top++]=u;
	for(int i=head[u]; i!=-1; i=edge[i].next)
		if(!dfs(edge[i].to))
			return false;
	return true;
}
bool Twosat(int n){
	memset(vis,false,sizeof vis);
	for(int i=0; i<n; i+=2){
		if(vis[i]||vis[i^1])
			continue;
		top=0;
		if(!dfs(i)){
			while(top)
				vis[S[--top]]=false;
			if(!dfs(i^1))
				return false;
		}
	}
	return true;
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		cin>>str[1]>>str[2];
		string tmp1=str[1].substr(0,3);
		string tmp2=str[1].substr(0,2)+str[2][0];
		if(!mp[tmp1])
			mp[tmp1]=++k,pm[k]=tmp1;
        if(!mp[tmp2])
			mp[tmp2]=++k,pm[k]=tmp2;
        a[i].fir=mp[tmp1];
        a[i].sec=mp[tmp2];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(a[i].fir==a[j].fir){
                addedge(2*i-2,2*j-1);
                addedge(2*i-1,2*j-1);
            }
            if(a[i].fir==a[j].sec){
                addedge(2*i-2,2*j-2);
            }
            if(a[i].sec==a[j].fir){
                addedge(2*i-1,2*j-1);
            }
            if(a[i].sec==a[j].sec){
                addedge(2*i-1,2*j-2);
            }
        }
    }
    if(Twosat(2*n)) {
        puts("YES");
        for(int i = 0; i < 2*n; i++)
            if(vis[i])
                if((i+1)&1)
                    cout<<pm[a[(i+2)/2].fir]<<endl;
                else
                    cout<<pm[a[(i+1)/2].sec]<<endl;
    } 
    else puts("NO");
    return 0;
}
