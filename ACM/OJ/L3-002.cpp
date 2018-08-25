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
#include<stack>
#include<cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
int treeNum[maxn];
stack<int> s;
int lowbit(int x){
	return x&(-x);
}
int sum(int x){
	int sum=0;
	while(x){
		sum+=treeNum[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int val){
	while(x<maxn){
		treeNum[x]+=val;
		x+=lowbit(x);
	}
}
bool check(int x,int size){
	if(n&2==0)
		return sum(x)>=size/2;
	else
		return sum(x)>=(size+1)/2;
}
int main(){
	scanf("%d",&n);
	memset(treeNum,0,sizeof treeNum);
	char op[20];
	while(n--){
		scanf("%s",op);
		if(op[1]=='o'){
			if(s.empty())
				cout<<"Invalid"<<endl;
			else{
				int tmp=s.top(); s.pop();
				add(tmp,-1);
				cout<<tmp<<endl;
			}
		}
		else if(op[1]=='u'){
			int tmp; scanf("%d",&tmp);
			s.push(tmp);
			add(tmp,1);
		}
		else{
			if(s.empty()){
				cout<<"Invalid"<<endl;
				continue;
			}
			int l=0,r=maxn;
			while(l<r){
				int mid=(l+r)>>1;
				if(check(mid,s.size()))
					r=mid;
				else
					l=mid+1;
			}
			cout<<l<<endl;
		}
	}
	return 0;
}
