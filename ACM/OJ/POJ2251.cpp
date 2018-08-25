#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<string>
#include<stack>
#include<cmath>
#include<cctype>
#include<iostream>
#include<set>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define MAXN 1000000007
#define judge(x,y,z) !vis[x][y][z]&&map[x][y][z]!='#'&&x>=0&&x<l&&y>=0&&y<m&&z>=0&&z<n
int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
bool vis[35][35][35];
char map[35][35][35];
int l,m,n;
struct node
{
    int x,y,z;
    int step;
};
int  BFS(int x,int y,int z)
{
    mem(vis);
    queue<node>q;
    node u;
    u.x=x;u.y=y;u.z=z;
    u.step=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        if(map[u.x][u.y][u.z]=='E')return u.step;
        q.pop();
        int i;
        for(i=0;i<6;i++)
        {
            node v;
            v.x=u.x+d[i][0];v.y=u.y+d[i][1];
            v.z=u.z+d[i][2];
            if(judge(v.x,v.y,v.z))
            {
                vis[v.x][v.y][v.z]=true;
                v.step=u.step+1;
                q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%d%d%d%*c",&l,&m,&n))
    {
        mem(map);
        if(!m&&!n&&!l)break;
        int i,j,k,sx,sy,sz;
        for(i=0;i<l;i++)
            for(j=0;j<m;j++){
                scanf("%s",map[i][j]);
                for(k=0;k<n;k++)
                {
                    if(map[i][j][k]=='S')sx=i,sy=j,sz=k;
                }
            }
        int step=BFS(sx,sy,sz);
        if(step)printf("Escaped in %d minute(s).\n",step);
        else printf("Trapped!\n");
    }
    return 0;
}
