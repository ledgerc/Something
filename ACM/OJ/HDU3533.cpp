#include<stdio.h>  
#include<string.h>  
#include<queue>  
#include<algorithm>  
using namespace std;  
#define ads(x) (x<0?-x:x)  
int n,m,k,life;  
int to[5][2] = {0,1,1,0,0,-1,-1,0,0,0};//�ĸ�������ֹͣ�������߷�  
int map[105][105];  
bool vis[105][105][1005];  
struct period  
{  
    char c;  
    int t,v;  
} s[105][105];  
struct node  
{  
    int x,y,step;  
};  
int check(int x,int y)  
{  
    if(x<0 || x>n || y<0 || y>m)  
        return 1;  
    return 0;  
}  
void bfs()  
{  
    node a,next;  
    queue<node> Q;  
    int i,j,flag,dis,tem;  
    a.x = a.y = a.step = 0;  
    Q.push(a);  
    vis[0][0][0] = true;  
    while(!Q.empty())  
    {  
        a = Q.front();  
        Q.pop();  
          if(a.step>life)  
            break;  
        if(a.x == n && a.y == m)  
        {  
            printf("%d\n",a.step);  
            return ;  
        }  
        for(i = 0; i<5; i++)  
        {  
            next = a;  
            next.x+=to[i][0];  
            next.y+=to[i][1];  
            next.step++;  
            if(check(next.x,next.y)) continue;  
            if(!s[next.x][next.y].t && !vis[next.x][next.y][next.step] && next.step<=life)//�ڷ�������������£�ö���ĸ�����  
            {  
                flag = 1;  
                for(j = next.x-1; j>=0; j--)//��λ����㣬����������Ѱ���Ƿ��г��Ϸ����������̨  
                {  
                    if(s[j][next.y].t && s[j][next.y].c == 'S')//�ҵ���һ����̨���������̨�ǳ��������  
                    {  
                        dis = next.x-j;//����̨���˵ľ���  
                        if(dis%s[j][next.y].v) break;//��Ϊ����Ҫ���ӵ���;�ĵ㣬�ӵ�ÿһ����v��������dis��dis��������v�Ļ�����ô�ӵ��ǲ�����ͣ��������  
                        tem = next.step-dis/s[j][next.y].v;//���ߵ�ʱ���ȥ��һ���ӵ����е����λ�������ʱ��  
                        if(tem<0) break;//Ϊ�������ǵ�һ���ӵ���û�о�������㣬��ô�˾��԰�ȫ  
                        if(tem%s[j][next.y].t==0)//�����������������ô���Ǻ������ӵ��պõ�����㣬��������  
                        {  
                            flag = 0;  
                            break;  
                        }  
                    }  
                    if(s[j][next.y].t)//�ҵ���̨�����ǳ����������ô�����̨�ᵱ�º��������ӵ������Ա�����ȫ���ǲ���Ҫ����  
                        break;  
                }
                if(!flag)//������������ˣ�����Ҳ�Ͳ���Ҫ����  
                    continue;  
                //��������Ҳ��һ���ĵ����Ͳ�ע����  
                for(j = next.x+1; j<=n; j++)  
                {  
                    if(s[j][next.y].t && s[j][next.y].c == 'N')  
                    {  
                        dis = j-next.x;  
                        if(dis%s[j][next.y].v) break;  
                        tem = next.step-dis/s[j][next.y].v;  
                        if(tem<0) break;  
                        if(tem%s[j][next.y].t==0)  
                        {  
                            flag = 0;  
                            break;  
                        }  
                    }  
                    if(s[j][next.y].t)  
                        break;  
                }  
                if(!flag)  
                    continue;  
                for(j = next.y-1; j>=0; j--)  
                {  
                    if(s[next.x][j].t && s[next.x][j].c == 'E')  
                    {  
                        dis = next.y-j;  
                        if(dis%s[next.x][j].v) break;  
                        tem = next.step-dis/s[next.x][j].v;  
                        if(tem<0) break;  
                        if(tem%s[next.x][j].t==0)  
                        {  
                            flag = 0;  
                            break;  
                        }  
                    }  
                    if(s[next.x][j].t)  
                        break;  
                }  
                if(!flag)  
                    continue;  
                for(j = next.y+1; j<=m; j++)  
                {  
                    if(s[next.x][j].t && s[next.x][j].c == 'W')  
                    {  
                        dis = j-next.y;  
                        if(dis%s[next.x][j].v) break;  
                        tem = next.step-dis/s[next.x][j].v;  
                        if(tem<0) break;  
                        if(tem%s[next.x][j].t==0)  
                        {  
                            flag = 0;  
                            break;  
                        }  
                    }  
                    if(s[next.x][j].t)  
                        break;  
                }  
                if(!flag)  
                    continue;  
                vis[next.x][next.y][next.step] = true;  
                Q.push(next);  
            }  
        }  
    }  
    printf("Bad luck!\n");  
}  
int main()  
{  
    int i,j,x,y,t,v;  
    char str[3];  
    while(~scanf("%d%d%d%d",&n,&m,&k,&life))  
    {  
        memset(s,0,sizeof(s));  
        memset(vis,false,sizeof(vis));  
        for(i = 0; i<k; i++)  
        {  
            scanf("%s%d%d%d%d",str,&t,&v,&x,&y);  
            s[x][y].v = v;  
            s[x][y].t = t;  
            s[x][y].c = str[0];  
        }  
        bfs();  
    }  
    return 0;  
} 
