#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

#define Key_value ch[ch[root][1]][0]
//父结点、左右孩子、点值、子树规模
int pre[maxn],ch[maxn][2],key[maxn],size[maxn];
//子树是否被翻转 
int rev[maxn];
//最小值
int m[maxn]; 
//根结点、结点数量
int root,tot1;
//内存池、内存池容量 
int s[maxn],tot2;

//增量的延迟标记 
int add[maxn];
int a[maxn];
int n,q;

//debug部分**********************************
void Treavel(int x){
   	if(x){
       	Treavel(ch[x][0]);
   	    printf("结点：%2d: 左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d rev = %2d key=%2d\n",x,ch[x][0],ch[x][1],pre[x],size[x],rev[x],key[x]);
   	    Treavel(ch[x][1]);
  		}
}
void debug(){
    printf("root:%d\n",root);
    Treavel(root);
}
//*******************************************

void NewNode(int &r,int father,int k){
    if(tot2)
		r=s[tot2--];
    else
		r=++tot1;
    pre[r]=father;
    ch[r][0]=ch[r][1]=0;
    key[r]=m[r]=k;
    rev[r]=add[r]=0;
    size[r]=1;
}
//反转的更新
void Update_Rev(int r){
    if(!r)
		return;
    swap(ch[r][0],ch[r][1]);
    rev[r]^=1;//这里要注意，一定是异或1
}
void Update_Add(int r,int ADD){
	if(!r)
		return;
	add[r]+=ADD;
	key[r]+=ADD;
	m[r]+=ADD;
}
void Push_Up(int r){
    int lson=ch[r][0],rson=ch[r][1];
    size[r]=size[lson]+size[rson]+1;
    m[r]=key[r];
    if(lson)
    	m[r]=min(m[r],m[lson]);
    if(rson)
    	m[r]=min(m[r],m[rson]);
}
void Push_Down(int r){
    if(add[r]){
        Update_Add(ch[r][0],add[r]);
        Update_Add(ch[r][1],add[r]);
        add[r]=0;
    }
    if(rev[r]){
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r]=0;
    }
}
void Build(int &x,int l,int r,int father){
    if(l>r)
		return;
    int mid=(l+r)/2;
    NewNode(x,father,a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
void Init(){
    root=tot1=tot2=0;
    ch[root][0]=ch[root][1]=pre[root]=add[root]=size[root]=rev[root]=key[root]=0;
    m[root]=inf;
	NewNode(root,0,inf);
    NewNode(ch[root][1],root,inf);
    Build(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Rotate(int x,int kind){
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}
void Splay(int r,int goal){
    Push_Down(r);
    while(pre[r]!=goal){
        if(pre[pre[r]]==goal){
            Push_Down(pre[r]);
            Push_Down(r);
            Rotate(r,ch[pre[r]][0]==r);
        }
        else{
            Push_Down(pre[pre[r]]);
            Push_Down(pre[r]);
            Push_Down(r);
            int y=pre[r];
            int kind=ch[pre[y]][0]==y;
            if(ch[y][kind]==r){
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    if(goal==0)
		root=r;
}
int Ger_Min(int r){
	Push_Down(r);
	while(ch[r][0]){
		r=ch[r][0];
		Push_Down(r);
	}
	return r;
}
int Get_Max(int r){
	Push_Down(r);
	while(ch[r][1]){
		r=ch[r][1];
		Push_Down(r);
	}
	return r;
}
int Get_Kth(int r,int k){
    Push_Down(r);
    int t=size[ch[r][0]]+1;
    if(t==k)return r;
    if(t>k) return Get_Kth(ch[r][0],k);
    else return Get_Kth(ch[r][1],k-t);
}
void ADD(int l,int r,int D){
	Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    Update_Add(Key_value,D);
    Push_Up(ch[root][1]);
    Push_Up(root);
} 
//删除根节点 
void Remove(){
    if(ch[root][0]==0){//没有左孩子
        root=ch[root][1];
        pre[root]=0;
    }
    else{
        int m=Get_Max(ch[root][0]);
        Splay(m,root);
        ch[m][1]=ch[root][1];
        pre[ch[root][1]]=m;
        root=m;
        pre[root]=0;
        Push_Up(root);//要更新
    }
}
//在第pos个数后插入tot个数
void Insert(int pos,int P){
    Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Kth(root,pos+2),root);
	NewNode(Key_value,ch[root][1],P);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r){
    if(!r) return;
    s[++tot2]=r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}
//从第pos个数开始连续删除tot个数
void Delete(int pos){
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+2),root);
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//循环右移 
void Revolve(int l,int r,int T){
	int len=r-l+1;
	T=(T%len+len)%len;
    if(T==0) return;
    int c=r-T+1;//将区间[c,r]放在[l,c-1]前面
    
	Splay(Get_Kth(root,c),0);
    Splay(Get_Kth(root,r+2),root);
    int tmp=Key_value;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,l+1),root);
    Key_value=tmp;
    pre[Key_value]=ch[root][1];//这个不用忘记
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int Query_Min(int l,int r){
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    return m[Key_value];
}
//反转
void Reverse(int l,int r){
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int main(){
	char op[20];
    int x,y,z;
	scanf("%d",&n);
        for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
        Init();
        debug(); 
        scanf("%d",&q);
        while(q--){
            scanf("%s",op);
            if(strcmp(op,"ADD")==0){
                scanf("%d%d%d",&x,&y,&z);
                ADD(x,y,z);
            }
            else if(strcmp(op,"REVERSE")==0){
                scanf("%d%d",&x,&y);
                Reverse(x,y);
            }
            else if(strcmp(op,"REVOLVE")==0){
                scanf("%d%d%d",&x,&y,&z);
                Revolve(x,y,z);
            }
            else if(strcmp(op,"INSERT")==0){
                scanf("%d%d",&x,&y);
                Insert(x,y);
            }
            else if(strcmp(op,"DELETE")==0){
                scanf("%d",&x);
                Delete(x);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%d\n",Query_Min(x,y));
            }
        }
    
    return 0;
}
/*
5
1
2
3
4
5
2
ADD 2 4 1
MIN 4 5

5
*/
