#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
#define bug() cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;

//1.1 Point���� 
const double pi = acos(-1.0);
const double eps = 1e-8;
int sgn(double x){
	if(fabs(x)<eps)
		return 0;
	if(x<0)
		return -1;
	else
		return 1;
}
struct Point{
	double x,y;
	Point(){};
	Point(double _x,double _y){
		x=_x;y=_y;
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	//���
	double operator ^ (const Point &b)const{
		return x*b.y-y*b.x;
	}
	//���
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
	//��ԭ����ת�Ƕ�B������ֵ������x,y�ı仯
	void transXY(double B){
		double tx=x,ty=y;
		x=tx*cos(B)-ty*sin(B);
		y=tx*sin(B)+ty*cos(B);
	}
};
struct Line{
	Point s,e;
	Line(){};
	Line(Point _s,Point _e){
		s=_s;e=_e;
	};
	//��ֱ���ཻ�󽻵�
	//��һ��ֵΪ0��ʾֱ���غϣ�Ϊ1��ʾƽ�У�Ϊ0��ʾ�ཻ,Ϊ2���ཻ
	//ֻ�е�һ��ֵΪ2ʱ�������������
	pair<int,Point> operator & (const Line &b)const{
		Point res=s;
		if(sgn((s-e)^(b.s-b.e))==0){
			if(sgn((s-b.e)^(b.s-b.e))==0)
				return make_pair(0,res);//�غ� 
			else
				return make_pair(1,res);//ƽ�� 
		}
		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x+=(e.x-s.x)*t;
		res.y+=(e.y-s.y)*t;
		return make_pair(2,res); 
	}
};
//1.3��������
double dist(Point a,Point b){
	return sqrt((a-b)*(a-b));
}
//���ص㵽�߶�����ĵ�
Point NearestPointToLineSeg(Point P,Line L){
	Point result;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	if(t>=0&&t<=1){
		result.x=L.s.x+(L.e.x-L.s.x)*t;
		result.y=L.s.y+(L.e.y-L.s.y)*t; 
	}
	else{
		if(dist(P,L.s)<dist(P,L.e))
			result=L.s;
		else
			result=L.e;
	}
	return result;
}
/*
* ��͹����Graham�㷨
* ��ı��0~n-1
* ����͹�����Stack[0~top-1]Ϊ͹���ı��
*/
Point list[maxn];
int Stack[maxn],top;
//�����list[0]�ļ������� 
bool cmp(Point a,Point b){
	double tmp=(a-list[0])^(b-list[0]);
	if(sgn(tmp)>0)
		return true;
	else if(sgn(tmp)==0&&sgn(dist(a,list[0])-dist(b,list[0]))<=0)
		return true;
	else
		return false;
}
void Graham(int n){
	Point p0;
	int k=0;
	p0=list[0];
	for(int i=1; i<n; i++){
		if( (p0.y>list[i].y) || (p0.y==list[i].y&&p0.x>list[i].x) ){
			p0=list[i];
			k=i;
		}
	}
	swap(list[k],list[0]);
	sort(list+1,list+n,cmp);
	if(n==1){
		top=1; Stack[0]=0;
		return;
	}
	if(n==2){
		top=2; Stack[0]=0; Stack[1]=1;
		return;
	}
	Stack[0]=0; Stack[1]=1;
	top=2;
	for(int i=2; i<n; i++){
		while( top>1 && sgn((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]])) <= 0 )
			top--;
		Stack[top++]=i;
	}
}
//��p0���߶�p1p2�ľ���
double pointtoseg(Point p0,Point p1,Point p2){
	return dist(p0,NearestPointToLineSeg(p0,Line(p1,p2)));
}
//ƽ���߶�p0p1��p2p3�ľ���
double dispallseg(Point p0,Point p1,Point p2,Point p3){
	double ans1 = min(pointtoseg(p0,p2,p3),pointtoseg(p1,p2,p3));
	double ans2 = min(pointtoseg(p2,p0,p1),pointtoseg(p3,p0,p1));
	return min(ans1,ans2);
}
//�õ�����a1a2��b1b2��λ�ù�ϵ
double Get_angle(Point a1,Point a2,Point b1,Point b2){
Point t = b1 - ( b2 - a1 ); 
	return (a2-a1)^(b1-b2);
}
double rotating_calipers(Point p[],int np,Point q[],int nq)
{
    int sp = 0, sq = 0;
    for(int i = 0;i < np;i++)
        if(sgn(p[i].y - p[sp].y) < 0)
            sp = i;
    for(int i = 0;i < nq;i++)
        if(sgn(q[i].y - q[sq].y) > 0)
            sq = i;
    double tmp;
    double ans = 1e99;
    for(int i = 0;i < np;i++)
    {
        while(sgn(tmp = Get_angle(p[sp],p[(sp+1)%np],q[sq],q[(sq+1)%nq])) < 0 )
            sq = (sq + 1)%nq;
        if(sgn(tmp) == 0)
            ans = min(ans,dispallseg(p[sp],p[(sp+1)%np],q[sq],q[(sq+1)%nq]));
        else ans = min(ans,pointtoseg(q[sq],p[sp],p[(sp+1)%np]));
        sp = (sp+1)%np;
    }
    return ans;
}
double solve(Point p[],int n,Point q[],int m){
    return min(rotating_calipers(p,n,q,m),rotating_calipers(q,m,p,n));
}
Point p[maxn],q[maxn];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        if(n == 0 && m == 0)break;
        for(int i = 0;i < n;i++)
        	scanf("%lf%lf",&list[i].x,&list[i].y);
        Graham(n);
        n = top;
        for(int i = 0;i < n;i++)
            p[i] = list[Stack[i]];
        for(int i = 0;i < m;i++)
        	scanf("%lf%lf",&list[i].x,&list[i].y);
        Graham(m);
        m = top;
        for(int i = 0;i < m;i++)
            q[i] = list[Stack[i]];
        printf("%.5lf\n",solve(p,n,q,m));
    }
    return 0;
}
