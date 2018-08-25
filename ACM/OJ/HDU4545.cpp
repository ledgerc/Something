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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
char str1[maxn],str2[maxn];
char s1[10],s2[10];
bool dp[maxn][maxn];
bool g[30][30];
int T,m;
int main(){
	cin>>T;
	for(int kase=1; kase<=T; kase++){
		memset(dp,false,sizeof dp);
		memset(g,false,sizeof g);
		cin>>m;
		while(m--){
            scanf("%s%s",&s1,&s2);
            g[s1[0]-'a'][s2[0]-'a']=true;
		}
        int len1=strlen(str1);
        int len2=strlen(str2);
		dp[0][0]=true;
		for(int i=0; i<=len2; i++)	
			dp[0][i]=true;
		
	}
} 
/*
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <math.h>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;
const int MAXN=1010;
char str1[MAXN],str2[MAXN];
bool g[30][30];
bool dp[MAXN][MAXN];
int main(){
    int T;
    scanf("%d",&T);
    int iCase=0;
    while(T--){
        iCase++;
        scanf("%s%s",&str1,&str2);
        memset(dp,false,sizeof(dp));
        memset(g,false,sizeof(g));
        int m;
        char s1[10],s2[10];
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%s",&s1,&s2);
            g[s1[0]-'a'][s2[0]-'a']=true;
        }
        int len1=strlen(str1);
        int len2=strlen(str2);
        dp[0][0]=true;
        for(int i=0;i<=len2;i++)
            dp[0][i]=true;
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
            {
                if(dp[i][j-1])
                {
                    dp[i][j]=true;
                    continue;
                }
                if(str1[i-1]==str2[j-1]&&dp[i-1][j-1])
                {
                    dp[i][j]=true;
                    continue;
                }
                if(g[str2[j-1]-'a'][str1[i-1]-'a']&&dp[i-1][j-1])
                {
                    dp[i][j]=true;
                    continue;
                }
            }
        if(dp[len1][len2])
			printf("Case #%d: happy\n",iCase);
        else
			printf("Case #%d: unhappy\n",iCase);
    }
    return 0;
}
*/
