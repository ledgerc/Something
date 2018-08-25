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
const int maxn = 5e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

#define Key_value ch[ch[root][1]][0]
int pre[maxn],key[maxn],ch[maxn][2],size[maxn],root,tot1;
int sum[maxn],rev[maxn],same[maxn];
int lx[maxn],rx[maxn],mx[maxn];
int s[maxn],tot2;
int a[maxn];
int n,q;
void NewNode(int &r,int father,int k){
	if(tot2)
		r=s[tot2--];
	else
		r=++tot1;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	sum[r]=k;
	key[r]=k;
	lx[r]=rx[r]=mx[r]=k;
	size[r]=1;
	rev[r]=same[r]=0;
}
void Update_Same(int r,int v){
	if(!r)
		return ;
	key[r]=v;
	sum[r]=v*size[r];
	lx[r]=rx[r]=mx[r]=max(v,v*size[r]);
	same[r]=1;
}
void Update_Rev(int r){
	if(!r)
		return;
	swap(ch[r][0],ch[r][1]);
	swap(lx[r],rx[r]);
	rev[r]^=1;
}
void Push_Up(int r){
    int lson=ch[r][0],rson=ch[r][1];
    size[r]=size[lson]+size[rson]+1;
    sum[r]=sum[lson]+sum[rson]+key[r];
    lx[r]=max(lx[lson],sum[lson]+key[r]+max(0,lx[rson]));
    rx[r]=max(rx[rson],sum[rson]+key[r]+max(0,rx[lson]));
    mx[r]=max(0,rx[lson])+key[r]+max(0,lx[rson]);
    mx[r]=max(mx[r],max(mx[lson],mx[rson]));
}
void Push_Down(int r){
	if(same[r]){
		Update_Same(ch[r][0],key[r]);
		Update_Same(ch[r][1],key[r]);
		same[r]=0;
	}
	if(rev[r]){
		Update_Rev(ch[r][0]);
		Update_Rev(ch[r][1]);
		rev[r]=0;
	}
}
void Build(int &x,int l,int r,int father){
	if(l>r)
		return ;
	int mid=(l+r)>>1;
	NewNode(x,father,a[mid]);
	Build(ch[x][0],l,mid-1,x);
	Build(ch[x][1],mid+1,r,x);
	Push_Up(x);
}
void Init(){
	root=tot1=tot2=0;
	ch[root][0]=ch[root][1]=pre[root]=size[root]=same[root]=rev[root]=sum[root]=key[root]=0;
    lx[root]=rx[root]=mx[root]=-inf;
    NewNode(root,0,-1);
    NewNode(ch[root][1],root,-1);
    for(int i=0;i<n;i++)
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
int Get_Kth(int r,int k){
	Push_Down(r);
	int t=size[ch[r][0]]+1;
	if(t==k)
		return r;
	if(t>k)
		return Get_Kth(ch[r][0],k);
	return Get_Kth(ch[r][1],k-t);
}
void Insert(int pos,int tot){
	for(int i=0; i<tot; i++)
		scanf("%d",&a[i]);
	Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Kth(root,pos+2),root);
    Build(Key_value,0,tot-1,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r){
	if(!r) return;
	s[++tot2]=r;
	erase(ch[r][0]);
	erase(ch[r][1]);
}
void Delete(int pos,int tot){
	Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Make_Same(int pos,int tot,int c){
	Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    Update_Same(Key_value,c);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Reverse(int pos,int tot){
	Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int Get_Sum(int pos,int tot){
	Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    return sum[Key_value];
}
int Get_MaxSum(int pos,int tot){
	Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    return mx[Key_value];
}
void Inorder(int r){
	if(!r) return;
	Push_Down(r);
	Inorder(ch[r][0]);
	printf("%d ",key[r]);
	Inorder(ch[r][0]);
}
int main(){
    scanf("%d%d",&n,&q);
    Init();
    char op[20];
    int x,y,z;
    while(q--){
        scanf("%s",op);
        if(op[0]=='I'){
            scanf("%d%d",&x,&y);
            Insert(x,y);
        }
        else if(op[0]=='D'){
        	scanf("%d%d",&x,&y);
            Delete(x,y);
        }
        else if(op[0]=='M'&&op[2]=='K'){
            scanf("%d%d%d",&x,&y,&z);
            Make_Same(x,y,z);
        }
        else if(op[0]=='R'){
            scanf("%d%d",&x,&y);
            Reverse(x,y);
        }
        else if(op[0]=='G'){
            scanf("%d%d",&x,&y);
            printf("%d\n",Get_Sum(x,y));
        }
        else
            printf("%d\n",Get_MaxSum(1,size[root]-2));
    }
    return 0;
}

