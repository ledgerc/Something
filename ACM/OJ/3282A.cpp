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
const int maxn = 1e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char a[maxn][maxn];
int main(){
	for(int i=0; i<8; i++)
		scanf("%s",a[i]);
	int mina=1000,minb=1000;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(a[i][j]=='W'){
				int k;
				for(k=i-1; k>=0; k--){
					if(a[k][j]!='.')
						break;
				}
				if(k<0&&i<mina)
					mina=i;
			}
			else if(a[i][j]=='B'){
				int k;
				for(k=i+1; k<8; k++){
					if(a[k][j]!='.')
						break;
				}
				if(k>=8&&(7-i)<minb)
					minb=7-i;
			}
		}
	}
	if(mina<=minb)
		cout<<"A"<<endl;
	else
		cout<<"B"<<endl;
	return 0;
}
