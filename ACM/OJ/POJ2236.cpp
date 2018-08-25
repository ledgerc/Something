#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define N 1110
int d;
bool use[N];
struct node{
	int pre;
	int x, y;
}p[N];
int find(int x){
	return x == p[x].pre ? x : find(p[x].pre);
}
void join(const node p1, const node p2){
	int root1, root2;
	root1 = find(p1.pre);
	root2 = find(p2.pre);
	if(root1 != root2)
		if((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) <= d * d)
			p[root2].pre = root1;
}
int main(){
	int num;
	char ope;
	int ok;
	int from, to;
	scanf("%d%d", &num, &d);
	for(int i = 1; i <= num; ++i)
		p[i].pre = i;
	memset(use, false, sizeof(use));
	for(int i = 1; i <= num; ++i)
		scanf("%d%d", &p[i].x, &p[i].y);
	while(scanf("\n%c", &ope) != EOF){
		if(ope == 'O'){
			scanf("%d", &ok);
			use[ok] = true;
			for(int i = 1; i <= num; ++i)
				if(use[i] && i != ok)
					join(p[i], p[ok]);
		}
		else{
			scanf("%d%d", &from, &to);
			if(find(from) == find(to))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}
