
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int tree[20][maxn];//表示每层每个位置的值 
int sorted[maxn];
int toleft[20][maxn];//toleft[p][i]表示第i层从1到i有多少个数分入左边
void build(int l,int r,int dep){
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	int same=mid-l+1;//表示等于中间值而且被分入左边的个数
	for(int i=l; i<=r; i++)
		if(tree[dep][i]<sorted[mid])
			same--;
	int lpos=l,rpos=mid+1;
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])//比中间的数小,分入左边 
			tree[dep+1][lpos++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0){
			tree[dep+1][lpos++]=tree[dep][i];
			same--;
		}
		else//比中间值大分入右边
			tree[dep+1][rpos++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+lpos-l;//从1到i放左边的个数
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}
//查询区间第k大的数，[L,R]是大区间，[l,r]是要查询的小区间
int query(int L,int R,int l,int r,int dep,int k){
	if(l==r)
		return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//[l,r]中位于左边的个数
	if(cnt>=k){
		//L+要查询的区间前被放在左边的个数
		int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		//左端点加上查询区间会被放在左边的个数
		int newr=newl+cnt-1; 
		return query(L,mid,newl,newr,dep+1,k);
	}
	else{
		//r+区间后分入左边的数的个数
		int newr=r+toleft[dep][R]-toleft[dep][r];
		//右端点减去区间分入右边的数的个数
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










int tree[20][maxn];//表示每层每个位置的值 
int sorted[maxn];
int toleft[20][maxn];//toleft[p][i]表示第i层从1到i有多少个数分入左边
ll sum[20][maxn];//sum[i][j] 第i层1-j中数的和
void build(int l,int r,int dep){
	if(l==r){
		sum[dep][l]=tree[dep][l];
		return ;
	}
	int mid=(l+r)>>1;
	int same=mid-l+1;//表示等于中间值而且被分入左边的个数
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])
			same--;
		sum[dep][i]=tree[dep][i];
        if(i>l)
			sum[dep][i]+=sum[dep][i-1];
	} 
	int lpos=l,rpos=mid+1;
	for(int i=l; i<=r; i++){
		if(tree[dep][i]<sorted[mid])//比中间的数小,分入左边 
			tree[dep+1][lpos++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0){
			tree[dep+1][lpos++]=tree[dep][i];
			same--;
		}
		else//比中间值大分入右边
			tree[dep+1][rpos++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+lpos-l;//从1到i放左边的个数
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}
//查询区间第k大的数，[L,R]是大区间，[l,r]是要查询的小区间
ll ans; 
int query(int L,int R,int l,int r,int dep,int k){
	if(l==r)
		return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//[l,r]中位于左边的个数
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
		//L+要查询的区间前被放在左边的个数
		int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		//左端点加上查询区间会被放在左边的个数
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
		//r+区间后分入左边的数的个数
		int newr=r+toleft[dep][R]-toleft[dep][r];
		//右端点减去区间分入右边的数的个数
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
