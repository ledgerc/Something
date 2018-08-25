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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
const int sigma_size = 26;

struct PalindromicTree{
	//��ʾ���Ϊi�Ľڵ��ʾ�Ļ��Ĵ�����������ַ�c�Ժ��ɵĻ��Ĵ��ı��
	int next[maxn][sigma_size];
	//��ʾ�ڵ�iʧ���Ժ���ת����������Ľڵ�i��ʾ�Ļ��Ĵ������׺���Ĵ�
	int fail[maxn];
	int cnt[maxn];//��ʾ�ڵ�i��ʾ�ı��ʲ�ͬ�Ĵ��ĸ���
	//��ʾ�Խڵ�i��ʾ������Ĵ������Ҷ˵�Ϊ���Ĵ���β�Ļ��Ĵ�����
	int num[maxn];
	int len[maxn];//��ʾ���i��ʾ�Ļ��Ĵ����� 
	int s[maxn];//�����ӵ��ַ� 
	int last;//ָ����һ���ַ����ڵĽڵ�
	int n,p;//�ַ�����ָ�� �ڵ�ָ��
	
	int newnode(int l){
		for(int i=0; i<sigma_size; i++)
			next[p][i]=0;
		cnt[p]=num[p]=0;
		len[p]=l;
		return p++;
	}
	void init(){
		p=0;
		//0��ʾż�����ȴ��ĸ���1��ʾ�������ȴ��ĸ�
		newnode(0);
		newnode(-1);
		last=0;
		n=0;
		s[n]=-1;////��ͷ��һ���ַ�����û�е��ַ�����������
		fail[0]=1;
	}
	int Getfail(int x){
		while(s[n-len[x]-1]!=s[n])
			x=fail[x];
		return x;
	}
	void insert(int c){
		c-='a';
		s[++n]=c;
		int cur=Getfail(last);//ͨ����һ�����Ĵ���������Ĵ���ƥ��λ��
		if(!next[cur][c]){//���������Ĵ�û�г��ֹ���˵��������һ���µı��ʲ�ͬ�Ļ��Ĵ�
			int now=newnode(len[cur]+2);
			fail[now]=next[Getfail(fail[cur])][c];
			next[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last=next[cur][c];
		cnt[last]++;
	}
	void count(){
		//�����ۼӶ��ӵ�cnt����Ϊ���fail[v]=u����uһ����v���ӻ��Ĵ�
		for(int i=p-1; i>=0; i--)
			cnt[fail[i]]+=cnt[i];
	}
};
int main(){
	
}
