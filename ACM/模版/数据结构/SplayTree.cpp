#define Key_value ch[ch[root][1]][0]
//����㡢���Һ��ӡ���ֵ��������ģ
int pre[maxn],ch[maxn][2],key[maxn],size[maxn];
//�����ĺ�  �����Ƿ񱻷�ת �����Ƿ���Ϊһ����
int sum[maxn],rev[maxn],same[maxn];
//����������������� ������������� ������к����������� 
int lx[maxn],rx[maxn],mx[maxn];
//����㡢�������
int root,tot1;
//�ڴ�ء��ڴ������ 
int s[maxn],tot2;

//�������ӳٱ�� 
int add[maxn];
int a[maxn];
int n,q;

//debug����**********************************
void Treavel(int x){
   	if(x){
       	Treavel(ch[x][0]);
   	    printf("��㣺%2d: ����� %2d �Ҷ��� %2d ����� %2d size = %2d rev = %2d\n",x,ch[x][0],ch[x][1],pre[x],size[x],rev[x]);
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
   	key[r]=k;
   	sum[r]=k;
   	rev[r]=same[r]=0;
   	lx[r]=rx[r]=mx[r]=k;
    size[r]=1;
} 
void Update_Same(int r,int v){
   	if(!r)
		return;
   	key[r]=v;
   	sum[r]=v*size[r];
   	lx[r]=rx[r]=mx[r]=max(v,v*size[r]);
   	same[r]=1;
}
//��ת�ĸ���
void Update_Rev(int r){
   	if(!r)
		return;
   	swap(ch[r][0],ch[r][1]);
   	swap(lx[r],rx[r]);
   	rev[r]^=1;//����Ҫע�⣬һ�������1
}
//���ӵĸ���
void Update_Add(int r,int ADD){
	if(!r)
		return;
	add[r]+=ADD;
	key[r]+=ADD;
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
   	ch[root][0]=ch[root][1]=pre[root]=size[root]=same[root]=rev[root]=sum[root]=key[root]=0;
   	lx[root]=rx[root]=mx[root]=-inf;
   	//ͷβ������һ����λ 
   	NewNode(root,0,-1);
   	NewNode(ch[root][1],root,-1);
   	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
   	Build(Key_value,0,n-1,ch[root][1]);
   	Push_Up(ch[root][1]);
   	Push_Up(root);
}
//0Ϊ���� 1Ϊ���� 
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
//�����r������goal���� 
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
//ɾ�����ڵ� �����
/***************************
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
***************************/
//�ڵ�pos���������tot����
void Insert(int pos,int tot){
    for(int i=0; i<tot; i++)
		scanf("%d",&a[i]);
    Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Kth(root,pos+2),root);
	Build(Key_value,0,tot-1,ch[root][1]);
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
void erase(int r){
    if(!r) return;
    s[++tot2]=r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}
//�ӵ�pos������ʼ����ɾ��tot����
void Delete(int pos,int tot){
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//�ӵ�pos����������ʼ��tot�����޸�Ϊc
void Make_Same(int pos,int tot,int c){
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    Update_Same(Key_value,c);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//���ӵ�pos����������ʼ��tot ��ת
void Reverse(int pos,int tot){
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//���
int Get_Sum(int pos,int tot){
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    return sum[Key_value];
}
//�õ�����
int Get_MaxSum(int pos,int tot){
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    return mx[Key_value];
}
//����SplayTree��ֵΪval���±� 
int find(int r,int val){
	if(!r)
		return 0;
	if(val==key[r])
		return r;
	if(val<key[r])
		return find(val,ch[r][0]);
	return find(val,ch[r][1]);
}

//����Ĳ��� 
void insert(int pos,int val){
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
//ɾ�����һ���㣨��n���������뵽��һ����ǰ�� 
void move1(){
	int x=Del(n+1);
	Insert(0+1,x);
}
void move2(){
	int x=Del(1+1);
	Insert(n+1,x);
}

void Inorder(int r){
    if(!r) return;
    Push_Down(r);
    Inorder(ch[r][0]);
    printf("%d ",key[r]);
    Inorder(ch[r][1]);
};

int main(){
    while(scanf("%d%d",&n,&q)==2){
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
    }
    return 0;
}
