int prime[maxn];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=maxn; i++){
        if(!prime[i])
			prime[++prime[0]]=i;
        for(int j=1; j<=prime[0]&&prime[j]<=maxn/i; j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
				break;
        }
    }
}
bool notprime[1000010];
int prime2[1000010];
void getPrime2(int L,int R){
    memset(notprime,false,sizeof(notprime));
    if(L<2)
		L=2;
    for(int i=1; i<=prime[0]&&(ll)prime[i]*prime[i]<=R; i++){
        int s=L/prime[i]+(L%prime[i]>0);
        if(s==1)
			s=2;
        for(int j=s; (ll)j*prime[i]<=R; j++)
            if((ll)j*prime[i]>=L)
                notprime[j*prime[i]-L]=true;
    }
    prime2[0]=0;
    for(int i=0; i<=R-L; i++)
        if(!notprime[i])
            prime2[++prime2[0]]=i+L;
}
int main(){
    getPrime();
    int L,U;
    while(scanf("%d%d",&L,&U)==2){
        getPrime2(L,U);
        for(int i=0; i<=U; i++)
        	printf("%2d: %2d\n",i,prime[i]);
        cout<<"-------------"<<endl;
        for(int i=0; i<=U; i++)
        	printf("%2d: %2d\n",i,prime2[i]);
        /*
        if(prime2[0]<2)
			printf("There are no adjacent primes.\n");
        else{
            int x1=0,x2=100000000,y1=0,y2=0;
            for(int i=1; i<prime2[0]; i++){
                if(prime2[i+1]-prime2[i]<x2-x1){
                    x1=prime2[i];
                    x2=prime2[i+1];
                }
                if(prime2[i+1]-prime2[i]>y2-y1){
                    y1=prime2[i];
                    y2=prime2[i+1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",x1,x2,y1,y2);
        }
        */
    }
}

/*
int prime[maxn];
bool isprime[maxn+1];
void init(){
	int p=0;
	memset(isprime,true,sizeof isprime);
	isprime[0]=isprime[1]=false;
	for(int i=2; i<=maxn; i++){
		if(isprime[i]){
			prime[p++]=i;
			for(int j=2*i; j<=maxn; j+=i)
				isprime[j]=false;
		}
	}
}
*/

bool not_prime[maxn];
int prime[maxn];
void init(){
	int total=0;
	memset(not_prime,false,sizeof not_prime);
	not_prime[1]=true;
	for(int i=2; i<=n; i++){
		if(!not_prime[i])
			prime[++total]=i;
		for(int j=1; j<=total&&i*prime[j]<=n; j++){
			not_prime[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}









int prime[maxn+10];//第i个质数 
void getPrime(){
	memset(prime,0,sizeof prime);
	for(int i=2; i<=maxn; i++){
		if(!prime[i])
			prime[++prime[0]]=i;
		for(int j=1; j<=prime[0]&&prime[j]<=maxn/i; j++){
			prime[prime[j]*i]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
ll factor1[100][2];
ll factor2[100][2];
int fatCnt;
int getFactors(ll x,ll factor[][2]){
	fatCnt=0;
	ll tmp = x;
	for(int i=1; prime[i]<=tmp/prime[i]; i++){
		factor[fatCnt][1]=0;
		if(tmp%prime[i]==0){
			factor[fatCnt][0]=prime[i];
			while(tmp%prime[i]==0){
				factor[fatCnt][1]++;
				tmp/=prime[i];
			}
			fatCnt++;
		}
	}
	if(tmp!=1){
		factor[fatCnt][0]=tmp;
		factor[fatCnt++][1]=1;
	}
	return fatCnt;
}
