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

struct cmp
{
    bool operator()(int x,int y)
    {
        return x>y;
    }
};
priority_queue<int,vector<int>,cmp>q;
priority_queue<int>q2;
int main(){
	int T;
	int L,n;
	int A,B;
	cin>>T;
	for(int kase=1; kase<=T; kase++){
		cin>>L>>n;
		while(!q.empty())
			q.pop();
		while(!q2.empty())
			q2.pop();
		int x=0,ans=0,t=1;
		while(n--){
			cin>>A;
			if(A==0){
				cin>>B;
				if(B>=x)
					q.push(B);
				else
					q2.push(B);
			}
			else{
				if(!q.empty()&&!q2.empty()){
					int tmp1=q.top();
					int tmp2=q2.top();
					if(tmp1-x<x-tmp2){
						t=1;
						ans+=q.top()-x;
						x=q.top();
						q.pop();
					}
					else if(tmp1-x>x-tmp2){
						t=-1;
						ans+=x-q2.top();
						x=q2.top();
						q2.pop();
					}
					else if(t==1){
						ans+=q.top()-x;
						x=q.top();
						q.pop();
					}
					else{
						ans+=x-q2.top();
						x=q2.top();
						q2.pop();
					}
				}
				else if(!q.empty()){
					t=1;
					ans+=q.top()-x;
					x=q.top();
					q.pop();
				}
				else if(!q2.empty()){
					t=-1;
					ans+=x-q2.top();
					x=q2.top();
					q2.pop();
				}
			}
		}
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}
