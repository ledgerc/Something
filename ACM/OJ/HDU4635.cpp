#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<math.h>
using namespace std;
const int MAXN = 100010;//����
const int MAXM = 100010;//����
struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong�����ֵ��1~scc
int Index,top;
int scc;//ǿ��ͨ�����ĸ���
bool Instack[MAXN];
int num[MAXN];//����ǿ��ͨ����������ĸ�����������1~scc
//num���鲻һ����Ҫ�����ʵ�����
void addedge(int u,int v){
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void Tarjan(int u){
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next){
        v = edge[i].to;
        if( !DFN[v] ){
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]){
        scc++;
        do{
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }
        while( v != u);
    }
}
void solve(int N){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
    for(int i = 1;i <= N;i++)
        if(!DFN[i])
            Tarjan(i);
}
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
int in[MAXN],out[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    int iCase = 0;
    int n,m;
    int u,v;
    while(T--){
        iCase++;
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        solve(n);
        if(scc == 1){
            printf("Case %d: -1\n",iCase);
            continue;
        }
        for(int i = 1;i <= scc;i++){
            in[i] = 0;
            out[i] = 0;
        }
        for(int u = 1;u <= n;u++)
            for(int i = head[u];i != -1;i = edge[i].next){
            	int v = edge[i].to;
            	if(Belong[u]==Belong[v])
					continue;
            	out[Belong[u]]++;
            	in[Belong[v]]++;
        	}
        long long sss = (long long)n*(n-1) - m;
        long long ans = 0;
        for(int i = 1;i <= scc;i++){
            if(in[i]==0||out[i]==0)
                ans = max(ans,sss - (long long)num[i]*(n-num[i]));
        }
        printf("Case %d: %d\n",iCase,ans);
    }
    return 0;
}
