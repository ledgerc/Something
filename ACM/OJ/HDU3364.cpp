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
const int maxn = 50+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


//һ�࿪�����⣬��2ȡģ��01������
 
//��equ�����̣�var����Ԫ�������������Ϊequ,����Ϊvar+1,�ֱ�Ϊ0��var
int equ,var;
int a[maxn][maxn],b[maxn][maxn],x[maxn];//������� �⼯ 
int free_num,free_x[maxn];//���ɱ�Ԫ�ĸ��� �����洢���ɱ�Ԫ�����ö�����ɱ�Ԫ����ʹ�ã�

//����ֵΪ-1��ʾ�޽⣬Ϊ0��Ψһ�⣬���򷵻����ɱ�Ԫ����
ll Gauss(){
	int max_r,col,k;
	free_num=0;
	for(k=0,col=0; k<equ&&col<var; k++,col++){
		max_r=k;
		for(int i=k+1; i<equ; i++)
			if(abs(a[i][col])>abs(a[max_r][col]))
				max_r=i;
		if(a[max_r][col]==0){
			k--;
			free_x[free_num++]=col;//��������ɱ�Ԫ 
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
		if(a[i][col])
			return -1;//�޽� 
	if(k<var)
		return var-k;//���ɱ�Ԫ����
	/*	
	int stat=1<<(var-k);//���ɱ�Ԫ�� var-k ��
    int res=INF;
    for(i=0;i<stat;i++){//ö�����б�Ԫ
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
	//Ψһ�⣬�ش� 
	for(int i=var-1; i>=0; i--){
		x[i]=a[i][var];
		for(int j=i+1; j<var; j++)
			x[i]^=(a[i][j] && x[j]);
	}
	return 0;
}
int main(){
	int T; scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(x,0,sizeof x);
		scanf("%d%d",&equ,&var);
		for(int i=0; i<var; i++){
			int k,tmp; scanf("%d",&k);
			while(k--){
				scanf("%d",&tmp);
				b[tmp-1][i]=1;
			}
		}
		printf("Case %d:\n",kase);
		int Q; scanf("%d",&Q);
		while(Q--){
			memcpy(a,b,sizeof b);
			for(int i=0; i<equ; i++)
				scanf("%d",&a[i][var]);
			ll ans=Gauss();
			if(ans!=-1){
				ans=(1LL<<ans);//!!!!!!!!!!
				cout<<ans<<endl;	
			}
			else
				cout<<"0"<<endl;
		}
	}
	return 0;
}
