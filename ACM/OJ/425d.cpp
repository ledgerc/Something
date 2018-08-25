#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000") //不需要申请系统栈
const int N = 100010;
const int M = 25;
int dp[2*N][M];  //这个数组记得开到2*N，因为遍历后序列长度为2*n-1
bool vis[N];
struct edge
{
    int u,v,w,next;
}e[2*N];
int tot,head[N];
inline void add(int u ,int v ,int w ,int &k)
{
    e[k].u = u; e[k].v = v; e[k].w = w;
    e[k].next = head[u]; head[u] = k++;
    u = u^v; v = u^v; u = u^v;
    e[k].u = u; e[k].v = v; e[k].w = w;
    e[k].next = head[u]; head[u] = k++;
}
int ver[2*N],R[2*N],first[N],dir[N];
//ver:节点编号 R：深度 first：点编号位置 dir：距离
void dfs(int u ,int dep)
{
    vis[u] = true; ver[++tot] = u; first[u] = tot; R[tot] = dep;
    for(int k=head[u]; k!=-1; k=e[k].next)
        if( !vis[e[k].v] )
        {
            int v = e[k].v , w = e[k].w;
            dir[v] = dir[u] + w;
            dfs(v,dep+1);
            ver[++tot] = u; R[tot] = dep;
        }
}
void ST(int n)
{
    for(int i=1;i<=n;i++)
        dp[i][0] = i;
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            int a = dp[i][j-1] , b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = R[a]<R[b]?a:b;
        }
    }
}
//中间部分是交叉的。
int RMQ(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a = dp[l][k], b = dp[r-(1<<k)+1][k]; //保存的是编号
    return R[a]<R[b]?a:b;
}

int LCA(int u ,int v)
{
    int x = first[u] , y = first[v];
    if(x > y) swap(x,y);
    int res = RMQ(x,y);
    return ver[res];
}

int main()
{
    //freopen("Input.txt","r",stdin);
    //freopen("Out.txt","w",stdout);
  
    int n,q,num = 0;
    scanf("%d%d",&n,&q);
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    for(int i=2; i<=n; i++){
            int u,v,w;
            scanf("%d",&u);
            add(i,u,1,num);
        }
    tot = 0; dir[1] = 0;
    dfs(1,1);
    /*
	printf("节点ver "); for(int i=1; i<=2*n-1; i++) printf("%d ",ver[i]); cout << endl;
    printf("深度R "); for(int i=1; i<=2*n-1; i++) printf("%d ",R[i]);   cout << endl;
    printf("首位first "); for(int i=1; i<=n; i++) printf("%d ",first[i]);    cout << endl;
    printf("距离dir "); for(int i=1; i<=n; i++) printf("%d ",dir[i]);      cout << endl;*/
	ST(2*n-1);
    while(q--){
     //   int lca = LCA(u,v);
     int a,b,c;  scanf("%d%d%d",&a,&b,&c);
     int ans; int u,v,lca;
	int lab=LCA(a,b); int lac=LCA(a,c); int lbc=LCA(b,c);
     
     
	 u=a,v=lbc;
     lca = LCA(u,v);
     if( lab==b&&lbc==c )
	 	ans=dir[lab];
	 else if(lac==c&&lab==b)
	 	ans=dir[lac];
	else
		ans=dir[u] + dir[v] - 2*dir[lca];
//	 cout<<ans<<endl;
	 
	 u=b,v=lac;
     lca = LCA(u,v);
     if(lab==a&&lac==c)
     	ans=max(ans,dir[lab]);
    else if(lbc==c&&lac==a)
    	ans=max(ans,dir[lbc]);
    else
	 ans = max(ans,dir[u] + dir[v] - 2*dir[lca]);
//	 cout<<ans<<endl;
	 
	 u=c,v=lab;
     lca = LCA(u,v);
     if(lac==a&&lab==b)
     	ans=max(ans,dir[lac]);
    else if(lbc==b&&lab==a)
    	ans=max(ans,dir[lbc]);
    else
	 ans = max(ans,dir[u] + dir[v] - 2*dir[lca]);
//	 cout<<ans<<endl;
	
	printf("%d\n",ans+1);
	  
    }
    return 0;
}
/*
3 100
1 1
1 
*/

