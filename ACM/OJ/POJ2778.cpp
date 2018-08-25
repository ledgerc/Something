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
const int MOD=100000;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
struct Matrix{
    int mat[110][110],n;
    Matrix(){}
    Matrix(int _n){
        n = _n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j]=0;
    }
    Matrix operator *(const Matrix &b)const{
        Matrix ret=Matrix(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++){
                    int tmp=(long long)mat[i][k]*b.mat[k][j]%MOD;
                    ret.mat[i][j]=(ret.mat[i][j]+tmp)%MOD;
                }
        return ret;
    }
};
Matrix pow_M(Matrix a,int n){
    Matrix ret = Matrix(a.n);
    for(int i = 0; i < ret.n; i++)
        ret.mat[i][i]=1;
    Matrix tmp=a;
    while(n){
        if(n&1)
			ret=ret*tmp;
        tmp=tmp*tmp;
        n>>=1;
    }
    return ret;
}
struct Trie{
	int next[110][4],fail[110];
	bool end[110];
	int root,L;
	int newnode(){
		for(int i=0; i<4; i++)
			next[L][i]=-1;
		end[L++]=false;
		return L-1;
	}
	void init(){
		L=0;
		root=newnode();
	}
	int getch(char ch){
		if(ch=='A')
			return 0;
		else if(ch=='C')
			return 1;
		else if(ch=='G')
			return 2;
		else
			return 3;
	}
	void insert(char buf[]){
		int len=strlen(buf);
		int now=root;
		for(int i=0; i<len; i++){
			if(next[now][getch(buf[i])]==-1)
				next[now][getch(buf[i])]=newnode();
			now=next[now][getch(buf[i])];
		}
		end[now]=true;
	}
	void build(){
		queue<int> Q;
		fail[root]=root;
		for(int i=0; i<4; i++)
			if(next[root][i]==-1)
				next[root][i]=root;
			else{
				fail[next[root][i]]=root;
				Q.push(next[root][i]);
			}
		while(!Q.empty()){
			int now=Q.front();
			Q.pop();
			if(end[fail[now]]==true)
				end[now]=true;
			for(int i=0; i<4; i++){
				if(next[now][i]==-1)
					next[now][i]=next[fail[now]][i];
				else{
					fail[next[now][i]]=next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	Matrix getMatrix(){
        Matrix res = Matrix(L);
        for(int i=0;i<L;i++)
            for(int j=0;j<4;j++)
                if(end[next[i][j]]==false)
                    res.mat[i][next[i][j]]++;
        return res;
    }
};
char buf[20];
Trie ac;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        ac.init();
        for(int i=0;i<n;i++){
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        Matrix a=ac.getMatrix();
        a=pow_M(a,m);
        int ans=0;
        for(int i=0;i<a.n;i++)
            ans=(ans+a.mat[0][i])%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
