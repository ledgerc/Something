#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int INF=0x7f7f7f7f;
int a[N];
vector<int>vec[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec[a[i]].push_back(i);
	}
	ll ans=0,dis=1,p=0;
	for(int i=1;i<N;i++)
	{
		if(vec[i].empty())continue;
		vector<int>::iterator ite=lower_bound(vec[i].begin(),vec[i].end(),p);
		ans+=dis*(vec[i].end()-ite);
		p=vec[i].back();
		vec[i].erase(ite,vec[i].end());
		if(vec[i].size())
		{
			p=0;
			dis++;
			i--;
		}
	}		
	cout<<ans<<endl;
	return 0; 
} 
