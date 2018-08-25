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
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
 * LCA  (POJ 1330)
 * 在线算法 DFS + ST
 */
int rmq[2*maxn];//rmq数组，就是欧拉序列对应的深度序列
struct ST{
    int mm[2*maxn];
    int dp[2*maxn][20];//最小值对应的下标
    void init(int n){
        mm[0] = -1;
        for(int i = 1;i <= n;i++){
            mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
            dp[i][0] = i;
        }
        for(int j = 1; j <= mm[n];j++)
            for(int i = 1; i + (1<<j) - 1 <= n; i++)
                dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }
    int query(int a,int b){//查询[a,b]之间最小值的下标
        if(a > b)swap(a,b);
        int k = mm[b-a+1];
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
    }
};
//边的结构体定义
struct Edge{
    int to,next;
};
Edge edge[maxn*2];
int tot,head[maxn];

int F[maxn*2];//欧拉序列，就是dfs遍历的顺序，长度为2*n-1,下标从1开始
int P[maxn];//P[i]表示点i在F中第一次出现的位置
int cnt;

ST st;
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){//加边，无向边需要加两次
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int u,int pre,int dep){
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for(int i = head[u];i != -1;i = edge[i].next){
        int v = edge[i].to;
        if(v == pre)continue;
        dfs(v,u,dep+1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}
void LCA_init(int root,int node_num){//查询LCA前的初始化
    cnt = 0;
    dfs(root,root,0);
    st.init(2*node_num-1);
}
int query_lca(int u,int v){//查询u,v的lca编号
    return F[st.query(P[u],P[v])];
}
bool flag[maxn];
int main(){
    int T;
    int N;
    int u,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        init();
        memset(flag,false,sizeof(flag));
        for(int i = 1; i < N;i++){
        	int u,v; scanf("%d%d",&u,&v);
        	addedge(u,v); addedge(v,u);
        	flag[v]=true;
        	/*
        	int tmp; scanf("%d",&tmp);
        	u=tmp; v=i+1;
        	pr(u) prln(v)
        	//u->father v->son
            addedge(u,v);
            addedge(v,u);
            flag[v] = true;
            */
        }
        int root;
        for(int i = 1; i <= N;i++)
            if(!flag[i]){
                root = i;
                break;
            }
        LCA_init(root,N);
        int q=100;
        while(q--){
        scanf("%d%d",&u,&v);
        printf("%d\n",query_lca(u,v));
		}
    }
    return 0;
}
