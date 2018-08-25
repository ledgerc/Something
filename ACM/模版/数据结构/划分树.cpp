
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int tree[20][maxn];//��ʾÿ��ÿ��λ�õ�ֵ 
int sorted[maxn];
int toleft[20][maxn];//toleft[p][i]��ʾ��i���1��i�ж��ٸ����������
void build(int l,int r,int dep){
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	int same=mid-l+1;//��ʾ�����м�ֵ���ұ�������ߵĸ���
	for(int i=l; i<=r; i++)
		if(tree[dep][i]<sorted[mid])
			same--;
	int lpos=l,rpos=mid+1;
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])//���м����С,������� 
			tree[dep+1][lpos++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0){
			tree[dep+1][lpos++]=tree[dep][i];
			same--;
		}
		else//���м�ֵ������ұ�
			tree[dep+1][rpos++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+lpos-l;//��1��i����ߵĸ���
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}
//��ѯ�����k�������[L,R]�Ǵ����䣬[l,r]��Ҫ��ѯ��С����
int query(int L,int R,int l,int r,int dep,int k){
	if(l==r)
		return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//[l,r]��λ����ߵĸ���
	if(cnt>=k){
		//L+Ҫ��ѯ������ǰ��������ߵĸ���
		int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		//��˵���ϲ�ѯ����ᱻ������ߵĸ���
		int newr=newl+cnt-1; 
		return query(L,mid,newl,newr,dep+1,k);
	}
	else{
		//r+����������ߵ����ĸ���
		int newr=r+toleft[dep][R]-toleft[dep][r];
		//�Ҷ˵��ȥ��������ұߵ����ĸ���
		int newl=newr-(r-l-cnt);
		return query(mid+1,R,newl,newr,dep+1,k-cnt);
	}
}
int main(){
	int n,m,T; cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		memset(tree,0,sizeof tree);
		for(int i=1; i<=n; i++){
			scanf("%d",&tree[0][i]);
			sorted[i]=tree[0][i];
		}
		sort(sorted+1,sorted+n+1);
		build(1,n,0);
		int s,t,k;
		while(m--){
			scanf("%d%d%d",&s,&t,&k);
			printf("%d\n",query(1,n,s,t,0,k));
		}
	}
	return 0;
}










int tree[20][maxn];//��ʾÿ��ÿ��λ�õ�ֵ 
int sorted[maxn];
int toleft[20][maxn];//toleft[p][i]��ʾ��i���1��i�ж��ٸ����������
ll sum[20][maxn];//sum[i][j] ��i��1-j�����ĺ�
void build(int l,int r,int dep){
	if(l==r){
		sum[dep][l]=tree[dep][l];
		return ;
	}
	int mid=(l+r)>>1;
	int same=mid-l+1;//��ʾ�����м�ֵ���ұ�������ߵĸ���
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])
			same--;
		sum[dep][i]=tree[dep][i];
        if(i>l)
			sum[dep][i]+=sum[dep][i-1];
	} 
	int lpos=l,rpos=mid+1;
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])//���м����С,������� 
			tree[dep+1][lpos++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0){
			tree[dep+1][lpos++]=tree[dep][i];
			same--;
		}
		else//���м�ֵ������ұ�
			tree[dep+1][rpos++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+lpos-l;//��1��i����ߵĸ���
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}
//��ѯ�����k�������[L,R]�Ǵ����䣬[l,r]��Ҫ��ѯ��С����
ll ans; 
int query(int L,int R,int l,int r,int dep,int k){
	if(l==r)
		return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//[l,r]��λ����ߵĸ���
	int ss=toleft[dep][l-1]-toleft[dep][L-1];
    int ee=l-L-ss;
    int s=toleft[dep][r]-toleft[dep][l-1];
    int e=r-l+1-s;
	if(cnt>=k){
		if(e>0){
            if(ee>0)
				ans+=sum[dep+1][mid+e+ee]-sum[dep+1][mid+ee];
            else
				ans+=sum[dep+1][mid+e];
        }
		//L+Ҫ��ѯ������ǰ��������ߵĸ���
		int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		//��˵���ϲ�ѯ����ᱻ������ߵĸ���
		int newr=newl+cnt-1; 
		return query(L,mid,newl,newr,dep+1,k);
	}
	else{
		if(s>0){
            if(ss>0)
				ans-=sum[dep+1][L+ss+s-1]-sum[dep+1][L+ss-1];
            else
				ans-=sum[dep+1][L+s-1];
        }
		//r+����������ߵ����ĸ���
		int newr=r+toleft[dep][R]-toleft[dep][r];
		//�Ҷ˵��ȥ��������ұߵ����ĸ���
		int newl=newr-(r-l-cnt);
		return query(mid+1,R,newl,newr,dep+1,k-cnt);
	}
}
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    int l,r;
    int iCase=0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+1+n);
        build(1,n,0);
        printf("Case #%d:\n",iCase);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&l,&r);
            l++;
            r++;
            ans=0;
            int tt=query(1,n,l,r,0,(r-l)/2+1);
            if((r-l+1)%2==0)
            {
                ans-=tt;
            }
            printf("%I64d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
