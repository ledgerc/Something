#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<String> 
#include<queue>
using namespace std;
struct knight{
    int x,y,step;
    int g,h,f;
    bool operator < (const knight & k) const{      //���رȽ������
        return f > k.f;
    }
}k;
bool visited[8][8];                                //�ѷ��ʱ��(�ر��б�)
int x1,y1,x2,y2,ans;                               //���(x1,y1),�յ�(x2,y2),�����ƶ�����ans
int dirs[8][2]={{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};//8���ƶ�����
priority_queue<knight> que;                        //��С���ȼ�����(�����б�)
bool in(const knight & a){                         //�ж�knight�Ƿ���������
    if(a.x<0 || a.y<0 || a.x>=8 || a.y>=8)
        return false;
    return true;
}
int Heuristic(const knight &a){                    //manhattan���ۺ���
    return (abs(a.x-x2)+abs(a.y-y2))*10;
}
void Astar(){                                      //A*�㷨
    knight t,s;
    while(!que.empty()){
        t=que.top(),que.pop(),visited[t.x][t.y]=true;
        if(t.x==x2 && t.y==y2){
            ans=t.step;
            break;
        }
        for(int i=0;i<8;i++){
            s.x=t.x+dirs[i][0],s.y=t.y+dirs[i][1];
            if(in(s) && !visited[s.x][s.y]){
                s.g = t.g + 23;                 //23��ʾ����5����10��ȡ��ceil
                s.h = Heuristic(s);
                s.f = s.g + s.h;
                s.step = t.step + 1;
                que.push(s);
            }
        }
    }
}
int main(){
    char line[5];
    while(gets(line)){
        x1=line[0]-'a',y1=line[1]-'1',x2=line[3]-'a',y2=line[4]-'1';
        memset(visited,false,sizeof(visited));
        k.x=x1,k.y=y1,k.g=k.step=0,k.h=Heuristic(k),k.f=k.g+k.h;
        while(!que.empty()) que.pop();
        que.push(k);
        Astar();
        printf("To get from %c%c to %c%c takes %d knight moves.\n",line[0],line[1],line[3],line[4],ans);
    }
    return 0;
}
