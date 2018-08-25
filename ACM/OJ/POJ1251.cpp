/*
Kruskal�㷨�Ļ���˼��
����WN=(V,{E})��һ������n���������ͨ�������տ�³˹�����㷨������С�������Ĺ���Ϊ��
�ȹ���һ��ֻ��n�����㣬���߼�Ϊ�յ���ͼ��
��������ͼ�и������㿴���Ǹ������ϵĸ���㣬������һ������n������һ��ɭ�֡�
֮�󣬴����ı߼�E��ѡȡһ��Ȩֵ��С�ıߣ��������ߵ��������������ͬ���������������ͼ��
Ҳ����˵��������������ֱ����ڵ��������ϳ�һ������
��֮���������ߵ���������������ͬһ�����ϣ��򲻿�ȡ����Ӧ��ȡ��һ��Ȩֵ��С�ı�����֮��
�������ƣ�ֱ��ɭ����ֻ��һ������Ҳ����ͼ�к���n-1����Ϊֹ��
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = ( 1 << 20 ) ;
int p[27];        //    ���鼯�������ж������Ƿ�ֱ�ӻ�����ͨ
struct prog {
    int u;
    int v;
    int w;
}map[80];//�洢�ߵ���Ϣ���������/�յ�/Ȩֵ
bool cmp ( prog a , prog b)
{//�����������߸���Ȩֵ��С������
    return a.w<b.w;
}
int find(int x)
{//���鼯��find��������
    return x==p[x]?x:p[x]=find(p[x]);
}
int main()
{
    int n;
    while ( cin >> n , n ) 
    {
        int i , j ;
        for  ( i = 0 ; i < 27  ; i ++ )
            p[i] = i ;//���鼯��ʼ��
        int k = 0 ;
        for ( i = 0 ; i < n - 1 ; i ++ )
        {//����ߵ���Ϣ
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

        sort ( map , map + k , cmp );//���ߴ�С��������
        int ans=0;        //��Ҫ��Ĵ�
        for ( i = 0 ; i < k ; i ++ )
        {
            int x = find(map[i].u);
            int y = find(map[i].v);
            if( x!=y)
            {//������㲻��ͬһ��ͨ��������������ӣ����洢�ñ�
                ans+=map[i].w;
                p[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
