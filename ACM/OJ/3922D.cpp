#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define X first
#define Y second
#define clr(u,v); memset(u,v,sizeof(u));
#define in() freopen("data","r",stdin);
#define out() freopen("ans","w",stdout);
#define Clear(Q); while (!Q.empty()) Q.pop();
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
char str[maxn];
ll pow(ll n, ll k){
    ll ans = 1;
    while (k > 0){
        if (k & 1) ans *= n;
        k >>= 1;
        n = n * n;
    }
    return ans;
}
int main(){
    ll n, ans = 0;
    cin >> n;
    cin >> (str + 1);
    int len = strlen(str + 1);
    ll k = 0;
    str[0] = '0';
    int pre = len;
    for (int i = len; i >= 0; i--){
        int pos = i;
        ll num = 0;
        while (pos <= pre && num < n){
            num *= 10;
            num += str[pos] - '0';
            pos++;
        }
        if (num >= n || i == 0){
            pos = i + 1;
            num = 0;
            int flag = 0;
            while (str[pos] == '0'){
                pos++;
                flag = 1;
            }
            int temp = pos - 1;
            while (pos <= pre){
                num *= 10;
                num += str[pos] - '0';
                pos++;
            }
            if (num == 0 && str[pre] == '0'){
                str[pre] = '\0';
                k++;
                i++;
                pre--;
                continue;
            }
            if (flag) i++;
            ans += num * pow(n, k);
            k++;
            pre = temp;
        }
    }
    cout << ans << endl;
    return 0;
}
