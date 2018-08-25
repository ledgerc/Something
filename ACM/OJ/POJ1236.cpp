#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const int MAXM = 110*110;
struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];
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
        if(!DFN[v]){
            Tarjan(v);
            if(Low[u] > Low[v])
                  Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]){
        scc++;
        do{
            v = Stack[--top];
            Belong[v] = scc;
            Instack[v] = false;
        }
        while( v!= u);
    }
}
int in[MAXN],out[MAXN];
void solve(int N){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 1;i <= N;i++)
        if(!DFN[i])
           Tarjan(i);
    if(scc == 1){
        printf("1\n0\n");
        return;
    }
    for(int i = 1;i <= scc;i++)
       in[i] = out[i] = 0;
    for(int u = 1;u <= N;u++){
        for(int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(Belong[u] != Belong[v]){
                in[Belong[v]]++;
                out[Belong[u]]++;
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i = 1;i <= scc;i++){
        if(in[i]==0)
			ans1++;
        if(out[i]==0)
			ans2++;
    }
    printf("%d\n%d\n",ans1,max(ans1,ans2));

}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int main()
{
    int n;
    int v;
    while(scanf("%d",&n) == 1)
    {
        init();
        for(int i = 1;i <= n;i++)
        {
            while(scanf("%d",&v)==1 && v)
            {
                addedge(i,v);
            }
        }
        solve(n);
    }
    return 0;
}
