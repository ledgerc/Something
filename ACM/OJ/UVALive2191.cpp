#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
typedef __int64 LL;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = (4.0*atan(1.0));
const int maxn = 200000 + 20;
#define lowbit(x) (x&-x)
LL C[maxn];
LL val[maxn];
int n;
LL sum(int x) {
    LL ret = 0;
    while(x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x, LL v) {
    while(x <= n) {
        C[x] += v;
        x += lowbit(x);
    }
}
char str[10];
int main() {
    int kase = 1;
    while(scanf("%d", &n) != EOF && n) {
        if(kase > 1) putchar('\n');
        printf("Case %d:\n", kase++);
        memset(C, 0, sizeof(LL) * (n+10));
        for(int i=1; i<=n; i++) {
            scanf("%lld", &val[i]);
            add(i, val[i]);
        }
        while(scanf("%s", str) != EOF && str[0] != 'E') {
            LL x, y;
            scanf("%lld%lld", &x, &y);
            if(str[0] == 'S') {
                LL d = y - val[x];
                add(x, d);
                val[x] = y;
            } else {
                LL ans = sum(y) - sum(x-1);
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
