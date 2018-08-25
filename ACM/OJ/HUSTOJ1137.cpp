#include<cstdiO>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
int A[1050];  
  
int main()  
{  
    int n,k;  
    scanf("%d%d",&n,&k);  
    for(int i=0;i<n;i++)  
        scanf("%d",&A[i]);  
    while(k--)  
        next_permutation(A,A+n);  //这是最骚的。 
    for(int i=0;i<n;i++)  
    {  
        if(i)  
            printf(" ");  
            printf("%d",A[i]);  
    }  
    printf("\n");  
    return 0;  
}
