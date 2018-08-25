#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 4;
const int inf = 0x3f3f3f3f;
bool check[maxn+10];
int prime[maxn+10];
int mu[maxn+10];
void Moblus(){
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= maxn; i++){
        if(!check[i]){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++){
            if(i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }
            else{
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
int a, b, c, d, k;
ll F[maxn];
int main(){
	int T, kase = 1;
	cin>>T;
	Moblus();
	while(T--){
		cin>>a>>b>>c>>d>>k;
		if(k == 0){
			cout<<"Case "<<kase++<<": 0"<<endl;
			continue;
		}
		b /= k;
		d /= k;
		int ed = min(b, d);
		ll f1 = 0,f2=0;
		for(int i = 1; i <= ed; i++){
			F[i] = (ll)(b / i) * (ll)(d / i);
			f1 += F[i] * mu[i];
			F[i] = (ll)(ed / i) * (ll)(ed / i - 1);
			f2 += F[i] * mu[i];
		}
		f1=f1-(f2/2);
		cout<<"Case "<<kase++<<": "<<f1<<endl;
	}
}
