//1.1 Point定义 
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
	//叉积
	double operator ^ (const Point &b)const{
		return x*b.y-y*b.x;
	}
	//点积
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
	//绕原点旋转角度B（弧度值），后x,y的变化
	void transXY(double B){
		double tx=x,ty=y;
		x=tx*cos(B)-ty*sin(B);
		y=tx*sin(B)+ty*cos(B);
	}
};

//1.3两点间距离
double dist(Point a,Point b){
	return sqrt((a-b)*(a-b));
} 

/*
* 求凸包，Graham算法
* 点的编号0~n-1
* 返回凸包结果Stack[0~top-1]为凸包的编号
*/
Point list[maxn];
int Stack[maxn],top;
//相对于list[0]的极角排序 
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

//旋转卡壳 求两点间距离平方的最大值
ll rotating_calipers(Point p[],int n){
	ll ans=0;
	Point v;
	int cur=1;
	for(int i=0; i<n; i++){
		v=p[i]-p[(i+1)%n];
		while((v^(p[(cur+1)%n]-p[cur])) < 0)
		 	cur=(cur+1)%n;
		ans=max(ans,max(dist1(p[i],p[cur]),dist1(p[(i+1)%n],p[(cur+1)%n])));
	}
	return ans;
}


int main(){
	
} 
