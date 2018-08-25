struct Complex{
	double x,y;
	Complex(double _x=0.0,double _y=0.0){
		x=_x; y=_y;
	}
	Complex operator - (const Complex &b) const {
		return Complex(x-b.x,y-b.y);
	}
	Complex operator + (const Complex &b) const {
		return Complex(x+b.x,y+b.y);
	}
	Complex operator * (const Complex &b) const {
		return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
	}
};
void change(Complex y[],int len){
	int i,j,k;
	for(i=1,j=len/2; i<len-1; i++){
		if(i<j)
			swap(y[i],y[j]);
		k=len/2;
		while(j>=k){
			j-=k;
			k/=2;
		}
		if(j<k)
			j+=k;
	}
}
void fft(Complex y[],int len,int on){
	change(y,len);
	for(int h=2; h<=len; h<<=1){
		Complex wn(cos(-on*2*pi/h),sin(-on*2*pi/h));
		for(int j=0; j<len; j+=h){
			Complex w(1,0);
			for(int k=j; k<j+h/2; k++){
				Complex u=y[k];
				Complex t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn; 
			}
		}
	}
	if(on==-1)
		for(int i=0; i<len; i++)
			y[i].x/=len;
}
Complex x1[maxn],x2[maxn];
char s1[maxn/2],s2[maxn/2];
int sum[maxn];
int main(){
	while(scanf("%s%s",s1,s2)==2){
		int len1=strlen(s1),len2=strlen(s2);
		int len=1;
		while(len < len1*2 || len < len2*2)
			len<<=1;
		for(int i = 0;i < len1;i++)
			x1[i] = Complex(s1[len1-1-i]-'0',0);
		for(int i = len1;i < len;i++)
			x1[i] = Complex(0,0);
		for(int i = 0;i < len2;i++)
			x2[i] = Complex(s2[len2-1-i]-'0',0);
		for(int i = len2;i < len;i++)
			x2[i] = Complex(0,0);
		//DFT
		fft(x1,len,1);
		fft(x2,len,1);
		for(int i = 0;i < len;i++)
			x1[i] = x1[i]*x2[i];
		fft(x1,len,-1);

		for(int i = 0;i < len;i++)
			sum[i] = (int)(x1[i].x+0.5);

		for(int i = 0;i < len;i++){
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
		len = len1+len2-1;
		while(sum[len] <= 0 && len > 0)
			len--;
		for(int i = len;i >= 0;i--)
			printf("%c",sum[i]+'0');
		printf("\n");
	}
	return 0;
}





Complex x1[maxn];
int a[maxn/4];
ll num[maxn];
ll sum[maxn]; 
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		memset(num,0,sizeof num);
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		sort(a,a+n);
		int len1=a[n-1]+1;
		int len=1;
		while(len<2*len1)
			len<<=1;
		for(int i=0; i<len1; i++)
			x1[i]=Complex(num[i],0);
		for(int i=len1; i<len; i++)
			x1[i]=Complex(0,0);
		fft(x1,len,1);
		for(int i=0; i<len; i++)
			x1[i]=x1[i]*x1[i];
		fft(x1,len,-1);
		for(int i=0; i<len; i++)
			num[i]=(ll)(x1[i].x+0.5);
		len=2*a[n-1];
		
		for(int i=0; i<n; i++)
			num[a[i]+a[i]]--;
		for(int i=1; i<=len; i++)
			num[i]/=2;
		
		sum[0]=0;
		for(int i=1; i<=len; i++)
			sum[i]=sum[i-1]+num[i];
		ll cnt=0;
		for(int i=0; i<n; i++){
			cnt+=sum[len]-sum[a[i]];
			cnt-=(ll)(n-1-i)*i;
			cnt-=n-1;
			cnt-=(ll)(n-1-i)*(n-i-2)/2;
		}
		ll tot=(ll)n*(n-1)*(n-2)/6;
		printf("%.7lf\n",(double)cnt/tot);
	}
	return 0;
}
