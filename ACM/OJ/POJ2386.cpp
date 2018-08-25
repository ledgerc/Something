#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
const int maxn = 1e3 + 7;
const int mod =  1e9 + 7;
using namespace std;

int main()
{
	int N,M;cin>>N>>M;
	char field[maxn][maxn];//map
	for(int i = 0; i<N; i++){
			for(int j=0; j<M; j++){
			cin>>field[i][j];
		}
	}
	
	//current position
	void dfs(int x, int y){
		field[x][y]='.';//represent current position to '.'
	
	
		for(int dx=-1; dx<=1; dx++){
			for(int dy=-1; dy<=1; dy++){
				int nx = x + dx, ny = y + dy ;//move
				if(0 <= nx && nx <= N && 0 <= ny && ny <= M && field[nx][ny] == 'W')
					dfc(nx,ny);
			}
		}
		return ;
	}
	
	void solve(){
		int res = 0;
		for(int i = 0; i<N; i++){
			for(int j=0; j<M; j++){
				if(field[i][j]=='W')
					dfs(i,j);
					res++;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
