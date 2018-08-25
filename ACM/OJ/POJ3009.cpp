#include<stdio.h>
#include<limits.h>
#define MAX 21
int map[MAX][MAX] ;
int h, w , min = INT_MAX ;//��һ��Ҫע��ľ��������ˣ�����ϰ���Ե�ȥ��Ϊ��
int sx , sy , ex, ey ;    //��¼��ʼ����ͽ�������
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void init(){//�������ݳ�ʼ���ĺ���
 for(int i = 0 ;i < h ; i++)
  for(int j = 0 ; j < w ; j++){
   scanf("%d",&map[i][j]) ;
   if(map[i][j] == 2){
    map[i][j] = 0 ;//!!�ڳ���Ҫ��ɵ�ʱ��������������⣬��Ϊ����ĳ���û��
                   //����2��������Ըɴ���Ϊ0����
    sx = i ;
    sy = j ;
   }
   
    if(map[i][j] == 3) {
     ex = i ;
     ey = j ;
    }
  }
     min = INT_MAX ;//!��Ϊ�ж�����������ÿһ�ζ�Ҫˢ��min�ĳ�ʼֵINT_MAX
}
 
int ok(int x , int y){//�ж��Ƿ�Խ��ĺ���
if(x >=0 && x < h && y >=0 && y < w)
return 1 ;
return 0 ;
}

void dfs(int step , int x , int y){//����
 
 if(step >=10)//�������10���������뿪
 return ;
 for(int i = 0 ; i < 4; i++)//���ĸ�����̽��
 {
    int k =x+d[i][0] , v = y+d[i][1] ;
  
    if(map[k][v] == 1)//�������ǰ���ϰ������߲�ͨ
    continue ;
  
    while(!map[k][v])//���е�·һֱ�ߵ�����0�ĵط�Ϊֹ
    {
     k += d[i][0] ;
     v += d[i][1] ;
    }
    if(ok(k,v))//���û���ܳ�����
   {
     if(map[k][v] == 1){//�����ʱ���ϰ�������
     map[k][v] = 0 ;//�����ϰ���
     dfs(step+1 , k-d[i][0] , v-d[i][1]) ;//����һ��������������-����Ҫ��
     map[k][v] = 1 ;//����Ҫ��ԭԭ���ĳ���
    }
      if(map[k][v] == 3){//����պ��ߵ���Ŀ�ĵ�
       if(step+1 < min)//�����ʱ�õ��Ĳ���Ҫ���Ѿ��õ���С���޸�min��ֵ
       min = step + 1;//��Ϊstep�Ǵ�0��ʼ����������Ҫ����1
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
