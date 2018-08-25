int n, m;
struct Edge {
    int u, v, c;
} e[M];
int realRoot, pre[N], in[N], id[N], vis[N];
int directedMST(int root, int n, int m) {
    int ret = 0;
    while(true) {
        memset(in, 0x3f, sizeof in);
        for(int i = 0; i < m; ++i) {
            int u = e[i].u, v = e[i].v;
            if(u != v && e[i].c < in[v]) {
                if(u == root) realRoot = i;
                pre[v] = u;
                in[v] = e[i].c;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i == root) continue;
            if(in[i] == INF) return -1;
        }

        int cnt = 0;
        memset(id, -1, sizeof id);
        memset(vis, -1, sizeof vis);
        in[root] = 0;
        for(int i = 0; i < n; ++i) {
            ret += in[i];
            int u = i;
            while(id[u] == -1 && vis[u] != i && u != root) {
                vis[u] = i;
                u = pre[u];
            }
            if(id[u] == -1 && u != root) {
                for(int v = pre[u]; v != u; v = pre[v]) {
                    id[v] = cnt;
                }
                id[u] = cnt++;
            }
        }
        if(cnt == 0) break;
        for(int i = 0; i < n; ++i)
            if(id[i] == -1) id[i] = cnt++;
        for(int i = 0; i < m; ++i) {
            int u = e[i].u, v = e[i].v;
            e[i].u = id[u];
            e[i].v = id[v];
            if(u != v) e[i].c -= in[v];
        }
        n = cnt;
        root = id[root];
    }
    return ret;
}
