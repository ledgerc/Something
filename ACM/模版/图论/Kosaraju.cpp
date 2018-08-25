//Kosaraju
//O(N+M)
struct Edge{
	int to,next;
}edge1[maxm],edge2[maxm];//edge1��ԭͼG��edge2����ͼGT 
int head1[maxn],head2[maxn]; 
bool mark1[maxn],mark2[maxn];
int tot1,tot2;
int cnt1,cnt2;
int st[maxn];//��ԭͼ����dfs����Ľ���ʱ���С��������
int Belong[maxn];//ÿ���������ĸ���ͨ����(0~cnt2-1)
int num;//�м������������ĳ����ͨ�����е�ĸ���
int setnum[maxn];//ǿ��ͨ�����е�ĸ��������0~cnt2-1
void addedge(int u,int v){
	edge1[tot1].to=v;edge1[tot1].next=head1[u];head1[u]=tot1++;
	edge2[tot1].to=u;edge2[tot2].next=head2[v];head2[v]=tot2++;
}
void DFS1(int u){//�������������DFS�㷨 
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
void solve(int n){//��ı�Ŵ�1��ʼ 
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
struct Bitset{//��unsigned����ʵ��bitset��Ϊ��ʹ��__builtin_ctz()
    unsigned v[8];//8��unsigned��ʾ8*32=256λ
    void reset(){//����
    
        for(int i=0;i<8;++i)
            v[i]=0;
    }
    void set(int x){//��ĳһλ��Ϊ1
    
        v[x>>5]|=1u<<(x&31);
    }
    void flip(int x){//��תĳһλ
        v[x>>5]^=1u<<(x&31);
    }
    bool test(int x){//����ĳһλ�Ƿ�Ϊ1
        return v[x>>5]>>(x&31)&1;
    }
}vis, G[MAXV], rG[MAXV];//���ʱ�ǣ�ԭͼ������ͼ
int V, M;
int ord[MAXV];//dfs��
int num;//��ǰǿ��ͨ�����Ľ����
inline void flipedge(int x, int y){//��תһ����

    G[x].flip(y);
    rG[y].flip(x);
}
void dfs0(int x){//����dfs
    vis.flip(x);
    for(int i=0;i<8;++i)
        while(true){
            unsigned tmp=vis.v[i]&G[x].v[i];//�õ�������û�з��ʹ��ĵ��״ѹ
            if(!tmp)
                break;
            dfs0(i<<5|__builtin_ctz(tmp));//��һ��������û�з��ʹ��ĵ�
        }
    ord[++ord[0]]=x;
}

void dfs1(int x){//����dfs
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
int kosaraju(){//ÿ�β�ѯ�Ĵ�
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
        if(vis.test(ord[i])){//�ҵ�һ���µ�ǿ��ͨ����
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
