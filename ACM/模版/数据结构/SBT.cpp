struct SBT{
	int left,right;
	int size,key;
	void init(){
		left=right=0;
		size=1;
	}
}tree[maxn];
int tot,root;
void left_rotate(int &x){
	int y=tree[x].right;
	tree[x].right=tree[y].left;
	tree[y].left=x;
	tree[y].size=tree[x].size;
	tree[x].size=tree[tree[x].left].size+tree[tree[x].right].size+1;
	x=y;
}
void right_rotate(int &x){
	int y=tree[x].left;
	tree[x].left=tree[y].right;
	tree[y].right=x;
	tree[y].size=tree[x].size;
	tree[x].size=tree[tree[x].left].size+tree[tree[x].right].size+1;
	x=y;
}
void maintain(int &x,int flag){
	if(flag==0){
		if(tree[tree[tree[x].left].left].size>tree[tree[x].right].size)
			right_rotate(x);
		else if(tree[tree[tree[x].left].right].size>tree[tree[x].right].size)
			left_rotate(tree[x].left),right_rotate(x);
		else
			return;
	}
	else{
		if(tree[tree[tree[x].right].right].size>tree[tree[x].left].size)
			left_rotate(x);
		else if(tree[tree[tree[x].right].left].size>tree[tree[x].left].size)
			right_rotate(tree[x].right),left_rotate(x);
		else
			return;
	}
	maintain(tree[x].left,0);
	maintain(tree[x].right,1);
	maintain(x,0);
	maintain(x,1);
}
void insert(int &x,int key){
	if(x==0){
		x=++tot;
		tree[x].init();
		tree[x].key=key;
	}
	else{
		tree[x].size++;
		if(key<tree[x].key)
			insert(tree[x].left,key);
		else
			insert(tree[x].right,key);
		maintain(x,key>=tree[x].key);
	}
}
//得到前驱，小于 前趋定义为小于x，且最大的数
//返回前驱的节点编号
int get_pre(int &r,int y,int key){
    if(r==0)
		return y;
    if(key>tree[r].key)//加个等号就是小于等于
        return get_pre(tree[r].right,r,key);
    else
		return get_pre(tree[r].left,y,key);
}
//得到后继，大于 后继定义为大于x，且最小的数
//返回后继的节点编号
int get_next(int &r,int y,int key){
    if(r==0)
		return y;
    if(key<tree[r].key)//加个等号就是大于等于
        return get_next(tree[r].left,r,key);
    else
		return get_next(tree[r].right,y,key);
}
//查找是否存在key值为k的元素
//不存在返回0，存在返回节点编号
int find(int t,int k){
    while(t && k!=tree[t].key)
        t=k<tree[t].key?find(tree[t].left,k):find(tree[t].right,k);
    return t;
}
int get_kth(int &x,int k){
	if(k<=tree[tree[x].left].size)
		return get_kth(tree[x].left,k);
	else if(k>tree[tree[x].left].size+1)
		return get_kth(tree[x].right,k-tree[tree[x].left].size-1);
	return tree[x].key;
}
int get_max(int r){
	while(tree[r].right)
		r=tree[r].right;
	return r;
} 
int get_min(int r){
	while(tree[r].left)
		r=tree[r].left;
	return r;
}
//删除值为key的数 
int del(int &x,int key){
	if(!x)
		return 0;
	tree[x].size--;
	if(key==tree[x].key || (key<tree[x].key&&tree[x].left==0)
    || (key>tree[x].key&&tree[x].right==0)){
        if(tree[x].left && tree[x].right){
            int p=del(tree[x].left,key+1);
            tree[x].key=tree[p].key;
            return p;
        }
        else{
            int p=x;
            x=tree[x].left+tree[x].right;
            return p;
        }
    }
    else
		return del(key<tree[x].key?tree[x].left:tree[x].right,key);
}
int deletemin(){
	int temp=root;
	if(tree[temp].left==0){
		root=tree[root].right;
		return tree[temp].key;
	}
	while(tree[tree[temp].left].left){
		tree[temp].size--;
		temp=tree[temp].left;
	}
	tree[temp].size--;
	int ret=tree[tree[temp].left].key;
	tree[temp].left=tree[tree[temp].left].right;
	return ret;
}
//得到前驱，返回的是小于v的key值，不存在v
int Pred(int t,int v){
    if(!t)
		return v;
    if(v<=tree[t].key)
		return Pred(tree[t].left,v);
    else{
        int tmp=Pred(tree[t].right,v);
        return v==tmp?tree[t].key:tmp;
    }
}
//得到后继，返回的是大于v的key值，不存在v
int Succ(int t,int v){
    if(!t)
		return v;
    if(v>=tree[t].key)
		return Succ(tree[t].right,v);
    else{
        int tmp=Succ(tree[t].left,v);
        return v==tmp?tree[t].key:tmp;
    }
}
void inorder(int &x){
	if(x==0)
		return;
	else{
		inorder(tree[x].left);
	//	cout<<tree[x].key<<" ";
		cout<<" "<<tree[x].key<<" "<<tree[x].size<<endl;
		inorder(tree[x].right);
	}
}
int main(){
	char op[20];
	while(true){
		root=tot=0; int tmp;
		cout<<"enter: ";
		scanf("%s",op);
		if(op[0]=='i'){
			scanf("%d",&tmp);
			insert(root,tmp);
			inorder(root);
			cout<<endl;
		}
		else if(op[0]=='p'){
			scanf("%d",&tmp);
			printf("%d\n",get_pre(root,0,tmp));
		}
		else{
			scanf("%d",&tmp);
			printf("%d\n",get_next(root,0,tmp));
		}
	}
}
/* 
int main(){
	char op[10];
	int u,n,Min;
	int temp=0;
	while(scanf("%d%d",&n,&Min)==2){
		tot=root=0;
		temp=0;
		int ans=0;
		while(n--){
			scanf("%s",op);
			if(op[0]=='I'){
				scanf("%d",&u);
				if(u>=Min)
					insert(root,u-temp);
			}
			else if(op[0]=='A'){
				scanf("%d",&u);
				temp+=u;
			}
			else if(op[0]=='S'){
				scanf("%d",&u);
				temp-=u;
				while(root!=0&&tree[get_min(root)].key+temp<Min){
					deletemin();
					ans++;
				}
			}
			else{
				scanf("%d",&u);
				if(root==0||u>tree[root].size)
					printf("-1\n");
				else{
					printf("%d\n",get_kth(root,tree[root].size+1-u)+temp);
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
}
*/ 
