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
const int maxn = 2e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

#define Key_value ch[ch[root][1]][0]
//父结点、左右孩子、点值、子树规模
int pre[maxn],ch[maxn][2],size[maxn];
//子树是否被翻转 
int rev[maxn];
char key[maxn];
//根结点、结点数量
int root,tot1;
int pos;//光标位置 
//内存池、内存池容量 
int s[maxn],tot2;

char str[maxn];

void NewNode(int &r,int father,char k){
    if(tot2)
		r=s[tot2--];
    else
		r=++tot1;
    pre[r]=father;
    ch[r][0]=ch[r][1]=0;
    key[r]=k;
    rev[r]=0;
    size[r]=1;
}
//反转的更新
void Update_Rev(int r){
    if(!r)
		return;
    swap(ch[r][0],ch[r][1]);
    rev[r]^=1;//这里要注意，一定是异或1
}
void Push_Up(int r){
    int lson=ch[r][0],rson=ch[r][1];
    size[r]=size[lson]+size[rson]+1;
}
void Push_Down(int r){
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
    NewNode(x,father,str[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
void Init(){
	pos=0;
    root=tot1=tot2=0;
    ch[root][0]=ch[root][1]=pre[root]=size[root]=rev[root]=0;
    NewNode(root,0,' ');
    NewNode(ch[root][1],root,' ');
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
int Get_Min(int r){
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
    if(t==k)
		return r;
    if(t>k)
		return Get_Kth(ch[r][0],k);
    else
		return Get_Kth(ch[r][1],k-t);
}
//在第pos个数后插入tot个数
void Insert(int tot){
    Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Min(ch[root][1]),root);
    Build(Key_value,0,tot-1,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r){
    if(!r)
		return;
    s[++tot2]=r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}
//从第pos个数开始连续删除tot个数
void Delete(int tot){
    Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Kth(root,pos+tot+2),root);
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//将从第pos个数连续开始的tot 反转
void Reverse(int tot){
    Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Kth(root,pos+tot+2),root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);
    Init();
    while(n--){
    	scanf("%s",op);
        if(op[0]=='I'){
            scanf("%d%*c",&x);
            gets(str);
            Insert(x);
        }
        else if(op[0]=='M'){
            scanf("%d",&x);
            pos=x;
        }
        else if(op[0]=='D'){
            scanf("%d",&x);
            Delete(x);
        }
        else if(op[0]=='R'){
            scanf("%d",&x);
            Reverse(x);
        }
        else if(op[0]=='G')
            printf("%c\n",key[Get_Kth(root,pos+2)]);
        else if(op[0]=='P')
			pos--;
        else
			pos++;
    }
    return 0;
}
