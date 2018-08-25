#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<Cstdio>
using namespace std;
const int INF = 3e9+7;
struct chess{
	int x,y;
	char k;
}cc[10];
int main(){
	ios::sync_with_stdio(false);
	int n; cin>>n;
	int kx,ky; cin>>kx>>ky;
	for(int i=1; i<=8; i++)
		cc[i].k='A';
	cc[1].x=0;cc[1].y=INF;
	cc[2].x=INF;cc[2].y=INF;
	cc[3].x=INF;cc[3].y=0;
	cc[4].x=INF;cc[4].y=-INF;
	cc[5].x=0;cc[5].y=-INF;
	cc[6].x=-INF;cc[6].y=-INF;
	cc[7].x=-INF;cc[7].y=0;
	cc[8].x=-INF;cc[8].y=INF;
	for(int i=0; i<n; i++){
		char c; int a,b;
		cin>>c>>a>>b;
		int tmpx=a-kx,tmpy=b-ky;
//		cout<<"debug:"<<tmpx<<" "<<tmpy<<endl;
		if(tmpx==0||tmpy==0){
			if(tmpx==0){
				if(tmpy>0){
					if(tmpy<cc[1].y){
						cc[1].y=tmpy;
						cc[1].k=c;
					}
				}
				else if(tmpy<0){
					if(tmpy>cc[5].y){
						cc[5].y=tmpy;
						cc[5].k=c;
					}
				}
			}
			if(tmpy==0){
				if(tmpx>0){
					if(tmpx<cc[3].x){
						cc[3].x=tmpx;
						cc[3].k=c;
					}
				}
				else if(tmpx<0){
					if(tmpx>cc[7].x){
						cc[7].x=tmpx;
						cc[7].k=c;
					}
				}
			}
		}
		else if(abs(tmpx)==abs(tmpy)){
			if(tmpx>0&&tmpy>0){
				if(tmpx<cc[2].x){
					cc[2].x=tmpx;
					cc[2].k=c;
				}
			}
			else if(tmpx>0&&tmpy<0){
				if(tmpx<cc[4].x){
					cc[4].x=tmpx;
					cc[4].k=c;
				}
			}
			else if(tmpx<0&&tmpy<0){
				if(tmpx>cc[6].x){
					cc[6].x=tmpx;
					cc[6].k=c;
				}
			} 
			else if(tmpx<0&&tmpy>0){
				if(tmpy<cc[8].y){
					cc[8].k=c;
					cc[8].y=tmpy;
				}
			}
		}
	}
	bool flag=false;
	if(cc[1].k=='R'||cc[1].k=='Q')
			flag=true;
	if(cc[2].k=='B'||cc[2].k=='Q')
			flag=true;
	if(cc[3].k=='R'||cc[3].k=='Q')
			flag=true;
	if(cc[4].k=='B'||cc[4].k=='Q')
			flag=true;
	if(cc[5].k=='R'||cc[5].k=='Q')
			flag=true;
	if(cc[6].k=='B'||cc[6].k=='Q')
			flag=true;
	if(cc[7].k=='R'||cc[7].k=='Q')
			flag=true;
	if(cc[8].k=='B'||cc[8].k=='Q')
			flag=true;
	if(flag==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
//	for(int i=1; i<=8; i++)
//		cout<<cc[i].k<<" ";
//	cout<<INF<<endl;
	return 0;
}
