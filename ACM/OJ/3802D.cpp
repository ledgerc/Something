#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5+5;
int n,a,b,k,book[maxn],ans[maxn];
char str[maxn]; 
int main(){  
    while(cin >> n >> a >> b >> k){  
        for(int i = 0; i < n; i++)
            scanf(" %c", &str[i]), book[i] = str[i]-48;
        int i, j, k2 = 0;
        for(i = 0; i < n; i++){  
            if(!book[i]){
                for(j = 0; j < b; j++){  
                    if(book[i+j] || i+j >= n)
						break;
                }
                if(j >= b){  
                    ans[k2++] = i+j-1;
                    i = i+j-1;
                }
            }
        }
        int num = k2-a+1;
        printf("%d\n", num);
        for(int i = 0; i < num; i++)
            printf("%d%c", ans[i]+1, i==num-1 ? '\n' : ' ');
    }
    return 0;
}
