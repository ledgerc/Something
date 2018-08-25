#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std; 
#define N 10005  
char str[N];  
struct node{
    char s[1000];
}ss[N];
bool cmp(node a,node b){
    return strcmp(a.s,b.s)<1;
}
int Minrp(char *s,int l){
    int i=0,j=1,k=0,t;  
    while(i<l && j<l && k<l){  
        t = s[(i+k) >= l ? i+k-l : i+k] - s[(j+k) >= l ? j+k-l : j+k];  
        if(!t)k++;  
        else {  
            if(t>0)i = i+k+1;  
            else j = j+k+1;  
            if(i==j)j++;  
            k = 0;  
        }  
    }  
    return i;  
}  
int main(){  
    int n;  
    while(scanf("%d",&n) != -1){
        int i,j,k;
        for(i=0;i<n;i++){
            scanf("%s",str);
            int len = strlen(str);
            int minpos = Minrp(str,len);
            for(k=0,j=minpos;j<len;j++){
                ss[i].s[k++] = str[j];
            }
            for(j=0;j<minpos;j++){
                ss[i].s[k++] = str[j];
            }
            ss[i].s[k] = '\0';
        }
        sort(ss,ss+n,cmp);
        int ans = 1;
        for(i=1;i<n;i++){
            if(strcmp(ss[i].s,ss[i-1].s)!=0){
                ans++;
            }  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
