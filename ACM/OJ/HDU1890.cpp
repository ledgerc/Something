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
//����㡢���Һ��ӡ���ֵ��������ģ
int pre[maxn],ch[maxn][2],key[maxn],size[maxn];
int rev[maxn];
//����㡢�������
int root,tot1;
//�ڴ�ء��ڴ������ 
int s[maxn],tot2;

int n,q;

void NewNode(int &r,int father,int k){
    r=k;
    pre[r]=father;
    ch[r][0]=ch[r][1]=0;
    key[r]=k;
    rev[r]=0;
    size[r]=1;
}
//��ת�ĸ���
void Update_Rev(int r){
    if(!r)
		return;
    swap(ch[r][0],ch[r][1]);
    rev[r]^=1;//����Ҫע�⣬һ�������1
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
    NewNode(x,father,mid);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
void Init(){
    root=tot1=tot2=0;
    ch[root][0]=ch[root][1]=pre[root]=size[root]=rev[root]=0;
    Build(root,1,n,0);
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
//ɾ�����ڵ� 
void Remove(){
    if(ch[root][0]==0){//û������
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
        Push_Up(root);//Ҫ����
    }
}
struct Node{
	int id,num;
}a[maxn];
bool cmp(Node a,Node b){
	if(a.num!=b.num)
		return a.num<b.num;
	return a.id<b.id;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		if(!n)
			break;
		Init();
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i].num);
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<n; i++){
			Splay(a[i].id,0);
			Update_Rev(ch[root][0]);
			printf("%d ",i+size[ch[root][0]]);
			Remove(); 
		}
		printf("%d\n",n);
	}
	return 0;
}
