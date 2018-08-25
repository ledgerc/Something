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
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 3e2+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n;
char s[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	if(n%4!=0){
		cout<<"==="<<endl;
		return 0;
	}
	else{
		int a=0,c=0,g=0,t=0;
		for(int i=0; i<n; i++){
			if(s[i]=='A') a++;
			else if(s[i]=='C') c++;
			else if(s[i]=='G') g++;
			else if(s[i]=='T') t++;
		}
		if(a>n/4||c>n/4||g>n/4||t>n/4){
			cout<<"==="<<endl;
			return 0;
		}
		n/=4;
		a=n-a,c=n-c,g=n-g,t=n-t;
		n*=4;
		for(int i=0; i<n; i++){
			if(s[i]!='?')
				cout<<s[i];
			else{
				if(a>0){
					cout<<"A";
					a--;
				}
				else if(c>0){
					cout<<"C";
					c--;
				}
				else if(g>0){
					cout<<"G";
					g--;
				}
				else if(t>0){
					cout<<"T";
					t--;
				}
			}
		}
	}
	return 0;
}
