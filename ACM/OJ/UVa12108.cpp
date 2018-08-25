#include<algorithm>  
#include<cctype>  
#include<cmath>  
#include<cstdio>  
#include<cstring>  
#include<iomanip>  
#include<iostream>  
#include<map>  
#include<queue>  
#include<set>  
#include<sstream>  
#include<stack>  
#include<string>  
#define ll long long  
#define pr(x) cout << #x << " = " << (x) << '\n';  
using namespace std;  
const int INF = 0x7f7f7f7f;  
const int MAXN = 21;  
int a[MAXN], b[MAXN], c[MAXN], cnt, n;  
bool ok() {  
    cnt = 0;  
    for (int i = 0; i < n; ++i) {  
        if (c[i] <= a[i]) ++cnt;  
    } 
    if (cnt == n) return 1;  
    return 0;  
}
void nextState() {  
    for (int i = 0; i < n; ++i) {  
        c[i] %= a[i] + b[i];  
        if (c[i] <= a[i] && cnt >= n - cnt) c[i] = 0;  
        else ++c[i];  
    }
}
int main() {  
    int kase = 0;  
    while (cin >> n && n) {  
        for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];  
        int ans = 1;  
        for (; ans < 1e6; ++ans) {  
            if (ok()) break;  
            nextState();  
        }  
        if (ans == 1e6) ans = -1;  
        cout << "Case " << ++kase << ": " << ans << '\n';  
    }  
    return 0;  
}  
