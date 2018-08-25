/*
A^x=B(mod C)(C������)��������������֪A��B��C��x
�Ȱ�x=i*m-j������m=ceil(sqrt(C))����ceil������ȡ������
����ԭʽ�ͱ�ΪA^(i*m-j)=B(mod C)��
�ٱ�ΪA^j��B=A^(m*i) (mod C)��
ö��j(��Χ0-m),��A^j��B����hash��
ö��i(��Χ1-m),��hash����Ѱ�ҵ�һ������A^j��B=A^(m*i) (mod C)��
��ʱx=i*m-j��Ϊ����
�����Ͽ���������������õ���x=i*m+j��Ҳ��������ֻ�ǻ�ǣ��������Ԫ�����ԱȽ��鷳��ʹx=i*m-j�Ϳ������ɱ�����������ˡ�
��ô�϶����˻�������Ϊ��ֻ���㵽m=ceil(sqrt(C))�Ϳ���ȷ�����أ�
x=i*m-j  Ҳ����x �����ֵ���ᳬ��p,�ǳ���p����ô�� ��
��һ����ʽ  a^(k mod p-1)=a^k (mod p)     �����ʽ���Ƶ���Ҫ�õ�����С����
k mod p-1���Կ��� k-m��p-1��  ,ԭʽ�ɻ���  a^k/(a^(p-1))^m=a^k (mod p)   
���ݷ���С���� a^(p-1)=1  (mod p) ����pΪ���� ��a,p ���ʣ��ɵ�a^k/1^m=a^k  (mod p)   a^k=a^k (mod p) ��֤��
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
