ll gcd(ll a,ll b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
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
ll eular(ll n){
	ll ans=n;
	for(int i=2; i*i<=n; i++)
		if(n%i==0){
			ans-=ans/i;
			while(n%i==0)
				n/=i;
		}
	if(n>1)
		ans-=ans/n;
	return ans;
}
ll Polya(int n,int m){//length-n color-m
	if(n==0)
		return 0;
	ll res=0;
	for(int i=1; i*i<=n; i++){
		if(n%i)
			continue;
		res+=eular(i)*pow(m,n/i);
		if(i*i!=n)
			res+=eular(n/i)*pow(m,i);
	}
	res/=n;
	if(n%2!=0)
		res+=pow(m,(n+1)/2);
	else
		res+=(pow(m,n/2)+pow(m,n/2+1))/2;
	return res/2;
}
