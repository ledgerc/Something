/*
1������ŵ������=��ͼ�����������������
2������ͼ�У����������������+��С���ǵ������=����ͼ�������
3������ͼ�У���С���ǵ������=���ƥ�������
4��ͼ��Ⱦɫ�����У�������Ҫ����ɫ������=����ŵ������
*/
// �ţ���ȫͼ 
// 1. ����ŵ������ = ��ͼ�����������������
// 2. ͼ��Ⱦɫ�����У�������Ҫ����ɫ������ = ����ŵ������
struct MaxClique {
    static const int V = 60;
    bool g[V][V];
    int n, ans, max[V], adj[V][V];
    int path[V], clique[V]; //for record
    //max[i]:= [i, n]'s maximum clique
    //adj[dep][i]:= available vertices

    void init(int _n) { n = _n; }

    bool dfs(int cur, int dep) {
        if(cur == 0) {
            if(dep > ans) {
                ans = dep;
                swap(clique, path);
                return 1;
            }
            return 0;
        }
        for(int i = 0; i < cur; ++i) {
            if(dep + cur - i <= ans) return 0; //dep + left <= ans
            int u = adj[dep][i], nxt = 0;
            if(dep + max[u] <= ans) return 0; //same as above
            path[dep] = u;
            for(int j = i + 1; j < cur; ++j) {
                int v = adj[dep][j];
                if(g[u][v]) adj[dep + 1][nxt++] = v;
            }
            if(dfs(nxt, dep + 1)) return 1;
        }
        return 0;
    }
    int maxClique() {
        ans = 0;
        memset(max, 0, sizeof max);
        for(int i = n - 1; ~i; --i) {
            int cur = 0;
            for(int j = i + 1; j < n; ++j)
                if(g[i][j]) adj[1][cur++] = j;
            path[0] = i;
            dfs(cur, 1);
            max[i] = ans;
        }
        return ans;
    }
} solver;

