#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
#define inf 0x3f3f3f3f
#define ms(a,b) memset(a,b,sizeof a)
#define ll long long
using namespace std;
const int N = 1005;
struct edge{
    int to, next;
}ed[N*N*2];
struct node {
    int x, y;
}no[N];
int x1, y1, x2, y2;
int a[N], b[N];
int c[N], d[N];
//////////
int n, A, B;
int cnt;
int head[N*2];
void add(int from, int to) {
    ed[cnt].to = to;
    ed[cnt].next = head[from];
    head[from] = cnt++;
}
/////////
int ord, sccnum, top;
int low[N*2], dfn[N*2], st[N*2];
bool instack[N*2];
int block[N*2];

void tarjan(int u) {
    low[u] = dfn[u] = ++ord;
    instack[u] = 1;
    st[top++] = u;
    for(int i = head[u]; ~i; i = ed[i].next) {
        int v = ed[i].to;
        //if(v == u)
        //    continue;
        if(dfn[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int v;
        sccnum++;
        do {
            v = st[--top];
            block[v] = sccnum;
            instack[v] = 0;
        }while(u != v);

    }
}
/////////////
int xy;
int cc[N*2];
int aaa;
void init() {
    for(int i = 1; i <= 2*n; i++ )
        head[i] = cc[i];
    ms(low,-1);
    ms(dfn,-1);
    ord = sccnum = top = 0;
}
bool judge(ll mid) {
    init();
    cnt = aaa;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(abs(no[i].x - x1) + abs(no[i].y - y1) + abs(no[j].x - x1) + abs(no[j].y - y1) > mid) {
                add(i, j + n);
                add(j, i + n);
                //cout << i << " " << j << endl;
            }
            if(abs(no[i].x - x1) + abs(no[i].y - y1) + abs(no[j].x - x2) + abs(no[j].y - y2) + xy > mid) {
                add(i, j);
                add(j + n, i + n);
            }
            if(abs(no[i].x - x2) + abs(no[i].y - y2) + abs(no[j].x - x1) + abs(no[j].y - y1) + xy > mid) {
                add(j, i);
                add(i + n, j + n);
            }
            if(abs(no[i].x - x2) + abs(no[i].y - y2) + abs(no[j].x - x2) + abs(no[j].y - y2) > mid) {
                add(j + n, i);
                add(i + n, j);
                //cout << "3-=-=" <<i << " " << j << endl;
            }
        }
    }
    //cout <<  endl <<endl;
    for(int i = 1; i <= 2*n; i++)
        if(dfn[i] == -1)
            tarjan(i);

    for(int i = 1; i <= n; i++)
        if(block[i] == block[i + n])
            return 0;
    return 1;
}
int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &A, &B);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &no[i].x, &no[i].y);
        for(int i = 1; i <= A; i++)
            scanf("%d%d", &a[i], &b[i]);
        for(int i = 1; i <= B; i++)
            scanf("%d%d", &c[i], &d[i]);
        cnt = 0;
        ms(head,-1);
        for(int i = 1; i <= A; i++) {
            add(a[i], b[i] + n);
            add(b[i] + n, a[i]);
            add(a[i] + n, b[i]);
            add(b[i], a[i] + n);
        }
        for(int i = 1; i <= B; i++) {
            add(c[i], d[i]);
            add(d[i], c[i]);
            add(c[i] + n, d[i] + n);
            add(d[i] + n, c[i] + n);
        }
        aaa = cnt;
        for(int i = 1; i <= 2*n; i++)
            cc[i] = head[i];

        xy = abs(x1 - x2) + abs(y1 - y2);
        int l = 0;
        int r = 10000000;
        int mid;
        int ans=inf;
        if(judge(10000000)){
            while(l < r) {
                mid = (l + r) >> 1;
                if(judge(mid)){
                    r = mid-1;
                	ans=mid;
				}
                else
                    l = mid + 1;
            }
            if(ans==inf)
                printf("-1\n");
            else
                printf("%lld\n",l);
        }
        else
            printf("-1\n");

    }
    return 0;
}
