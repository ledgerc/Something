//Kosaraju
//O(N+M)
struct Edge{
	int to,next;
}edge1[maxm],edge2[maxm];//edge1是原图G，edge2是逆图GT 
int head1[maxn],head2[maxn]; 
bool mark1[maxn],mark2[maxn];
int tot1,tot2;
int cnt1,cnt2;
int st[maxn];//对原图进行dfs，点的结束时间从小到大排序
int Belong[maxn];//每个点属于哪个连通分量(0~cnt2-1)
int num;//中间变量，用来数某个连通分量中点的个数
int setnum[maxn];//强连通分量中点的个数，编号0~cnt2-1
void addedge(int u,int v){
	edge1[tot1].to=v;edge1[tot1].next=head1[u];head1[u]=tot1++;
	edge2[tot1].to=u;edge2[tot2].next=head2[v];head2[v]=tot2++;
}
void DFS1(int u){//类似拓扑排序的DFS算法 
	mark1[u]=true;
	for(int i=head1[u]; i!=-1; i=edge1[i].next)
		if(!mark1[edge1[i].to])
			DFS1(edge1[i].to);
	st[cnt1++]=u;
}
void DFS2(int u){
	mark2[u]=true;
	num++;
	Belong[u]=cnt2;
	for(int i=head2[u]; i!=-1; i=edge2[i].next)
		if(!mark2[edge2[i].to])
			DFS2(edge2[i].to);
}
void solve(int n){//点的编号从1开始 
	memset(mark1,false,sizeof mark1);
	memset(mark2,false,sizeof mark2);
	cnt1=cnt2=0;
	for(int i=1; i<=n; i++)
		if(!mark1[i])
			DFS1(i);
	for(int i=cnt1-1; i>=0; i--)
		if(!mark2[st[i]]){
			num=0;
			DFS2(st[i]);
			setNum[cnt2++]=num;
		}
}



const int MAXV=250+3;
struct Bitset{//用unsigned数组实现bitset，为了使用__builtin_ctz()
    unsigned v[8];//8个unsigned表示8*32=256位
    void reset(){//清零
    
        for(int i=0;i<8;++i)
            v[i]=0;
    }
    void set(int x){//把某一位设为1
    
        v[x>>5]|=1u<<(x&31);
    }
    void flip(int x){//翻转某一位
        v[x>>5]^=1u<<(x&31);
    }
    bool test(int x){//返回某一位是否为1
        return v[x>>5]>>(x&31)&1;
    }
}vis, G[MAXV], rG[MAXV];//访问标记，原图，反向图
int V, M;
int ord[MAXV];//dfs序
int num;//当前强连通分量的结点数
inline void flipedge(int x, int y){//翻转一条边

    G[x].flip(y);
    rG[y].flip(x);
}
void dfs0(int x){//正向dfs
    vis.flip(x);
    for(int i=0;i<8;++i)
        while(true){
            unsigned tmp=vis.v[i]&G[x].v[i];//得到相连的没有访问过的点的状压
            if(!tmp)
                break;
            dfs0(i<<5|__builtin_ctz(tmp));//下一个相连的没有访问过的点
        }
    ord[++ord[0]]=x;
}

void dfs1(int x){//反向dfs
    vis.flip(x);
    ++num;
    for(int i=0;i<8;++i)
        while(true){
            unsigned tmp=vis.v[i]&rG[x].v[i];
            if(!tmp)
                break;
            dfs1(i<<5|__builtin_ctz(tmp));
        }
}
int kosaraju(){//每次查询的答案
    vis.reset();
    int res=0;
    ord[0]=0;
    for(int i=0;i<V;++i)
        vis.set(i);
    for(int i=0; i<V;++i)
        if(vis.test(i))
            dfs0(i);
    for(int i=0;i<V;++i)
        vis.set(i);
    for(int i=V;i;--i)
        if(vis.test(ord[i])){//找到一个新的强连通分量
            num=0;
            dfs1(ord[i]);
            res+=num*(num-1)/2;
        }
    return res;
}
int main(){
    int T_T; scanf("%d",& T_T);
    while(T_T--){
        scanf("%d%d",&V, &M);
        for(int i=0;i<V;++i){
            G[i].reset(); rG[i].reset();
        }
        for(int i=0;i<V;++i){
            char s[MAXV]; scanf("%s", s);
            for(int j=0;j<V;++j)
                if(s[j]=='1')
                    flipedge(i, j);
        }
        while(M--){
            int n; scanf("%d", &n);
            while(n--){
                int a, b;
                scanf("%d%d", &a, &b);
                flipedge(a-1, b-1);
            }
            printf("%d\n", kosaraju());
        }
    }
    return 0;
}
