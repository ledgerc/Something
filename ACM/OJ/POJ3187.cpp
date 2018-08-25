#include<iostream>
using namespace std;
const int maxn = 11;
int n,sum,num[maxn],c[maxn];
bool vis[maxn],flag;
int findc(int a,int n){
	int i=1,ans=1;
	while(i<=a){
		ans=ans*n/i;
		n--;i++;
	}
	return ans;
} 
void dfs(int dep,int val){
    if(val>sum) return;
    if(dep==n){
        if(val==sum&&!flag){
            flag=true;
            for(int i=0; i<n; i++)
                cout<<num[i]<<' ';
            cout<<endl;
        }
        return;
    }
    for(int v=1; v<=n&&!flag; v++)
        if(!vis[v]){
            num[dep]=v;
            vis[v]=true;
            dfs(dep+1,val+c[dep]*v);
            vis[v]=false;
        }
}
int main(){
    cin>>n>>sum;
    for(int i=0; i<n; i++)
        c[i]=findc(i,n-1); 
    dfs(0,0);
    return 0;
}
