#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
set<int > s;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		s.clear();
		for(int i=0; i<n; i++){
			int tmp; scanf("%d",&tmp);
			for(int i=0; i<tmp; i++){
				int tmp1; scanf("%d",&tmp1);
				s.insert(tmp1);
			}
		}
		if(s.size()==m)
			printf("YES\n");
		else
			printf("NO\n");
	}	
}
