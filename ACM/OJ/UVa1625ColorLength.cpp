#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=1<<29;
const int maxn=5010;
char stra[maxn],strb[maxn];
int dp[maxn][maxn],res[maxn][maxn],first[27][2],last[27][2],l1,l2,tot;
bool vis[27];
void Init(){
    memset(vis,0,sizeof(vis));
    memset(last,-1,sizeof(last));
    for(int i=0;i<27;i++)
        first[i][0]=first[i][1]=inf;
    tot=0;
    l1=strlen(stra);
    l2=strlen(strb);
    for(int i=0;i<l1;i++){
        if(!vis[stra[i]-'A']){
            vis[stra[i]-'A']=1;
            tot++;
        }
        if(first[stra[i]-'A'][0]==inf)
            first[stra[i]-'A'][0]=i;
        last[stra[i]-'A'][0]=i;
    }
    for(int i=0;i<l2;i++){
        if(!vis[strb[i]-'A']){
            vis[strb[i]-'A']=1;
            tot++;
        }
        if(first[strb[i]-'A'][1]==inf)
            first[strb[i]-'A'][1]=i;
        last[strb[i]-'A'][1]=i;
    }
    for(int i=0;i<=l1;i++)
        for(int j=0;j<=l2;j++){
            int cnt=0;
            for(int k=0;k<26;k++){
                if(first[k][0]==inf&&first[k][1]==inf)
                    continue;
                if(first[k][0]>i-1&&first[k][1]>j-1)
                    continue;
                if(last[k][0]<=i-1&&last[k][1]<=j-1)
                    continue;
                cnt++;
            }
            res[i][j]=cnt;
        }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",stra,strb);
        Init();
        dp[l1][l2]=0;
        for(int i=l2-1;i>=0;i--)
            dp[l1][i]=dp[l1][i+1]+res[l1][i];
        for(int i=l1-1;i>=0;i--)
            for(int j=l2;j>=0;j--){
                if(j==l2)
                    dp[i][j]=dp[i+1][j]+res[i][j];
                else
                    dp[i][j]=min(dp[i+1][j],dp[i][j+1])+res[i][j];
            }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
/*
如果大部分数据范围比较小，还是不要用memset初始化。先读入数据范围，再手写for循环初始化。
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=5005;
char a[maxn],b[maxn];
int len1,len2;
int first[255][3],last[255][3];
int dp[maxn][maxn];
int c[maxn][maxn];
int main(){
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;++kase){
        scanf("%s%s",a+1,b+1);
        len1=strlen(a+1),len2=strlen(b+1);
        for(int i='A';i<='Z';i++){
            first[i][1]=first[i][2]=inf;
            last[i][1]=last[i][2]=-1;
        }
        for(int i=0;i<=len1;i++)
            for(int j=0;j<=len2;j++)
            c[i][j]=dp[i][j]=0;
        for(int i=1;i<=len1;i++){
            if(first[a[i]][1]==inf) first[a[i]][1]=i;
            last[a[i]][1]=i;
        }
        for(int i=1;i<=len2;i++){
            if(first[b[i]][2]==inf) first[b[i]][2]=i;
            last[b[i]][2]=i;
        }
        for(int i=0;i<=len1;i++){
            if(i){
                c[i][0]=c[i-1][0];
                if(first[a[i]][1]==i) c[i][0]++;
                if(last[a[i]][1]==i&&last[a[i]][2]==-1) c[i][0]--;
            }
            for(int j=1;j<=len2;j++){
                c[i][j]=c[i][j-1];
                if(first[b[j]][2]==j&&first[b[j]][1]>i) c[i][j]++;
                if(last[b[j]][2]==j&&last[b[j]][1]<=i) c[i][j]--;
            }
        }
        for(int i=0;i<=len1;i++)
            for(int j=0;j<=len2;j++){
                if(i>0&&j>0) dp[i][j]=min(dp[i-1][j],dp[i][j-1])+c[i][j];
                else if(i==0&&j>0) dp[i][j]=dp[i][j-1]+c[i][j];
                else if(i>0&&j==0) dp[i][j]=dp[i-1][j]+c[i][j];
            }
        printf("%d\n",dp[len1][len2]);
    }
}
