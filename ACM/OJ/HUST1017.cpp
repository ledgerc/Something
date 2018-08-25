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
	//U D R L������¼ĳ����ŵĽڵ���������ҽڵ�ı��
    //Row Col������¼ĳ����ŵĽڵ��ھ����е��кź��к�
	int H[MaxN],S[MaxM];
	//H����ͷ S��������ĳһ����1������
	int ansd,ans[MaxN];
	void init(int _n,int _m){
		n = _n;
		m = _m;
		for(int i = 0;i <= m;i++){//��ʼ����ͷ
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
	void remove(int c){//��ĳһ�н���ɾ�� ͬʱɾ������Ϊ1����
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for(int i = D[c];i != c;i = D[i])
			for(int j = R[i];j != i;j = R[j]){
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c){//���Żָ�״̬
		for(int i = U[c];i != c;i = U[i])
			for(int j = L[i];j != i;j = L[j])
				++S[Col[U[D[j]]=D[U[j]]=j]];
		L[R[c]] = R[L[c]] = c;
	}
	bool Dance(int d){//dΪ�ݹ����
		int Min,c; 
		if(R[0]==0){
			ansd=d;
			return true; 
		}
		c = R[0];
		//һ���Ż� �ҵ����а���1������ �����ڼ��ٵݹ����� 
		for(int i = R[0];i != 0;i = R[i])
			if(S[i] < S[c])
				c = i;
		remove(c);
		//���� 
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
