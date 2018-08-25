#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int g[65][130][1300];
int n,m,l,tt,ans;
int dx[6]={0,0,-1,1,0,0};
int dy[6]={0,0,0,0,1,-1};
int dz[6]={1,-1,0,0,0,0};
struct node{
  int x,y,z;
};

int check(int x,int y,int z){
  if((x<0)||(y<0)||(z<0)){
    return 0;
  }
  if((x>=l)||(y>=n)||(z>=m)){
    return 0;
  }
  return 1;
}

void bfs(int x,int y,int z){
  g[x][y][z]=0;
  struct node t;
  t.x=x;t.y=y;t.z=z;
  queue<node>q;
  q.push(t);
  int tmp=1;
  while(!q.empty()){
    struct node qq=q.front();
    q.pop();
    for(int i=0;i<6;i++){
      int nx=qq.x+dx[i];
      int ny=qq.y+dy[i];
      int nz=qq.z+dz[i];
      if(check(nx,ny,nz)&&g[nx][ny][nz]){
        t.x=nx;t.y=ny;t.z=nz;
        g[nx][ny][nz]=0;
        tmp++;
        q.push(t);
      }
    }
  }
  if(tmp>=tt){
    ans+=tmp;
  }
}

int main(){
  int t;
  scanf("%d%d%d%d",&n,&m,&l,&tt);
  for(int i=0;i<l;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<m;k++){
        scanf("%d",&g[i][j][k]);
      }
    }
  }
  for(int i=0;i<l;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<m;k++){
        if(g[i][j][k]==1){
          bfs(i,j,k);
        }
      }
    }
  }
  printf("%d\n",ans);
} 
