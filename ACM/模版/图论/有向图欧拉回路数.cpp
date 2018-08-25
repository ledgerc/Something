/*
Trees����ͨ��������������������ʲô�ǻ�����������أ�����D(G)ΪͼG�Ķ�����������������У���i=jʱ
��d[i][j]Ϊ��i�Ķ�������i��jʱ��d[i][j]=0���ټ������A(G)ΪͼG���ڽӾ�������������У���i���j��
�ɴ����a[i][j]=1������a[i][j]Ϊ0����ô���ʱ��Ϳ���������������ΪC(G)=D(G)-A(G)��Ȼ��ͨ���������
�����ĵ�����ֵ�Ϳ����ˡ�����Ҫ����1�Ž��Ϊ���ڵ���������ĸ�������ô����2~n����n-1�׻����������
������ֵ�����ˡ�Deg[1]��ʾ1�Ž�����ȡ�

���ϣ�
������ͼ��ŷ����·��������BEST���� 
ec(G)=ts(G)?deg(s)!?��v��V, v��s(deg(v)?1)!, ts(G):=��sΪ�����������ĸ��� 
��μ�������ͼ����������������Ҫ�õ�MatrixTree���� 
�����������K=��������D?�ڽӾ���A 
����ͼ�Ķ����������ÿ�����Լ��Ķ��� 
����ͼ�Ķ����������ÿ�����Լ������ 
�ڽӾ����Ǳ�ʾu?>v�ߵĸ����ľ��� 
�رߣ����ձ������㣬�Ի������������ 
����ͼ������������c=|K������1��n?1������ʽ| 
����ͼ������������c=|ȥ�������ڵ��ǽ׵õ�������ʽ|
*/

const LL MOD=998244353;
const int MAXV=400+1;
int V;
LL D[MAXV][MAXV];//��i����j�ıߵ���Ŀ
LL in[MAXV],out[MAXV];//ÿ��������ȣ�����
struct Matrix{
    LL a[MAXV][MAXV];
    Matrix(){ 
        memset(a,0,sizeof(a));
    }
    LL det(int n){//��ǰn��n�е�����ʽ��ֵ
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
LL get_fac(LL x){//����׳�
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
LL inv(LL a){//������Ԫ
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
        //������ڵ���Ȳ����ڳ��ȣ��򲻴���ŷ����·ֱ�����0
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
        //�Ѹ��ڵ��Ƶ���󣬷���ȥ����������ʽ
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
