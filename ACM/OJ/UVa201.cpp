#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int H[10][10];
int V[10][10];
int main()
{
    int  n,m,x,y,T = 0;
    char c;
    while (~scanf("%d%d",&n,&m)) {  
        getchar();
        for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= n ; ++ j)
            V[i][j] = H[i][j] = 0;
        for (int i = 1 ; i <= m ; ++ i) {
            scanf("%c%d%d",&c,&x,&y);
            getchar();
            if (c == 'H')
                H[x][y] = 1;
            else
                V[y][x] = 1;
        }
        if (T ++) printf("\n**********************************\n\n");  
        printf("Problem #%d\n\n",T);  
          
        int sum = 0;  
        for (int l = 1 ; l <= n ; ++ l) {  
            int count = 0,flag = 0;  
            for (int i = 1 ; i+l <= n ; ++ i)  
            for (int j = 1 ; j+l <= n ; ++ j) {  
                flag = 1;  
                for (int h = j ; h < j+l ; ++ h)  
                    if (!H[i][h] || !H[i+l][h]) flag = 0;  
                for (int v = i ; v < i+l ; ++ v)  
                    if (!V[v][j] || !V[v][j+l]) flag = 0;  
                count += flag;  
            }  
            sum += count;  
            if (count) printf("%d square (s) of size %d\n",count,l);  
        }  
              
        if (!sum) printf("No completed squares can be found.\n");  
    }   
    return 0;  
}  
