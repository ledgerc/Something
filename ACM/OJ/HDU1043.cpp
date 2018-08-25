#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
const int maxn=4e5+10;
int ha[9]={1,1,2,6,24,120,720,5040,40320};//阶乘数组 
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//方向数组 
char d[10]="udlr";  
int vis[maxn];
struct node{
    int f[3][3];
    int x,y;
    int g,h;
    int hash_num;
    bool operator < (const node a)const{
        return h+g>a.h+a.g;
    }
};
struct path{
    int pre;
    char ch;
}p[maxn];
int get_hash(node e){//康托展开，压缩空间
    int a[9],i,j,k=0,ans=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            a[k++]=e.f[i][j];
    }
    for(i=0;i<9;i++){
        k=0;
        for(j=0;j<i;j++)
            if(a[j]>a[i])k++;
        ans+=ha[i]*k;
    }
    return ans;
}
//评估函数，获得评估值  
//计算1~8的数字回到原点需要的步数作为评估值，必定小于实际操作数  
int get_h(node e){
    int i,j,ans=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(e.f[i][j])
            ans+=abs(i-(e.f[i][j]-1)/3)+abs(j-(e.f[i][j]-1)%3);
        }
    }
    return ans;
}
void print(int x){
    if(p[x].pre==-1)
		return;
    print(p[x].pre);
    printf("%c",p[x].ch);
}
void A_star(node e){
    memset(vis,0,sizeof(vis));
    int i,j,k,end_ans,xx,yy;
    node a,b;
    for(i=0;i<9;i++)
        a.f[i/3][i%3]=(i+1)%9;
    end_ans=get_hash(a);
    e.hash_num=get_hash(e);
    e.g=0;e.h=get_h(e);
    vis[e.hash_num]=1;
    p[e.hash_num].pre=-1;
    
    if(e.hash_num==end_ans){
		printf("\n");
		return;
	}
    
    priority_queue<node>q; 
    q.push(e);
    while(!q.empty()){
        e=q.top();
        q.pop();
        for(i=0;i<4;i++){
            xx=e.x+dir[i][0];
            yy=e.y+dir[i][1];
            if(xx<0||yy<0||xx>=3||yy>=3)
				continue;
            a=e;
            swap(a.f[e.x][e.y],a.f[xx][yy]);
            k=get_hash(a);
            if(vis[k])
				continue;
            vis[k]=1;
            a.hash_num=k;
            a.x=xx;
            a.y=yy;
            a.g++;
            a.h=get_h(a);
            p[k].pre=e.hash_num;
            p[k].ch=d[i];
            if(k==end_ans){
                print(k);
                printf("\n");
                return;
            }
            q.push(a);
        }
    }
}
int main(){
    char a[30];
    while(gets(a)){
        int i,j,k,n;
        node e;
        n=strlen(a);
        for(i=0,j=0;i<n;i++){
            if(a[i]==' ')
				continue;
            if(a[i]=='x'){
				e.f[j/3][j%3]=0;
				e.x=j/3;
				e.y=j%3;
			}
            else
				e.f[j/3][j%3]=a[i]-'0';
            j++;
        }
        //判断逆序数
        for(i=0,k=0;i<9;i++){
            if(e.f[i/3][i%3]==0)
				continue;
            for(j=0;j<i;j++){
                if(e.f[j/3][j%3]==0)
					continue;
                if(e.f[j/3][j%3]>e.f[i/3][i%3])
					k++;
            }
        }
        if(k&1)
			printf("unsolvable\n");
        else A_star(e);
	}
    return 0;
}
