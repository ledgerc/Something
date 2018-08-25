#include <algorithm>  
#include <cctype>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <iostream>  
#include <map>  
#include <queue>  
#include <string>  
#include <set>  
#include <vector>  
#include<cmath>  
#include<bitset>  
#include<sstream>  
using namespace std;  
#define INF 0x7fffffff  
#define maxn 10005  
  
typedef pair<double,double> P;//first保存x坐标，second保存y坐标  
  
int N;  
P A[maxn];  
  
//用于按坐标归并排序的比较函数  
bool compare_y(P a,P b)  
{  
    return a.second<b.second;  
}  
  
//传入的a已经按x坐标排好序了  
double closest_pair(P *a,int n)  
{  
    if(n<=1){  
        return INF;  
    }  
    int m=n/2;  
    double x=a[m].first;  
    double d=min(closest_pair(a,m),closest_pair(a+m,n-m));  
    inplace_merge(a,a+m,a+n,compare_y);//归并两个排好序的数列  
    //此时a已经按照y排好序  
  
    vector<P> b;//将到直线距离小于d的顶点加入  
    for(int i=0;i<n;i++){  
        if(fabs(a[i].first-x)>=d) continue;  
  
        //从后往前检查b中y坐标相差小于d的点  
        for(int j=0;j<b.size();j++){  
            double dx=a[i].first-b[b.size()-j-1].first;  
            double dy=a[i].second-b[b.size()-j-1].second;  
            if(dy>=d) break;  
            d=min(d,sqrt(dx*dx+dy*dy));  
        }  
        b.push_back(a[i]);  
    }  
    return d;  
}  
  
void solve()  
{  
    sort(A,A+N);//按照x坐标排序  
    double d=closest_pair(A,N);  
    if(d>=10000) printf("INFINITY\n");  
    else{  
        printf("%.4f\n",d);  
    }  
}  
int main()  
{  
  
    while(cin>>N&&N){  
        for(int i=0;i<N;i++){  
            cin>>A[i].first>>A[i].second;  
        }  
        solve();  
    }  
    return 0;  
}  
