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

//1.2Line����
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

//1.4�жϣ��߶��ཻ
bool inter(Lint l1,Line l2){
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

//1.5�жϣ�ֱ�ߺ��߶��ཻ
bool Seg_inter_line(Line l1,Line l2){
	return  sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e))<=0;
}

//1.6�㵽ֱ�߾���
//���ص�result�ǵ㵽ֱ������ĵ�
Point PointToLine(Point P,Line L){
	Point result;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	result.x=L.s.x+(L.e.x-L.s.x)*t;
	result.y=L.s.y+(L.e.y-L.s.y)*t;
	return result;
}

//1.7�㵽�߶ξ���
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

//1.8�������ε����
//��ı�Ŵ�0~n-1
double CalcArea(Point p[],int n){
	double res=0;
	for(int i=0; i<n; i++)
		res+=(p[i]^p[(i+1)%n])/2;
	return fabs(res);
}

//1.9�жϵ����߶���
bool Onseg(Point P,Line L){
	return
    sgn((L.s-P)^(L.e-P))==0&&
	sgn((P.x-L.s.x)*(P.x-L.e.x))<=0&&
	sgn((P.y-L.s.y)*(P.y-L.e.y))<=0;	
}

//1.10�жϵ���͹�������
//���γ�һ��͹�������Ұ���ʱ�����������˳ʱ��������<0��Ϊ>0
//��ı��:0~n-1
//����ֵ�� 
//-1:����͹�������
//0:����͹����α߽���
//1:����͹�������
int inConvexPoly(Point a,Point p[],int n){
	for(int i=0; i<n; i++){
		if(sgn((p[i]-a)^(p[(i+1)%n]-a))<0)
			return -1;
		else if(OnSeg(a,Line(p[i],p[(i+1)%n])))
			return 0;
	}
	return 1;
}

//1.12�ж�͹�����
//�ж�͹�����
//�����߱�
//�������˳ʱ�����Ҳ��������ʱ�����
//��ı��1~n-1
bool isconvex(Point poly[],int n){
	bool s[3];
	memset(s,false,sizeof(s));
	for(int i=0; i<n; i++){
		s[sgn( (poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]) )+1] = true;
		if(s[0] && s[2])
			return false;
	}
	return true;
}




//6. ������Բ������
Point waixin(Point a,Point b,Point c){
	double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1 + b1*b1)/2;
	double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2 + b2*b2)/2;
	double d=a1*b2-a2*b1;
	return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2 -a2*c1)/d);
}

//7. ����Բ�ཻ�����
double Area_of_overlap(Point c1,double r1,Point c2,double r2){
	double d=dist(c1,c2);
	if(r1+r2<d+eps)
		return 0;
	if(d<fabs(r1-r2)+eps){
		double r=min(r1,r2);
		return pi*r*r;
	}
	double x=(d*d+r1*r1-r2*r2)/(2*d);
	double t1=acos(x/r1);
	double t2=acos((d-x)/r2);
	return r1*r1*t1+r2*r2*t2-d*r1*sin(t1);
}
