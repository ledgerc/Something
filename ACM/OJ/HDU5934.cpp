#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
using namespace std;
#define N 1010
#define INF 0x7fffffff
struct node{
    int u, v, nxt;
}edge[2000010];
struct P{
    long long x, y, r, c;
}p[N];
int belong[N], vis[N], head[N], tot, cnt, num, dfn[N], low[N], in[N], out[N];
stack<int> sta;
void init() {
    tot = cnt = num = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(belong, 0, sizeof(belong));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    while(sta.size()) sta.pop();
}
void add(int u, int v) {
    edge[tot].u = u; edge[tot].v = v; edge[tot].nxt = head[u]; head[u] = tot++;
}
bool dis(int u, int v) {
    double a = sqrt(((p[u].x - p[v].x) * (p[u].x - p[v].x) + (p[u].y - p[v].y) * (p[u].y - p[v].y)) * 1.0);
    if(a <= p[u].r) return true;
    return false;
}
void tarjan(int u) {
    vis[u] = 1;
    sta.push(u);
    dfn[u] = low[u] = ++cnt;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            if(low[v] < low[u]) low[u] = low[v];
        } else if(vis[v]) {
            if(dfn[v] < low[u]) low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]) {
        ++num;
        while(true) {
            int v = sta.top(); sta.pop();
            belong[v] = num; vis[v] = 0;
            if(v == u) break;
        }
    }
}

int main(){
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        init();
        for(int i = 1; i <= n; i++)
			scanf("%I64d%I64d%I64d%I64d", &p[i].x, &p[i].y, &p[i].r, &p[i].c);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(dis(i, j)) add(i, j);
            }
        }
        for(int i = 1; i <= n; i++)
			if(!dfn[i])
				tarjan(i);
        for(int u = 1; u <= n; u++) {
            for(int i = head[u]; ~i; i = edge[i].nxt) {
                int v = edge[i].v;
                if(belong[u] != belong[v]) {
                    out[belong[u]]++;
                    in[belong[v]]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i <= num; i++) {
            if(in[i] == 0) {
                int mi = INF;
                for(int j = 1; j <= n; j++) {
                    if(belong[j] == i) {
                        if(p[j].c < mi) mi = p[j].c;
                    }
                }
                ans += mi;
            }
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
