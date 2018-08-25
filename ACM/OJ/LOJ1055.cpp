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
typedef pair<int,int> P;
const int mod = 1e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
bool mark[11][11][11][11][11][11];
char m[11][11];
int n;
struct Node{
	P p1,p2,p3;
	int step;
	Node(P _p1,P _p2,P _p3,int _step){
		p1=_p1; p2=_p2; p3=_p3;
		step=_step;
	}
};
void setmark(P p1,P p2,P p3){
	mark[p1.first][p1.second][p2.first][p2.second][p3.first][p3.second]=true;
}
bool inRange(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=n&&m[x][y]!='#';
}
int bfs(P tmp1,P tmp2,P tmp3){
	queue<Node> que;
	que.push(Node(tmp1,tmp2,tmp3,0));
	setmark(tmp1,tmp2,tmp3);
	int ans=-1;
	while(!que.empty()){
		Node now=que.front(); que.pop();
		int x1=now.p1.first,y1=now.p1.second;
		int x2=now.p2.first,y2=now.p2.second;
		int x3=now.p3.first,y3=now.p3.second;
		int step=now.step;
		if(m[x1][y1]=='X'&&m[x2][y2]=='X'&&m[x3][y3]=='X'){
			ans=step;
			break;
		}
		for(int i=0; i<4; i++){
			int nx1=x1+dx[i],ny1=y1+dy[i]; bool flag1=false;
			int nx2=x2+dx[i],ny2=y2+dy[i]; bool flag2=false;
			int nx3=x3+dx[i],ny3=y3+dy[i]; bool flag3=false;
			if(!inRange(nx1,ny1)){
				nx1=x1,ny1=y1;
				flag1=true;
			}
			if(!inRange(nx2,ny2)){
				nx2=x2,ny2=y2;
				flag2=true;
			}
			if(!inRange(nx3,ny3)){
				nx3=x3,ny3=y3;
				flag3=true;
			}
			
			if(flag1&&flag2&&flag3)
				continue;
			else{
				while(1){
					bool flag=0;
					if(!flag1&&flag2&&nx1==nx2&&ny1==ny2){
						nx1=x1,ny1=y1;
						flag1=1; flag=1;
					}
					if(flag1&&!flag2&&nx1==nx2&&ny1==ny2){
						nx2=x2,ny2=y2;
						flag2=1; flag=1;
					}
					if(!flag1&&flag3&&nx1==nx3&&ny1==ny3){
						nx1=x1,ny1=y1;
						flag1=1; flag=1;
					}
					if(flag1&&!flag3&&nx1==nx3&&ny1==ny3){
						nx3=x3,ny3=y3;
						flag3=1; flag=1;
					}
					if(!flag2&&flag3&&nx2==nx3&&ny2==ny3){
						nx2=x2,ny2=y2;
						flag2=1; flag=1;
					}
					if(flag2&&!flag3&&nx2==nx3&&ny2==ny3){
						nx3=x3,ny3=y3;
						flag3=1; flag=1;
					}
					if(!flag)
						break;
				}
				if(mark[nx1][ny1][nx2][ny2][nx3][ny3])
					continue;
				else{
					mark[nx1][ny1][nx2][ny2][nx3][ny3]=true;
					que.push(Node(P(nx1,ny1),P(nx2,ny2),P(nx3,ny3),step+1));
				}
			}
		}
	}
	return ans;
}
int main(){
	int T; cin>>T;
	for(int kase=1; kase<=T; kase++){
		cin>>n;
		for(int i=1; i<=n; i++)
			scanf("%s",m[i]+1);
		P tmp1,tmp2,tmp3;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				if(m[i][j]=='A')
					tmp1=make_pair(i,j);
				if(m[i][j]=='B')
					tmp2=make_pair(i,j);
				if(m[i][j]=='C')
					tmp3=make_pair(i,j);
			}
		memset(mark,false,sizeof mark); 
		int ans=bfs(tmp1,tmp2,tmp3);
		if(ans==-1)
			printf("Case %d: trapped\n",kase);
		else
			printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}
