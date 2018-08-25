/*
Kruskal算法的基本思想
假设WN=(V,{E})是一个含有n个顶点的连通网，则按照克鲁斯卡尔算法构造最小生成树的过程为：
先构造一个只含n个顶点，而边集为空的子图，
若将该子图中各个顶点看成是各棵树上的根结点，则它是一个含有n棵树的一个森林。
之后，从网的边集E中选取一条权值最小的边，若该条边的两个顶点分属不同的树，则将其加入子图，
也就是说，将这两个顶点分别所在的两棵树合成一棵树；
反之，若该条边的两个顶点已落在同一棵树上，则不可取，而应该取下一条权值最小的边再试之。
依次类推，直至森林中只有一棵树，也即子图中含有n-1条边为止。
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = ( 1 << 20 ) ;
int p[27];        //    并查集，用于判断两点是否直接或间接连通
struct prog {
    int u;
    int v;
    int w;
}map[80];//存储边的信息，包括起点/终点/权值
bool cmp ( prog a , prog b)
{//排序函数，将边根据权值从小到大排
    return a.w<b.w;
}
int find(int x)
{//并查集的find，不解释
    return x==p[x]?x:p[x]=find(p[x]);
}
int main()
{
    int n;
    while ( cin >> n , n ) 
    {
        int i , j ;
        for  ( i = 0 ; i < 27  ; i ++ )
            p[i] = i ;//并查集初始化
        int k = 0 ;
        for ( i = 0 ; i < n - 1 ; i ++ )
        {//构造边的信息
            char str[3];
            int m;
            cin >> str >> m ;
            for ( j = 0 ; j < m ; j ++ ,k ++ )
            {
                char str2[3];
                int t;
                cin >> str2 >> t ;
                map[k].u=(str[0]-'A');
                map[k].v=(str2[0]-'A');
                map[k].w=t;
            }
        }

        sort ( map , map + k , cmp );//将边从小到大排序
        int ans=0;        //所要求的答案
        for ( i = 0 ; i < k ; i ++ )
        {
            int x = find(map[i].u);
            int y = find(map[i].v);
            if( x!=y)
            {//如果两点不在同一连通分量里，则将两点连接，并存储该边
                ans+=map[i].w;
                p[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
