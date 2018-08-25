#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 1e3+7;
int n,m;
int a[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(a[i][j]==1){
				for(int k=j-1; k>=0; k--){
					if(a[i][k]==0)
						ans++;
					else
						break;
				}
				for(int k=j+1; k<m; k++){
					if(a[i][k]==0)
						ans++;
					else
						break;
				}
				for(int k=i-1; k>=0; k--){
					if(a[k][j]==0)
						ans++;
					else
						break;
				}
				for(int k=i+1; k<n; k++){
					if(a[k][j]==0)
						ans++;
					else
						break;
				}
			}
		}
	cout<<ans<<endl;
	return 0;
}
