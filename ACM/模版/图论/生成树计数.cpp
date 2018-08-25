#include<iostream>
#include<cmath>
using namespace std;
#define zero(x)((x>0? x:-x)<1e-15)
const int MAXN = 100;
double a[MAXN][MAXN];
double b[MAXN][MAXN];
int g[53][53];
int N, M;
double det(double a[MAXN][MAXN], int n){
    int i,j,k,sign = 0;
    double ret=1,t;
    for(i=0; i<n; i++)
    	for(j=0; j<n; j++)
        	b[i][j]=a[i][j];
    for(i=0; i<n; i++){
        if(zero(b[i][i])){
           for(j=i+1; j<n; j++)
               if(!zero(b[j][i]))
                	break;
           if(j==n)
               return 0;
           for(k=i; k<n; k++)
               t=b[i][k],b[i][k]=b[j][k],b[j][k]=t;
           sign++;
        }
        ret*= b[i][i];
        for(k=i+1; k<n; k++)
           b[i][k]/=b[i][i];
        for(j=i+1; j<n; j++)
           for(k=i+1; k<n; k++)
               b[j][k]-=b[j][i]*b[i][k];
    }
    if(sign&1)
        ret=-ret;
    return ret;
}
int main(){
	int cas;
	scanf("%d", &cas);
    while(cas--){
        scanf("%d%d",&N,&M);
        for(int i=0; i<N; i++) {
           for(int j=0; j<N; j++) {
               g[i][j]=0;
            }
        }
        while(M--){
           int a,b;
           scanf("%d%d",&a,&b);
           g[a-1][b-1]=g[b-1][a-1]=1;
        }
        for(int i=0; i<N; i++){
        	for(int j=0; j<N; j++)
				a[i][j]=0;
        }
        for(int i=0; i<N; i++) {
        	int d=0;
        	for(int j=0; j<N; j++)
		   		if(g[i][j]) d++;
           	a[i][i]=d;
        }
        for(int i=0; i<N; i++){
           	for(int j=0; j<N; j++) {
               	if(g[i][j])
			   		a[i][j]=-1;
            }
        }
       	double ans=det(a,N-1);
       	printf("%0.0lf\n",ans);
    }
    return 0;
}
