#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
struct Query  
{  
    int id, l, r;  
    long long ans;  
};  
  
const int MAXN = 200010;  
const int MAXNUM = 1000010;  
int n, m, sqrtn;  
int c[MAXN], num[MAXNUM];  
Query q[MAXN];  
  
int gcd(int a, int b)  
{  
    return b == 0 ? a : gcd(b, a % b);  
}  
  
bool cmplr(const Query &a, const Query &b)  
{  
    if (a.l / sqrtn == b.l / sqrtn) return a.r < b.r;  
    else return a.l < b.l;  
}  
  
bool cmpid(const Query &a, const Query &b)  
{  
    return a.id < b.id;  
}  
  
int main()  
{  
    scanf("%d%d", &n, &m);  
    sqrtn = (int)sqrt(n);  
    memset(num, 0, sizeof(num));  
    for (int i = 1; i <= n; i++)  
        scanf("%d", &c[i]);  
    for (int i = 0; i < m; i++)  
    {  
        q[i].id = i;  
        scanf("%d%d", &q[i].l, &q[i].r);  
    }  
    sort(q, q + m, cmplr);  
    int l = 1, r = 1;  
    long long ans = c[1];  
    num[c[1]]++;  
    for (int i = 0; i < m; i++)  
    {  
        while (r < q[i].r)  
        {  
            r++;  
            ans -= (long long)num[c[r]] * num[c[r]] * c[r];  
            num[c[r]]++;  
            ans += (long long)num[c[r]] * num[c[r]] * c[r];  
        }  
        while (l < q[i].l)  
        {  
            ans -= (long long)num[c[l]] * num[c[l]] * c[l];  
            num[c[l]]--;  
            ans += (long long)num[c[l]] * num[c[l]] * c[l];  
            l++;  
        }  
        while (l > q[i].l)  
        {  
            l--;  
            ans -= (long long)num[c[l]] * num[c[l]] * c[l];  
            num[c[l]]++;  
            ans += (long long)num[c[l]] * num[c[l]] * c[l];  
        }  
        while (r > q[i].r)  
        {  
            ans -= (long long)num[c[r]] * num[c[r]] * c[r];  
            num[c[r]]--;  
            ans += (long long)num[c[r]] * num[c[r]] * c[r];  
            r--;  
        }  
        cout<<l<<" "<<r<<" "<<ans<<endl;
        q[i].ans = ans;  
    }  
    sort(q, q + m, cmpid);  
    for (int i = 0; i < m; i++)  
        cout << q[i].ans << "\n";  
    return 0;  
}  
