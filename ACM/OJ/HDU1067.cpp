/*���⣺��4*8 ��ͼ�У�����4�����͵��ƣ�ÿ�������1-7������42��ʾ��4���Ƶĵڶ��ţ�
���ڸ���4*7һ��28�ţ�ͬʱ����ߵ�һ�п�ʼ�յģ���һ����Ҫ�����ǰ�ÿ�����͵�1���ƴ��ϵ��·������пյ�λ���ϣ�
Ȼ�����³��ֵĿ�λ�ã���Ҫ��ѡ��λ����ߵ������Ƶĺ�̣����û�еĻ����Ͳ��ܲ����� 
�ⷨ����Ŀ��״̬�ܶ࣬����Ҫ��ô��ʾһ��״̬�Ѿ����������ء�
�ǾͰѾ�����һ��ת�����ѵ�ǰ������չ������2Ϊ������Ϊʮ���Ƶ��������2^32��������Long Long����
�������洢��Щ��������map��setӦ��Ҳ���ԣ�������΢���㣬�������ü򵥵�hash*/
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iterator>
#include<stack>
using namespace std;
const int INF=1e9+7;
const int eps=0.0000001;
typedef __int64 LL;
const LL mod=1000007;
int maze[4][8];
LL Hash[mod];
LL base[32];
struct node{
    int px[4],py[4]; //�����ĸ���λ
    int S[4][8];     //����ͼ
    int dist;
}Nod[100005];
int id;
queue<int> que;
int goal[4][8]={    //����״̬
{ 11,12,13,14,15,16,17,0 },
{ 21,22,23,24,25,26,27,0 },
{ 31,32,33,34,35,36,37,0 },
{ 41,42,43,44,45,46,47,0 }
};
LL G;
void GetBase(){//���2^i
    base[0]=1;
    for(int i=1;i<32;i++)
		base[i]=base[i-1]*2;
}
int GetId(int x,int y){
	return x*8+y;
}
void SetHead(){
    for(int i=0;i<4;i++)
        for(int j=1;j<8;j++){
        int a=maze[i][j]/10;    
        int b=maze[i][j]%10;
        if(b==1){
			maze[a-1][0]=maze[i][j];
			maze[i][j]=0;
		} //��11,21,31,41������
    }
}
LL GetHash(int S[4][8]){
    LL ret=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<8;j++)
			ret+=(LL)S[i][j]*base[GetId(i,j)];  //�õ���ϣֵ
    return ret;
}
bool InsertHash(LL val){
	LL v=val%mod;
	while(Hash[v]!=-1&&Hash[v]!=val)
		v=(v+10)%mod;   //����
	if(Hash[v]==-1){
		Hash[v]=val;
		return true;
	}  //���Բ���
	return false;
}
void init(){
    memset(Hash,-1,sizeof(Hash));
    while(!que.empty())  que.pop();
    id=0;
    G=GetHash(goal);
    int k=0;
    int cur=id++;
    for(int i=0;i<4;i++)
        for(int j=0;j<8;j++){
        Nod[cur].S[i][j]=maze[i][j];
        if(maze[i][j]==0){ Nod[cur].px[k]=i; Nod[cur].py[k++]=j; }  //�õ������״̬
    }
    Nod[cur].dist=0;
    que.push(cur);
}
void Change_S(node& e,int x,int y,int pick,int k){
    for(int i=0;i<4;i++)
        for(int j=0;j<8;j++)
        if(e.S[i][j]==pick){
        e.S[i][j]=0;
        e.S[x][y]=pick;
        e.px[k]=i; e.py[k]=j;
        return;
    }
}
void AddNode(int now){
    node& e=Nod[now];
    for(int i=0;i<4;i++){
        int x=e.px[i];
        int y=e.py[i];
        int pre=e.S[x][y-1];
        if(pre==0)
			continue;  //Ҳ�ǿ�λ����

        int a=pre/10;
        int b=pre%10;
        if(b==7)
			continue;//������*7

        int pick=pre+1;
        node t=e;
        t.dist++;
        Change_S(t,x,y,pick,i); 
        LL nowG=GetHash(t.S);
        if(!InsertHash(nowG))
			continue;  //�ܷ����

        int cur=id++;
        Nod[cur]=t;
        que.push(cur);
    }
}
int solve(){
    SetHead();
    init();
    while(!que.empty()){
        int now=que.front();  que.pop();
        node& e=Nod[now];
        LL nowG=GetHash(e.S);
        if(nowG==G)
			return e.dist;  //�ҵ���
        AddNode(now);
    }
    return -1;
}
int main(){
    int T;
    GetBase();
    cin>>T;
    while(T--){
        memset(maze,0,sizeof(maze));
        for(int i=0;i<4;i++)
            for(int j=1;j<8;j++)
				cin>>maze[i][j];
        printf("%d\n",solve());
    }
    return 0;
}
