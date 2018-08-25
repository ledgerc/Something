#include<stdio.h>
 int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};   //记录方向
 int g,a,b;//g用来记录是否找到解，找到后不再搜索
 int vist[26][26],path[26][2];
 void find(int i,int j,int k)//i,j是要走的格子，k记录已经走过的步数
 {
     if(k==a*b)//走完了
     {
         for(int i=0;i<k;i++)
         printf("%c%d",path[i][0]+'A',path[i][1]+1);
         printf("\n");
         g=1;
     }
     else
     for(int x=0;x<8;x++)//8个方向依次搜索
     {
         int n=i+dir[x][0];
         int m=j+dir[x][1];
         if(n>=0&&n<b&&m>=0&&m<a&&!vist[n][m]&&!g)
         {
             vist[n][m]=1;//标记已走
             path[k][0]=n,path[k][1]=m;
             find(n,m,k+1);
             vist[n][m]=0;//清除标记
         }
     }
 }
 int main()
 {
     int n;
     scanf("%d",&n);
     for(int m=0;m<n;m++)
     {
         g=0;
         scanf("%d %d",&a,&b);
         for(int i=0;i<a;i++)//一个点一个点的尝试
             for(int j=0;j<b;j++)
                 vist[i][j]=0;
         vist[0][0]=1;
         path[0][0]=0,path[0][1]=0;
         printf("Scenario #%d:\n",m+1);
         find(0,0,1);
         if(!g) printf("impossible\n");
         printf("\n");
     }
     return 0;
 }
