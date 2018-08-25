/*
Trees可以通过基尔霍夫矩阵求出。那什么是基尔霍夫矩阵呢？假设D(G)为图G的度数矩阵，在这个矩阵中，当i=j时
有d[i][j]为点i的度数，当i≠j时，d[i][j]=0；再假设矩阵A(G)为图G的邻接矩阵，在这个矩阵中，若i点和j点
可达，则有a[i][j]=1，否则a[i][j]为0。那么这个时候就可以令基尔霍夫矩阵为C(G)=D(G)-A(G)。然后通过求基尔霍
夫矩阵的的行列值就可以了。由于要求以1号结点为根节点的生成树的个数，那么计算2~n结点的n-1阶基尔霍夫矩阵
的行列值就行了。Deg[1]表示1号结点的入度。

资料：
求有向图的欧拉回路个数，是BEST定理 
ec(G)=ts(G)?deg(s)!?∏v∈V, v≠s(deg(v)?1)!, ts(G):=以s为根的外向树的个数 
如何计算有向图的外向树个数，这要用到MatrixTree定理 
基尔霍夫矩阵K=度数矩阵D?邻接矩阵A 
无向图的度数矩阵就是每个点自己的度数 
有向图的度数矩阵就是每个点自己的入度 
邻接矩阵是表示u?>v边的个数的矩阵 
重边：按照边数计算，自环：不计入度数 
无向图生成树计数：c=|K的任意1个n?1阶主子式| 
有向图外向树计数：c=|去掉根所在的那阶得到的主子式|
*/

const LL MOD=998244353;
const int MAXV=400+1;
int V;
LL D[MAXV][MAXV];//从i，到j的边的数目
LL in[MAXV],out[MAXV];//每个结点的入度，出度
struct Matrix{
    LL a[MAXV][MAXV];
    Matrix(){ 
        memset(a,0,sizeof(a));
    }
    LL det(int n){//求前n行n列的行列式的值
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                a[i][j]=(a[i][j]%MOD+MOD)%MOD;
        LL ret=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                while(a[j][i]){
                    LL t=a[i][i]/a[j][i];
                    for(int k=i;k<n;++k)
                        a[i][k]=((a[i][k]-a[j][k]*t)%MOD+MOD)%MOD;
                    for(int k=i;k<n;++k)
                        swap(a[i][k],a[j][k]);
                    ret=-ret;
                }
            if(!a[i][i])
                return 0;
            ret=ret*a[i][i]%MOD;
        }
        ret=(ret%MOD+MOD)%MOD;
        return ret;
    }
};
LL get_fac(LL x){//计算阶乘
    LL res=1;
    for(LL i=2;i<=x;++i)
        res=(res*i)%MOD;
    return res;
}
LL exgcd(LL a, LL b, LL &x, LL &y){
    LL d=a;
    if(b){
        d=exgcd(b, a%b, y, x);
        y-=(a/b)*x;
    }
    else{
        x=1; y=0;
    }
    return d;
}
LL inv(LL a){//计算逆元
    LL x, y;
    exgcd(a, MOD, x, y);
    return (MOD+x%MOD)%MOD;
}
void init(){
    for(int i=0;i<=V;++i)
        in[i]=out[i]=0;
}
int main(){
    int cas=1;
    while(~scanf("%d",&V)){
        init();
        Matrix mat;
        for(int i=0;i<V;++i)
            for(int j=0;j<V;++j){
                scanf("%lld", &D[i][j]);
                mat.a[i][j]-=D[i][j];
                mat.a[j][j]+=D[i][j];
                in[j]+=D[i][j];
                out[i]+=D[i][j];
            }
        //如果存在点入度不等于出度，则不存在欧拉回路直接输出0
        bool ok=true;
        for(int i=0;i<V;++i)
            if(in[i]!=out[i]){
                ok=false;
                break;
            }
        if(!ok){
            printf("Case #%d: 0\n", cas++);
            continue;
        }
        //把根节点移到最后，方便去掉它求行列式
        for(int i=0;i<V;++i)
            swap(mat.a[0][i], mat.a[V-1][i]);
        for(int i=0;i<V;++i)
            swap(mat.a[i][0], mat.a[i][V-1]);
        LL ans=mat.det(V-1);
        for(int i=0;i<V;++i)
            ans=(ans*get_fac(in[i]-(i!=0)))%MOD;
        for(int i=0;i<V;++i)
            for(int j=0;j<V;++j)
                ans=(ans*inv(get_fac(D[i][j])))%MOD;
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
