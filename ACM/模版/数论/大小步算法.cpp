/*
A^x=B(mod C)(C是质数)，都是整数，已知A、B、C求x
先把x=i*m-j，其中m=ceil(sqrt(C))，（ceil是向上取整）。
这样原式就变为A^(i*m-j)=B(mod C)，
再变为A^j×B=A^(m*i) (mod C)。
枚举j(范围0-m),将A^j×B存入hash表
枚举i(范围1-m),从hash表中寻找第一个满足A^j×B=A^(m*i) (mod C)。
此时x=i*m-j即为所求。
在网上看到的其他题解大多用的是x=i*m+j，也可以做，只是会牵扯的求逆元，所以比较麻烦。使x=i*m-j就可以轻松避免这个问题了。
那么肯定有人会有疑问为何只计算到m=ceil(sqrt(C))就可以确定答案呢？
x=i*m-j  也就是x 的最大值不会超过p,那超过p的怎么办 ？
有一个公式  a^(k mod p-1)=a^k (mod p)     这个公式的推导需要用到费马小定理
k mod p-1可以看做 k-m（p-1）  ,原式可化成  a^k/(a^(p-1))^m=a^k (mod p)   
根据费马小定理 a^(p-1)=1  (mod p) 其中p为质数 ，a,p 互质，可得a^k/1^m=a^k  (mod p)   a^k=a^k (mod p) 得证。
*/
/*
ll a,b,c,m;
map<ll,int> mp;
ll mod_pow(ll x,ll n,ll mod){
	ll res=1;
	while(n>0){
		if(n&1)
			res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	while(scanf("%lld%lld%lld",&c,&a,&b)!=EOF){
		mp.clear();
		if(a%c==0){
			printf("no solution\n");
			continue;
		}
		int flag=false;
		m=ceil(sqrt(c));
		ll ans=0;
		for(int i=0; i<=m; i++){
			if(i==0){
				ans=b%c;
				mp[ans]=i;
				continue;
			}
			ans=(ans*a)%c;
			mp[ans]=i;
		}
		ll t=mod_pow(a,m,c);
	//	cout<<"T: "<<t<<endl;
		ans=1;
		for(int i=1; i<=m; i++){
			ans=(ans*t)%c;
			if(mp[ans]){
				int tmp=i*m-mp[ans];
				printf("%d\n",(tmp%c+c)%c);
				flag=true;
				break;
			}
		}
		if(!flag)
			printf("no solution\n");
	}
	return 0;
}
*/













#define mod 76543
int hs[mod],head[mod],next[mod],id[mod],top;
void insert(int x,int y){
	int k = x % mod;
	hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}
int find(int x){
	int k = x % mod;
	for(int i= head[k]; i!=-1; i=next[i])
		if(hs[i]==x)
			return id[i];
	return -1;
}
int BSGS(int a,int b,int n){
	memset(head,-1,sizeof head);
	top=1;
	if(b == 1)
		return 0;
	int m = sqrt(n*1.0), j;
	long long x = 1, p = 1;
	for(int i = 0; i < m; ++i, p = p*a%n)
		insert(p*b%n,i);
	for(long long i = m; ;i += m){
		if( (j = find(x = x*p%n)) != -1 )
			return i-j;
		if(i > n)
			break;
	}
	return -1;
}
