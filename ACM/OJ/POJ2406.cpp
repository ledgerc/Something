#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
const int Max = 100000005;
 
char str[Max];        //  模式串。
int len, next[Max];
void get_next(){
    int i=0,j=-1;
    next[0]=-1;
    while(i<len){
        if(j==-1||str[i]==str[j]){
            ++i;++j;
            next[i]=j;
        } 
        else
			j=next[j];
    }
}
int main(){
    while(scanf("%s", str) != EOF){
        if(str[0] == '.')
			break;
        len = strlen(str);
        get_next();
        int ans = 1;
        if(len % (len-next[len]) == 0)       //看整个长度len能分解成x个这种串
            ans = len / (len-next[len]);
        printf("%d\n", ans);
    }
    return 0;
}
