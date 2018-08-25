#include <stdio.h>
#include <stdlib.h>

//所有都是白的，或者所有都是黑的
int all_white_or_black(int* bits, int len)
{
  int i = 0;
  for (i = 0; i < len - 1; i++)
    if (bits[i] != bits[i + 1])
      return 0;
  return 1;
}

//改变一个格子的颜色，并根据其所在位置改变其周围格子的颜色
void change_color(int* arr, int i)
{
  arr[i] = !(arr[i]);
  int x = i/4;
  int y = i%4;
  if (y < 3)
    arr[i + 1] = !(arr[i + 1]);
  if (y > 0)
    arr[i - 1] = !(arr[i - 1]);
  if (x > 0)
    arr[i - 4] = !(arr[i - 4]);
  if (x < 3)
    arr[i + 4] = !(arr[i + 4]);
}

//递归判断
void combine(int* arr, int len, int* result, int count, const int NUM, int* last)
{
  int i;
  for (i = len; i >= count; i--)
  {
    result[count - 1] = i - 1;
    if (count > 1)
      combine(arr, i - 1, result, count - 1, NUM, last);
    else
    {
      int j = 0;
      //在这里生成arr的副本
      int* new_arr = (int*)malloc(sizeof(int)*16);
      for (j = 0; j < 16; j++)
        new_arr[j] = arr[j];

      for (j = NUM - 1; j >=0; j--)
      {
         change_color(new_arr, result[j]);
      }
      if (all_white_or_black(new_arr, 16))
      {
         *last = NUM;
         free(new_arr);
         break;
      }
      free(new_arr);
    }
  }
}

int main()
{
  char str[5];
  int bits[16];
  int count = 15;
  int lines = 4;
  while (lines--)
  {
    scanf("%s", str);
    int i;
    for (i = 0; i < 4; i++)
    {
      if (str[i] == 'b')
        bits[count--] = 1;
      else
        bits[count--] = 0;
    }
  }

  if (all_white_or_black(bits, 16))
    printf("%d\n", 0);
  else
  {
    //生成bits数组的副本
    int* new_bits = (int*)malloc(sizeof(int)*16);
    int i;
    for (i = 0; i < 16; i++)
      new_bits[i] = bits[i];

    int j;
    //这里last用来接受combine函数里面的NUM，即需要的步数
    int last = 0;
    for (j = 1; j <= 16; j++)
    {
      int* result = (int*)malloc(sizeof(int)*j);
      combine(new_bits, 16, result, j, j, &last);
      if (last == j)
      {
        printf("%d\n", last);
        break;
      }
      //new_bits已被改变，所以要还原为bits
      for (i = 0; i < 16; i++)
        new_bits[i] = bits[i];
     
      free(result);
    }
    free(new_bits);

    if (j == 17)
      printf("Impossible\n");
  }
 
  return 0;
}
/*
#include<iostream>  
#include<queue>  
#include<cstdio>  
using namespace std;  
#include<memory.h>  
  
struct Node  
{  
    int state;  
    int step;  
};  
  
bool visit[65536];  
  
int change[16] =   //16种状态转换，对应4*4的翻子位置  
{  
     51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};  
  
int bfs(int state)  
{  
    int i;  
    memset(visit,false,sizeof(visit));    //标记每一个状态都未访问过  
    queue<Node>q;  
    Node cur,next;  
    cur.state = state;  
    cur.step = 0;  
    q.push(cur);  
    visit[state] = true;  
  
    while(!q.empty())  
    {  
        cur = q.front();  
        q.pop();  
        if(cur.state == 0 || cur.state == 0xffff)   //65535  
            return cur.step;  
        for(i=0;i<16;i++)  
        {  
            next.state = cur.state^change[i];  
            next.step = cur.step + 1;  
            if(visit[next.state])  
                continue;  
            if(next.state == 0 || next.state == 0xffff)   //65535  
                return next.step;  
            visit[next.state] = true;  
            q.push(next);  
        }  
    }  
    return -1;  
}  
  
int main(void)  
{  
    int i,j,state,ans;  
    char ch[5][5];  
    while(scanf("%s",ch[0])!=EOF)  
    {  
        for(i = 1 ; i < 4 ; ++i)  
            scanf("%s",ch[i]);  
        state = 0;  
        for(i = 0 ; i < 4 ; ++i)  
        {  
            for(j = 0 ; j < 4 ; ++j)  
            {  
                state <<= 1;  
                if(ch[i][j] == 'b')  
                    state += 1;  
                //state ^= (1<<((3-i)*4+(3-j)));  
            }  
        }  
        ans = bfs(state);  
        if(ans == -1)  
            puts("Impossible");  
        else  
            printf("%d\n",ans);  
    }  
    return 0;  
}  
*/
