#include<iostream> 
#include<string.h>
using namespace std;  
  
const int prime=1999;  //长度为n区间的最大素数 (本题n=2000)  
  
typedef class  
{  
    public:  
        int x,y;  
}Node;  
  
typedef class HashTable  
{  
    public:  
        int x,y;   //标记key值对应的x,y  
        HashTable* next;  //当出现地址冲突时，开放寻址  
  
        HashTable()  //Initial  
        {  
            next=0;  
        }  
}Hashtable;  
  
Node pos[2001];  
Hashtable* hash[prime];   //hash[]是指针数组，存放地址  
  
void insert_vist(int k)  
{  
    int key=((pos[k].x * pos[k].x)+(pos[k].y * pos[k].y))%prime +1;   //+1是避免==0  
                                                                      //使key从[0~1998]后移到[1~1999]  
    if(!hash[key])  
    {  
        Hashtable* temp=new Hashtable;  
        temp->x=pos[k].x;  
        temp->y=pos[k].y;  
        hash[key]=temp;  
    }  
    else   //hash[key]已存地址，地址冲突  
    {  
        Hashtable* temp=hash[key];  
          
        while(temp->next)     //开放寻址，直至next为空  
            temp=temp->next;  
  
        temp->next=new HashTable;   //申请新结点，用next指向，记录x、y  
        temp->next->x=pos[k].x;  
        temp->next->y=pos[k].y;  
    }  
    return;  
}  
  
bool find(int x,int y)  
{  
    int key=((x * x)+(y * y))%prime +1;  
  
    if(!hash[key])   //key对应的地址不存在  
        return false;  
    else  
    {  
        Hashtable* temp=hash[key];  
  
        while(temp)  
        {  
            if(temp->x==x && temp->y==y)  
                return true;  
  
            temp=temp->next;  
        }  
    }  
  
    return false;  
}  
  
int main(void)  
{  
    int n;  
    while(cin>>n)  
    {  
        if(!n)  
            break;  
  
        memset(hash,0,sizeof(hash));   //0 <-> NULL  
  
        for(int k=1;k<=n;k++)  
        {  
            cin>>pos[k].x>>pos[k].y;  
            insert_vist(k);   //插入哈希表，标记散点  
        }  
  
        int num=0;  //正方形的个数  
        for(int i=1;i<=n-1;i++)  
            for(int j=i+1;j<=n;j++)  
            {  
                int a=pos[j].x-pos[i].x;  
                int b=pos[j].y-pos[i].y;  
  
                int x3=pos[i].x+b;  
                int y3=pos[i].y-a;  
                int x4=pos[j].x+b;  
                int y4=pos[j].y-a;  
                  
                if(find(x3,y3) && find(x4,y4))  
                    num++;  
  
                x3=pos[i].x-b;  
                y3=pos[i].y+a;  
                x4=pos[j].x-b;  
                y4=pos[j].y+a;  
  
                if(find(x3,y3) && find(x4,y4))  
                    num++;  
            }  
  
        cout<<num/4<<endl;  //同一个正方形枚举了4次  
    }  
    return 0;  
}  
