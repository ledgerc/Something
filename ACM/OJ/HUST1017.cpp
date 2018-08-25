#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int MaxN = 1010; 
const int MaxM = 1010;
const int maxnode = 100010;
char g[MaxN];
struct DLX{
	int n,m,size;
	int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
	//U D R L用来记录某个标号的节点的上下左右节点的标号
    //Row Col用来记录某个标号的节点在矩阵中的行号和列号
	int H[MaxN],S[MaxM];
	//H是行头 S用来保存某一列中1的数量
	int ansd,ans[MaxN];
	void init(int _n,int _m){
		n = _n;
		m = _m;
		for(int i = 0;i <= m;i++){//初始化列头
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i-1;
			R[i] = i+1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for(int i = 1;i <= n;i++)
			H[i] = -1;
	}
	void Link(int r,int c){
		++S[Col[++size]=c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if(H[r] < 0)
			H[r] = L[size] = R[size] = size;
		else{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c){//对某一列进行删除 同时删除列中为1的行
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for(int i = D[c];i != c;i = D[i])
			for(int j = R[i];j != i;j = R[j]){
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c){//反着恢复状态
		for(int i = U[c];i != c;i = U[i])
			for(int j = L[i];j != i;j = L[j])
				++S[Col[U[D[j]]=D[U[j]]=j]];
		L[R[c]] = R[L[c]] = c;
	}
	bool Dance(int d){//d为递归深度
		int Min,c; 
		if(R[0]==0){
			ansd=d;
			return true; 
		}
		c = R[0];
		//一个优化 找到列中包含1最多的列 有助于减少递归的深度 
		for(int i = R[0];i != 0;i = R[i])
			if(S[i] < S[c])
				c = i;
		remove(c);
		//搜索 
		for(int i = D[c];i != c;i = D[i]){
			ans[d] = Row[i];
			for(int j = R[i];j != i;j = R[j])
				remove(Col[j]);
			if(Dance(d+1))
				return true;
			for(int j = L[i];j != i;j = L[j])
				resume(Col[j]);
		}
		resume(c);
		return false;
	}
};
DLX dlx;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		dlx.init(n,m);
		for(int i=1; i<=n; i++){
			int num,j;
			scanf("%d",&num);
			while(num--){
				scanf("%d",&j);
				dlx.Link(i,j);
			}
		}
		if(!dlx.Dance(0))
			printf("NO\n");
		else{
			printf("%d",dlx.ansd);
			for(int i=0; i<dlx.ansd; i++)
				printf(" %d",dlx.ans[i]);
			printf("\n");
		}
	}
	return 0;
}
