#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
#define bug() cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 4e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

char s[maxn];
struct SuffixAutoMachine{
	int ch[maxn][26],len[maxn],link[maxn];
	//right数组 该节点表示的字符串出现的次数 
	//sum数组 该节点子串数目 
	int topo[maxn],cnt[maxn],right[maxn],sum[maxn];
	int size,last;
	int ans;
	void init(){
		size=last=ans=0;
		len[0]=0; link[0]=-1;
		memset(cnt,0,sizeof cnt);
		memset(ch[0],-1,sizeof ch[0]);
	}
    void extend(int c){
        int p=last,np=++size;
        len[np]=len[p]+1; //right[np]++;
        memset(ch[np], -1, sizeof ch[np]);
        while(p!=-1&&ch[p][c]==-1)
			ch[p][c]=np,p=link[p];
        if(p==-1){
			link[np]=0;
		}
        else{
            int q=ch[p][c];
            if(len[q] != len[p] + 1){
                int nq = ++size;
                memcpy(ch[nq], ch[q], sizeof ch[q]);
                len[nq] = len[p] + 1;
                link[nq] = link[q];
                link[q] = link[np] = nq;
                while(p!=-1 && ch[p][c] == q)
					ch[p][c] = nq, p = link[p];
            }
            else link[np] = q;
        }
        //len[np]-len[link[np]];//加入c后增加的子串的数目;
        last = np;
    }
    void init_topo(){	
    	for(int i=1; i<=size; i++) cnt[len[i]]++;
    	for(int i=1; i<=last; i++) cnt[i]+=cnt[i-1];
    	for(int i=1; i<=size; i++) topo[cnt[len[i]]--]=i;
    	/*
    	for(int i=size; i>=1; i--){
			int u=topo[i];
			right[link[u]]+=right[u];
		}
		for(int i=size; i>0; i--){
    		int tmp=b[i]; sum[tmp]=1;
    		for(int j=0; j<26; j++)
    			sum[tmp]+=sum[ch[tmp][j]];
		}
		*/
	}
}sam;
