#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 405;
const int inf=9999999;
int map[ maxn ][ maxn ];
const int dx[]={0,0,0,1,-1};
const int dy[]={0,1,-1,0,0};
struct Node{
    int x,y,time;
};
int bfs(){
    if( map[0][0]==0 ) return -1;
    else if( map[0][0]==-1 ) return 0;
    Node tmp,now;
    tmp.x=tmp.y=tmp.time=0;
    queue<Node>q;
    q.push( tmp );
    while( !q.empty() ){
        now=q.front();
        q.pop();
        for( int i=1;i<5;i++ ){
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            tmp.time=now.time+1;
            if( tmp.x<0||tmp.y<0||tmp.x>=maxn||tmp.y>=maxn ) continue;
            if( map[tmp.x][tmp.y]==-1 ) return tmp.time;
            if( tmp.time>=map[tmp.x][tmp.y] ) continue;
            map[tmp.x][tmp.y]=tmp.time;
            q.push( tmp );
        }
    }
    return -1;
}
int main(){
    int n;
    while( scanf("%d",&n)!=EOF ){
        int x,y,t;
        memset( map,-1,sizeof(map) );
        while( n-- ){
            scanf("%d%d%d",&x,&y,&t);
            for( int k=0;k<5;k++ ){
                int tx=x+dx[ k ];
                int ty=y+dy[ k ];
                if( tx<0||ty<0||tx>=maxn||ty>=maxn ) continue;
                if( map[tx][ty]==-1 ) map[tx][ty]=t;
                else map[tx][ty]=min( map[tx][ty],t );
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
