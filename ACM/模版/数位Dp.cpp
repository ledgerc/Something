#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int dp[20][2000];
int a[20];//�������ֵ���������
//state��dp��״̬
//f�ǵ�ǰ���Ƿ�����
int dfs(int pos, int state, int f){
	//����ĩβ����//��������¼�¼����[0,r]
	if(pos==-1)
		;
	//û�б��������Ѿ������ֵ�����
	if (!f&&dp[pos][state]!=-1)
		return dp[pos][state];
	//i�ڿ������ƺ��ܴﵽ�����ֵ
	int end=f?a[pos]:9;
	int res=0;
	for (int i=0; i<=end; ++i){
		//״̬ת��
		int laststate=state;
		
		//��һ��״̬�Ǳ����Ƶĵ��ҽ�����ǰ��������ȡ�˼���ֵ
		res+=dfs(pos-1,laststate,f&&i==end);
	}
	//ֻ����û�����Ƶ�����²Ÿ���dp��ֵ
	//����֮dp�������û����������µ�����ֵ
	if(!f)
		dp[pos][state]=res;
	return res;
}
int cal(ll x){
	//�������������λ��¼����
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,1);
}
