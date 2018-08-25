int tot,root[55],c[maxn],lson[maxn],rson[maxn];
int op,cnt;
void update(int &t,int y,int x,int l,int r){
	if(!t){
		t=++tot; c[t]=x;
	}
	c[t]=min(c[t],x);
	if(l==r) return;
	int mid = l+r>>1;
	if(y<=mid)
		update(lson[t],y,x,l,mid);
	else
		update(rson[t],y,x,mid+1,r);
}
void query(int t,int L,int R,int x,int l,int r){
	if(cnt||!t) return;
	if(L<=l&&r<=R){
		if(c[t]<=x)
			cnt=1;
		return ;
	}
	int mid=l+r>>1;
	if(L<=mid) query(lson[t],L,R,x,l,mid);
	if(mid<R) query(rson[t],L,R,x,mid+1,r);
}
void init(){
	tot=0;
	memset(root,0,sizeof root);
	memset(lson,0,sizeof lson);
	memset(rson,0,sizeof rson);
}
int main(){
	while(scanf("%d",&op)!=EOF){
		if(op==0)
			init();
		else if(op==1){
			int x,y,color; scanf("%d%d%d",&x,&y,&color);
			update(root[color],y,x,1,1e6);
		}
		else if(op==2){
			int x,y1,y2; scanf("%d%d%d",&x,&y1,&y2);
			int ans=0;
			for(int i=0; i<=50; i++){
				cnt=0;
				query(root[i],y1,y2,x,1,1e6);
				ans+=cnt;
			}
			printf("%d\n",ans);
		}
		else
			return 0; 
	}
	return 0;
}
