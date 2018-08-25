#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define M_PI 3.1415926
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+7;
const int ST_SIZE = (1<<15)-1;
//input 
int  N,C;
int L[maxn];
int S[maxn],A[maxn];
//data to maintain Segment Tree 
double vx[ST_SIZE],vy[ST_SIZE];//各节点的向量 
double ang[ST_SIZE];//各节点的角度 
//为了查询角度变化而保存当前角度的数组
double prv[maxn];

//初始化
//节点编号：k. 当前节点对应的[l,r)区间。 
void init(int k,int l,int r){
	ang[k]=vx[k]=0.0;
	
	if(r-l==1){
		//叶子节点 
		vy[k]=L[1]; 
	}
	else{
		//非叶子节点
		int chl=k*2+1,chr=k*2+2;
		init(chl,l,(l+r)/2);
		init(chr,(l+r)/2,r);
		vy[k]=vy[chl]+vy[chr]; 
	}
}

//把s和s+1的角度变为a
//节点编号：v. 当前节点对应的[l,r)区间
void change(int s,double a,int v,int l,int r){
	if(s<=l)
		return;
	else if(s<r){
		int chl=v*2+1,chr=v*2+2;
		int m=(l+r)/2;
		change(s,a,chl,l,m);
		change(s,a,chr,m,r);
		if(s<=m)
			ang[v]+=a;
		
		double s=sin(ang[v]),c=cos(ang[v]);
		vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v]=vy[chl]+(s*vx[chr]-c*vy[chr]);
	}
}

void solve(){
	//初始化 
	init(0,0,N);
	for(int i=1; i<N; i++)
		prv[i]=M_PI;
		
	//处理操作
	for(int i=0; i<C; i++){
		int s=S[i];
		double a=A[i]/360.0*2*M_PI;//把角度换算为弧度
		
		change(s,a-prv[s],0,0,N);
		prv[s]=a;
		
		printf("%.2f %.2f\n",vx[0],vy[0]); 
	} 
}

int main(){
	while(scanf("%d %d",&N,&C)&&N+C>0){
		
		for(int i=0; i<N; i++)
			scanf("%d",&L[i]);
		for(int i=0; i<C; i++)
			scanf("%d %d",&S[i],&A[i]);
		
		solve();
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXD 10010
const double PI = acos(-1.0);
int N, M, a[MAXD], A[MAXD], degree[MAXD], rd[4 * MAXD];
struct point
{
    double x, y;
}dp[4 * MAXD];
double getrad(int x)
{
    return x * PI / 180;
}
void build(int cur, int x, int y)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    rd[cur] = 0;
    dp[cur].x = 0, dp[cur].y = A[y] - A[x - 1];
    if(x == y)
        return ;
    build(ls, x, mid);
    build(rs, mid + 1, y);
}
void init()
{
    int i;
    A[0] = 0;
    for(i = 1; i <= N; i ++)
    {
        scanf("%d", &a[i]);
        A[i] = A[i - 1] + a[i];
        degree[i] = 0;
    }
    build(1, 1, N);
}
void update(int cur)
{
    int ls = cur << 1, rs = (cur << 1) | 1;
    dp[cur].x = dp[ls].x + dp[rs].x, dp[cur].y = dp[ls].y + dp[rs].y;
}
void Rotate(double &dx, double &dy, double rad)
{
    double x = dx, y = dy;
    dx = x * cos(rad) - y * sin(rad);
    dy = x * sin(rad) + y * cos(rad);
}
void pushdown(int cur)
{
    int ls = cur << 1, rs = (cur << 1) | 1;
    if(rd[cur])
    {
        double rad = getrad(rd[cur]);
        rd[ls] += rd[cur], rd[rs] += rd[cur];
        Rotate(dp[ls].x, dp[ls].y, rad);
        Rotate(dp[rs].x, dp[rs].y, rad);
        rd[cur] = 0;
    }
}
void refresh(int cur, int x, int y, int k, int delta)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    if(x == y)
    {
        double rad = getrad(delta);
        Rotate(dp[cur].x, dp[cur].y, rad);
        return ;
    }
    pushdown(cur);
    if(mid + 1 < k)
        refresh(rs, mid + 1, y, k, delta);
    else
    {
        double rad = getrad(delta);
        if(k <= mid)
            refresh(ls, x, mid, k, delta);
        Rotate(dp[rs].x, dp[rs].y, rad);
        rd[rs] += delta;
    }
    update(cur);
}
void solve()
{
    int i, j, k, d, delta;
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d", &k, &d);
        ++ k, d = d - 180;
        delta = d - degree[k];
        degree[k] = d;
        refresh(1, 1, N, k, delta);
        printf("%.2f %.2f\n", dp[1].x, dp[1].y);
    }
}
int main()
{
    int t = 0;
    while(scanf("%d%d", &N, &M) == 2)
    {
        init();
        if(t ++)
            printf("\n");
        solve();
    }
    return 0;
}
