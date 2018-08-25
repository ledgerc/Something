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
  
typedef pair<double,double> P;//first����x���꣬second����y����  
  
int N;  
P A[maxn];  
  
//���ڰ�����鲢����ıȽϺ���  
bool compare_y(P a,P b)  
{  
    return a.second<b.second;  
}  
  
//�����a�Ѿ���x�����ź�����  
double closest_pair(P *a,int n)  
{  
    if(n<=1){  
        return INF;  
    }  
    int m=n/2;  
    double x=a[m].first;  
    double d=min(closest_pair(a,m),closest_pair(a+m,n-m));  
    inplace_merge(a,a+m,a+n,compare_y);//�鲢�����ź��������  
    //��ʱa�Ѿ�����y�ź���  
  
    vector<P> b;//����ֱ�߾���С��d�Ķ������  
    for(int i=0;i<n;i++){  
        if(fabs(a[i].first-x)>=d) continue;  
  
        //�Ӻ���ǰ���b��y�������С��d�ĵ�  
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
    sort(A,A+N);//����x��������  
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
