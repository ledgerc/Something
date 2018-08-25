#include<stdio.h>
#define MAXN 520
#define MAXM 6000
const int INF = (1<<26);
struct node{
    int u,v,w;
}edge[MAXM];
int dis[MAXN],top;
int bellman_ford(int n){
    int i,j,u,v,w;
    for(i=1; i<=n; i++)
		dis[i]=INF;
    dis[1]=0;
    for(i=0; i<n-1; i++){
        for(j=0; j<top; j++){
            u = edge[j].u;
            v = edge[j].v;
            w = edge[j].w;
            if(dis[u] < INF && dis[u]+w < dis[v]){
                dis[v]=dis[u]+w;
            }
        }
    }
    for(j=0; j<top; j++){
        u=edge[j].u;
        v=edge[j].v;
        w=edge[j].w;
        if(dis[u] < INF && dis[u]+w < dis[v]){
            return 0;
        }
    }
    return 1;
}
void add(int u, int v, int w){
    edge[top].u = u;
    edge[top].v = v;
    edge[top++].w = w;
}
int main(){
    int T, n, m, l, i, u, v, w;
    scanf("%d", &T);
    while(T--){
        top = 0;
        scanf("%d %d %d", &n, &m, &l);
        for(i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        for(i=0; i<l; i++){
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, -w);
        }
        if(!bellman_ford(n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
