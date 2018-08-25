#include<stdio.h>  
#include<string.h>  
#define N 1000005  
char str[N];  
int f[N];  
void getFail(char *p, int *f)  
{  
    int m=strlen(p);  
    f[0]=f[1]=0;  
    for(int i=1; i<m; ++i)  
    {  
        int j=f[i];  
        while(j && p[i]!=p[j])j=f[j];  
        f[i+1] = p[i]==p[j]?1+j:0;  
    }  
}  
int main()  
{  
    while(scanf("%s",str)!=EOF)  
    {  
        int len=strlen(str);  
        getFail(str,f);  
        printf("%d\n",len-f[len]);  
  
    }  
    return 0;  
}  
