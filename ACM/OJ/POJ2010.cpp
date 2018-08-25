#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,c,f;
const int maxn = 1e5+7;
struct Node{
	int value,cost;
	bool operator <(const Node &a)const{
		return a.cost<cost;
	}
};
Node a[maxn];
bool cmp(Node a,Node b){
	return a.value<b.value;
}
priority_queue<Node> Q;
bool can(int x,int mid){
    while(!Q.empty()) Q.pop();
    for(int i = 0;i < c;i++){
        if(i != mid)
            Q.push(a[i]);
    }
    int cnt1 = 0,cnt2 = 0,cnt = 0;
    int sum = f - a[mid].cost;
    while(!Q.empty()){
        Node tem = Q.top();Q.pop();
        if(tem.value == x && sum >= tem.cost){
            sum -= tem.cost;
            cnt++;
        }
        else if(tem.value < x && cnt1 < n/2 && sum >= tem.cost){
            sum -= tem.cost;
            cnt1++;
        }
        else if(tem.value > x && cnt2 < n/2 && sum >= tem.cost){
            sum -= tem.cost;
            cnt2++;
        }
        if(cnt + cnt1 + cnt2 >= n-1){
            return true;
        }
    }
    return false;
}
int main(){
	while(scanf("%d%d%d",&n,&c,&f)!=EOF){
		for(int i=0; i<c; i++){
			cin>>a[i].value>>a[i].cost;
		}
		if(n==1){
			if(a[0].cost<f)
				cout<<a[0].value<<endl;
			else
				cout<<"-1"<<endl;
			continue;
		}
		sort(a,a+c,cmp);
        int l=0,r=c-1;  
        int ans=-1;  
        while(l<=r){  
            int mid=l+(r-l)/2;  
            if(can(a[mid].value,mid)){
                ans = a[mid].value;
                l = mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%d\n",ans);
	}
}
/*
#include<cstdio>  
#include<algorithm>  
#include<vector>  
#include<set>  
#include<map>  
#include<iostream>  
#include<string>  
#include<cstring>  
#include<queue>  
using namespace std;  
typedef long long LL;  
const int maxn = 100000 + 5;  
const int INF = 1000000000;  
  
struct Node{  
    int value,cost;  
    bool operator < (const Node &a) const{  
        return a.cost < cost;  
    }  
}a[maxn];  
  
bool cmp(Node a,Node b){  
    return a.value < b.value;  
}  
priority_queue<Node> Q;  
  
int n,c,f;  
  
bool can(int x,int mid){  
    while(!Q.empty()) Q.pop();  
    for(int i = 0;i < c;i++){  
        if(i != mid)  
            Q.push(a[i]);  
    }  
    int cnt1 = 0,cnt2 = 0,cnt = 0;  
    int sum = f - a[mid].cost;  
    while(!Q.empty()){  
        Node tem = Q.top();Q.pop();  
        if(tem.value == x && sum >= tem.cost){  
            sum -= tem.cost;  
            cnt++;  
        }  
        else if(tem.value < x && cnt1 < n/2 && sum >= tem.cost){  
            sum -= tem.cost;  
            cnt1++;  
        }  
        else if(tem.value > x && cnt2 < n/2 && sum >= tem.cost){  
            sum -= tem.cost;  
            cnt2++;  
        }  
        if(cnt + cnt1 + cnt2 >= n-1){  
            return true;  
        }  
    }  
    return false;  
}  
  
int main(){  
    while(scanf("%d%d%d",&n,&c,&f) != EOF){  
        for(int i = 0;i < c;i++){  
            scanf("%d%d",&a[i].value,&a[i].cost);  
        }  
        if(n == 1){  
            if(a[0].cost <= f)  printf("%d\n",a[0]);  
            else printf("-1\n");  
            continue;  
        }  
        sort(a,a+c,cmp);  
        int l = 0,r = c-1;  
        int ans = -1;  
        while(l <= r){  
            int mid = l+(r-l)/2;  
            if(can(a[mid].value,mid)){  
                ans = a[mid].value;  
                l = mid+1;  
            }  
            else{  
                r = mid-1;  
            }  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
*/
