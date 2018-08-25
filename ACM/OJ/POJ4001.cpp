#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[15][15];
bool search(int a,int b)
{
    int i,j,t;
    ///这是判断马的- -
    if(a-2>0&&b-1>0&&vis[a-2][b-1]==5&&!vis[a-1][b-1]) return 0;
    if(b-2>0&&a-1>0&&vis[a-1][b-2]==5&&!vis[a-1][b-1]) return 0;
    if(a-2>0&&b+1<=9&&vis[a-2][b+1]==5&&!vis[a-1][b+1]) return 0;
    if(b+2<=9&&a-1>0&&vis[a-1][b+2]==5&&!vis[a-1][b+1]) return 0;
    if(a+2<=10&&b+1<=9&&vis[a+2][b+1]==5&&!vis[a+1][b+1]) return 0;
    if(b-2>0&&a+1<=10&&vis[a+1][b-2]==5&&!vis[a+1][b-1]) return 0;
    if(a+2<=10&&b-1>0&&vis[a+2][b-1]==5&&!vis[a+1][b-1]) return 0;
    if(b+2<=9&&a+1<=10&&vis[a+1][b+2]==5&&!vis[a+1][b+1]) return 0;
    ///然后是炮和车，t记录有几个隔子
    t=0;
    for(i=a-1; i>=1; i--)
    {
        if(!t&&(vis[i][b]==3||vis[i][b]==2)) return 0;///车
         
        if(vis[i][b]==4&&t==1)return 0;///炮
        if(vis[i][b]!=0) t++;
    }
    t=0;
    for(i=a+1; i<=10; i++)
    {
        if(!t&&(vis[i][b]==3||vis[i][b]==2)) return 0;
         
        if(vis[i][b]==4&&t==1)return 0;
        if(vis[i][b]!=0) t++;
    }
    t=0;
    for(i=b-1; i>=1; i--)
    {
        if(!t&&(vis[a][i]==3||vis[a][i]==2)) return 0;
         
        if(vis[a][i]==4&&t==1)return 0;
        if(vis[a][i]!=0) t++;
    }
    t=0;
    for(i=b+1; i<=9; i++)
    {
        if(!t&&(vis[a][i]==3||vis[a][i]==2)) return 0;
         
        if(vis[a][i]==4&&t==1)return 0;
        if(vis[a][i]!=0) t++;
    }
    return 1;
}
int main()
{
    int n,xx,yy,i,j,aa,bb,x,y;
    char c;
    while(~scanf("%d%d%d",&n,&xx,&yy))
    {
        aa=0,bb=0;
        if(n==0&&xx==0&&yy==0)
            break;
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
          //  getchar();
         //   scanf("%c %d %d",&c,&x,&y);
            cin>>c>>x>>y;///scanf输入会出错
            if(c=='G')
            {
                vis[x][y]=2;
                aa=x,bb=y;
            }
            else if(c=='R')
                vis[x][y]=3;
            else if(c=='C')
                vis[x][y]=4;
            else if(c=='H')
                vis[x][y]=5;
        }
        int k;
        if(xx+1<=3&&xx+1>=1)///将不能出界
        {
            k=search(xx+1,yy);
            if(k)
            {
                printf("NO\n");
                continue;
            }
        }
        if(xx-1>=1&&xx-1<=3)
        {
            k=search(xx-1,yy);
            if(k)
            {
                printf("NO\n");
                continue;
            }
        }
        if(yy+1<=6&&yy+1>=4)
        {
            k=search(xx,yy+1);
            if(k)
            {
                printf("NO\n");
                continue;
            }
        }
        if(yy-1>=4&&yy-1<=6)
        {
            k=search(xx,yy-1);
            if(k)
            {
                printf("NO\n");
                continue;
            }
        }
        printf("YES\n");
    }
    return 0;
}


#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int ff[11][11];
char map[11][11];
bool inside(int x,int y)//判断坐标是否在棋局内
{
    if(x>=1&&x<=10&&y>=1&&y<=9) return true;
    return false;
}
bool solve(int x,int y)//判断点(x,y)是否是危险点,安全点返回  true ,
                      //也就是 将  下一步可以走的点，否则false
{
    bool cmp=true;
    for(int i=x+1;i<=10;i++)
    {
        if(ff[i][y]==1)
        {
            if(map[i][y]=='R'||map[i][y]=='G')
                return false;
            else
                for(int t=i+1;t<=10;t++)
                    if(ff[t][y]==1)
                    {
                        if(map[t][y]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }


    for(int i=x-1;i>=1;i--)
    {
        if(ff[i][y]==1)
        {
            if(map[i][y]=='R'||map[i][y]=='G')
                return false;
            else
                for(int t=i-1;t>=0;t--)
                    if(ff[t][y]==1)
                    {
                        if(map[t][y]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }

    for(int i=y+1;i<=9;i++)
    {
        if(ff[x][i]==1)
        {
            if(map[x][i]=='R'||map[x][i]=='G')
                return false;
            else
                for(int t=i+1;t<=9;t++)
                    if(ff[x][t]==1)
                    {
                        if(map[x][t]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }


    for(int i=y-1;i>=1;i--)
    {
        if(ff[x][i]==1)
        {
            if(map[x][i]=='R'||map[x][i]=='G')
                return false;
            else
                for(int t=i-1;t>=0;t--)
                    if(ff[x][t]==1)
                    {
                        if(map[x][t]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }
    //下面判断会不会被马吃掉
    if(inside(x-2,y-1))
    {
        if(ff[x-2][y-1])
        {
            if(map[x-2][y-1]=='H'&&ff[x-1][y-1]==0)
                return false;
        }
    }

    if(inside(x+2,y+1))
    {
        if(ff[x+2][y+1])
        {
            if(map[x+2][y+1]=='H'&&ff[x+1][y+1]==0)
                return false;
        }
    }

    if(inside(x-1,y-2))
    {
        if(ff[x-1][y-2])
        {
            if(map[x-1][y-2]=='H'&&ff[x-1][y-1]==0)
                return false;
        }
    }


   if(inside(x+1,y+2))
    {
        if(ff[x+1][y+2])
        {
            if(map[x+1][y+2]=='H'&&ff[x+1][y+1]==0)
                return false;
        }
    }


    if(inside(x+2,y-1))
    {
        if(ff[x+2][y-1])
        {
            if(map[x+2][y-1]=='H'&&ff[x+1][y-1]==0)
                return false;
        }
    }

    if(inside(x+1,y-2))
    {
        if(ff[x+1][y-2])
        {
            if(map[x+1][y-2]=='H'&&ff[x+1][y-1]==0)
                return false;
        }
    }

    if(inside(x-2,y+1))
    {
        if(ff[x-2][y+1])
        {
            if(map[x-2][y+1]=='H'&&ff[x-1][y+1]==0)
                return false;
        }
    }

    if(inside(x-1,y+2))
    {
        if(ff[x-1][y+2])
        {
            if(map[x-1][y+2]=='H'&&ff[x-1][y+1]==0)
                return false;
        }
    }

    return true;
}

int main()
{
    int N,x,y;
    int a,b;
    char ch;
    while(scanf("%d%d%d",&N,&x,&y))
    {
        if(N==0&&x==0&&y==0)break;
        memset(ff,0,sizeof(ff));
        //ch=getchar();
        for(int i=0;i<N;i++)
        {
            cin>>ch>>a>>b;
            map[a][b]=ch;
            ff[a][b]=1;
        }
        bool res=false;
        if(x-1>=1&&x-1<=3)
            if(solve(x-1,y))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        if(x+1>=1&&x+1<=3)
            if(solve(x+1,y))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        if(y-1>=4&&y-1<=6)
            if(solve(x,y-1))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        if(y+1>=4&&y+1<=6)
            if(solve(x,y+1))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }
    return 0;
}
