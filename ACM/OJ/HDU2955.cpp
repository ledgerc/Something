#include <stdio.h>  
#include <algorithm>  
#include <iostream>  
#include <cmath>  
#include <string.h>  
using namespace std;  
const int N = 50005;  
int main()  
{  
    int t, m0, m[N];  
    double p0, p[N], ans[N];  
    scanf("%d", &t);  
    while(t --){  
        scanf("%lf%d", &p0, &m0);  
        int sum = 0;  
        for(int i = 0; i < m0; i ++)  
        {  
            scanf("%d%lf", &m[i], &p[i]);  
            sum += m[i];  
        }  
        memset(ans, 0, sizeof(ans));  
        ans[0] = 1;  
        for(int i = 0; i < m0; i ++)  
        {  
            for(int j = sum; j >= m[i]; j --)  
            {  
                ans[j] = max(ans[j], ans[j - m[i]] *(1 - p[i]));  
            }  
        }  
        for(int i = sum; i >= 0; i --)  
        {  
            if(ans[i] > (1 - p0))  
            {  
                printf("%d\n", i);  
                break;  
            }  
        }  
    }  
    return 0;  
}
