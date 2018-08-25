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
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

//一类开关问题，对2取模的01方程组
 
//有equ个方程，var个变元。增广矩阵行数为equ,列数为var+1,分别为0到var
int equ,var;
int a[maxn][maxn],x[maxn];//增广矩阵 解集 
int free_num,free_x[maxn];//自由变元的个数 用来存储自由变元（多解枚举自由变元可以使用）

//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss(){
	int max_r,col,k;
	free_num=0;
	for(k=0,col=0; k<equ&&col<var; k++,col++){
		max_r=k;
		for(int i=k+1; i<equ; i++)
			if(abs(a[i][col])>abs(a[max_r][col]))
				max_r=i;
		if(a[max_r][col]==0){
			k--;
			free_x[free_num++]=col;//这个是自由变元 
			continue;
		}
		if(max_r!=k){
			for(int j=col; j<var+1; j++)
				swap(a[k][j],a[max_r][j]);
		}
		for(int i=k+1; i<equ; i++)
			if(a[i][col]!=0){
				for(int j=col; j<var+1; j++)
					a[i][j]^=a[k][j];
			}
	}
	for(int i=k; i<equ; i++)
		if(a[i][col]!=0)
			return -1;//无解 
	if(k<var)
		return var-k;//自由变元个数
	/*	
	int stat=1<<(var-k);//自由变元有 var-k 个
    int res=INF;
    for(i=0;i<stat;i++){//枚举所有变元
        int cnt=0;
        int index=i;
        for(j=0;j<var-k;j++){
            x[free_x[j]]=(index&1);
            if(x[free_x[j]])
				cnt++;
            index>>=1;
        }
        for(j=k-1;j>=0;j--){
            int tmp=a[j][var];
            for(int l=j+1;l<var;l++)
            	if(a[j][l])
					tmp^=x[l];
            x[j]=tmp;
            if(x[j])
				cnt++;
        }
        if(cnt<res)
			res=cnt;
    }	
	*/
	//唯一解，回代 
	for(int i=var-1; i>=0; i--){
		x[i]=a[i][var];
		for(int j=i+1; j<var; j++)
			x[i]^=(a[i][j] && x[j]);
	}
	return 0;
}
int start[maxn],end[maxn];
int main(){
	int T; cin>>T;
	while(T--){
		int n,u,v; cin>>n;
		for(int i=0; i<n; i++)
			cin>>start[i];
		for(int i=0; i<n; i++)
			cin>>end[i];
		memset(a,0,sizeof a);
		while(scanf("%d%d",&u,&v)){
			if(u==0)
				break;
			a[v-1][u-1]=1;
		}
		for(int i=0; i<n; i++)
			a[i][i]=1;
		for(int i=0; i<n; i++)
			a[i][n]=start[i]^end[i];
		equ=var=n;
		int ans=Gauss();
		if(ans==-1)
			cout<<"Oh,it's impossible~!!"<<endl;
		else
			cout<<(1<<ans)<<endl;
	}
	return 0;
}
