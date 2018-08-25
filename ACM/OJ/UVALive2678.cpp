#include<cstdio>  
#include<algorithm>  
using namespace std;  
#define maxn 100010  
int sum[maxn];  
int main() {  
    int S, N;  
    while(scanf("%d%d",&N, &S) == 2) {  
        sum[0] = 0;  
        int tmp;  
        for(int i = 1; i <= N; i++) {  
            scanf("%d",&tmp);  
            sum[i] = sum[i-1] + tmp;      
        }  
        int start = 0;  
        int ans = N + 1;  
        for(int i = 1; i <= N; i++)   {  
            if( sum[i] - sum[start] < S)  
                continue;  
            while(sum[i] - sum[start] >= S)  
                start++;  
            ans = min(ans,i - start + 1);  
        }  
        printf("%d\n",ans == N + 1? 0:ans);  
    }  
    return 0;  
}  
