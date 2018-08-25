#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int PL = 500;

typedef struct node
{
    int L,R;

    int Id ;

    node(){}

    node(int _L,int _R):L(_L),R(_R){}

    bool operator < (const node &a)const
    {
        return (L/PL == a.L/PL) ? (R<a.R):(L/PL<a.L/PL);
    }
}Section;

Section s[55000];

int a[55000];

LL ansm[55000];

LL ansd[55000];

int num[55000];

int main()
{
    int n,m;

    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);

        for(int i = 1;i<=m;i++) scanf("%d %d",&s[i].L,&s[i].R),s[i].Id = i;

        sort(s+1,s+m+1);

        LL sum = 0;

        int l = 0,r = 1;

        memset(num,0,sizeof(num));

        for(int i = 1;i<=m;i++)
        {
            while(r<=s[i].R)
            {
                sum+=(num[a[r]]);

                num[a[r]] ++;

                r++;
            }

            while(r>s[i].R+1)
            {
                r--;

                num[a[r]] --;

                sum-=num[a[r]];

            }

            while(l<s[i].L-1)
            {
                l++;

                num[a[l]]--;

                sum-=num[a[l]];

            }

            while(l>=s[i].L)
            {
                sum+=num[a[l]];

                num[a[l]]++;

                l--;
            }

            ansm[s[i].Id] = sum;

            ansd[s[i].Id] = (1LL*(s[i].R-s[i].L+1)*(s[i].R-s[i].L))/2;
            cout<<l<<" "<<r<<endl;
        }

        for(int i =1;i<=m;i++)
        {
            if(ansm[i] ==0) printf("0/1\n");
            else
            {
                LL g = __gcd(ansm[i],ansd[i]);

                printf("%lld/%lld\n",ansm[i]/g,ansd[i]/g);
            }
        }
    }
    return 0;
}
