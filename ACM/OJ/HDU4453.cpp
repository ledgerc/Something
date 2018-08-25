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
const int maxn = 1e6+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

#define Key_value ch[ch[root][1]][0]
int n,m,k1,k2;
int pre[maxn],ch[maxn][2],key[maxn],size[maxn];
int rev[maxn];
int root,tot1;
int s[maxn],tot2;

int add[maxn];
int a[maxn];

void Treavel(int x){
   	if(x){
       	Treavel(ch[x][0]);
   	    printf("结点：%2d: 左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d rev = %2d key = %2d\n",x,ch[x][0],ch[x][1],pre[x],size[x],rev[x],key[x]);
   	    Treavel(ch[x][1]);
  		}
}
void debug(){
    printf("root:%d\n",root);
    Treavel(root);
}

void NewNode(int &r,int father,int k){
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
} 
void Push_Up(int r){
   	int lson=ch[r][0],rson=ch[r][1];
   	size[r]=size[lson]+size[rson]+1;
}
void Push_Down(int r){
   	if(rev[r]){
   	    rev[r]=0;
   	    rev[ch[r][0]]^=1;
   	    rev[ch[r][1]]^=1;
   	    swap(ch[r][0],ch[r][1]);
   	}
   	if(add[r]){
   		Update_Add(ch[r][0],add[r]);
   		Update_Add(ch[r][1],add[r]);
   		add[r]=0;
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
   	ch[root][0]=ch[root][1]=pre[root]=size[root]=rev[root]=key[root]=0;
   	NewNode(root,0,0);
   	NewNode(ch[root][1],root,0);
   	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
   	Build(Key_value,0,n-1,ch[root][1]);
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
void Insert(int pos,int val){
	int x=Get_Kth(root,pos);
	if(ch[x][1]==0)
		NewNode(ch[x][1],x,val);
	else{
		x=Get_Min(ch[x][1]);
		NewNode(ch[x][0],x,val);
	}
	while(x){
		Push_Up(x);
		x=pre[x];
	}
	n++;//!!!!!!!!
}
int Del(int pos){
	int x=Get_Kth(root,pos-1);
	int y=Get_Kth(root,pos+1);
	Splay(x,0);
	Splay(y,root);
	
	x=ch[ch[root][1]][0];
	pre[x]=0; ch[ch[root][1]][0]=0;
	Push_Up(ch[root][1]);
	Splay(1,0);
	n--;
	return key[x];
}
//删除最后一个点（第n个），加入到第一个点前。 
void move1(){
	int x=Del(n+1);
	Insert(0+1,x);
}
void move2(){
	int x=Del(1+1);
	Insert(n+1,x);
}
void jie(int k){
	int x=Get_Kth(root,k+2);
	Splay(x,root);
	Push_Up(ch[root][1]);
	Push_Up(root);
}
void ADD(int l,int r,int D){
	Splay(Get_Kth(root,l),0);
   	Splay(Get_Kth(root,r+2),root);
   	Update_Add(Key_value,D);
   	Push_Up(ch[root][1]);
   	Push_Up(root);
}
//将从第pos个数连续开始的tot反转
void Reverse(int tot){
//    Splay(Get_Kth(root,pos),0);
//    Splay(Get_Kth(root,pos+tot+1),root);
    Splay(Get_Kth(root,tot+2),root); 
    Push_Up(ch[root][1]);
    Push_Up(root);
    Update_Rev(Key_value);
}
void Inorder(int r){
    if(!r)
		return;
    Push_Down(r);
    Inorder(ch[r][0]);
    printf("%d ",key[r]);
    Inorder(ch[r][1]);
};
int main(){
	int kase=0;
	while(scanf("%d%d%d%d",&n,&m,&k1,&k2)&&(n||m||k1||k2)){
		Init();
		char op[20];
		printf("Case #%d:\n",++kase);
		while(m--){
			scanf("%s",op);
			if(op[0]=='q'){
				printf("%d\n",key[Get_Min(ch[root][1])]);
			}
			else if(op[0]=='m'){
				int tmp; scanf("%d",&tmp);
				if(tmp==1) move1();
				else move2();
			}
			else if(op[0]=='i'){
				int tmp; scanf("%d",&tmp);
				Insert(2,tmp);
			}
			else if(op[0]=='d'){
				Del(2);
			}
			else if(op[0]=='a'){
				int tmp; scanf("%d",&tmp);
			//	jie(k2);
			//	add[ch[ch[root][1]][0]]+=tmp;
			//	key[ch[ch[root][1]][0]]+=tmp;
				ADD(1,k2,tmp);
			}
			else if(op[0]=='r'){
			//	Reverse(k1);
				jie(k1);
				rev[ch[ch[root][1]][0]]^=1;
			}
		//	Inorder(root); puts("");
		}
	}
}
