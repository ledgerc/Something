#include<stdio.h>
#include<limits.h>
#define MAX 21
int map[MAX][MAX] ;
int h, w , min = INT_MAX ;//第一个要注意的就是坐标了，不能习惯性地去认为。
int sx , sy , ex, ey ;    //记录开始坐标和结束坐标
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void init(){//用于数据初始化的函数
 for(int i = 0 ;i < h ; i++)
  for(int j = 0 ; j < w ; j++){
   scanf("%d",&map[i][j]) ;
   if(map[i][j] == 2){
    map[i][j] = 0 ;//!!在程序将要完成的时候这里出现了问题，因为后面的程序没有
                   //处理2的情况所以干脆置为0好了
    sx = i ;
    sy = j ;
   }
   
    if(map[i][j] == 3) {
     ex = i ;
     ey = j ;
    }
  }
     min = INT_MAX ;//!因为有多组数据所以每一次都要刷新min的初始值INT_MAX
}
 
int ok(int x , int y){//判断是否越界的函数
if(x >=0 && x < h && y >=0 && y < w)
return 1 ;
return 0 ;
}

void dfs(int step , int x , int y){//搜索
 
 if(step >=10)//如果超过10步，果断离开
 return ;
 for(int i = 0 ; i < 4; i++)//往四个方向探索
 {
    int k =x+d[i][0] , v = y+d[i][1] ;
  
    if(map[k][v] == 1)//如果在眼前有障碍物在走不通
    continue ;
  
    while(!map[k][v])//可行的路一直走到不是0的地方为止
    {
     k += d[i][0] ;
     v += d[i][1] ;
    }
    if(ok(k,v))//如果没有跑出界外
   {
     if(map[k][v] == 1){//如果此时在障碍物上面
     map[k][v] = 0 ;//击碎障碍物
     dfs(step+1 , k-d[i][0] , v-d[i][1]) ;//后退一步继续搜索！‘-’重要！
     map[k][v] = 1 ;//回溯要复原原来的场景
    }
      if(map[k][v] == 3){//如果刚好走到了目的地
       if(step+1 < min)//如果此时得到的步数要比已经得到的小则修改min的值
       min = step + 1;//因为step是从0开始计数的所以要加上1
    }
   }
 }
}
int main(){
 while(scanf("%d %d",&w,&h),h&&w)
 {
  init() ;
  dfs(0,sx,sy) ;
  if(min < INT_MAX)
  printf("%d\n",min) ;
  else
  printf("-1\n") ;
 } 
 return 0 ;
}
