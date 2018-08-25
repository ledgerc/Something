
#define eps 1e-9
double a[maxn][maxn],x[maxn];//方程的左边的矩阵和等式右边的值，求解之后x存的就是结果
int equ,var;//方程数和未知数个数

//返回0表示无解，1表示有解
int Gauss(){
	int i,j,k,col,max_r;
	for(k=0,col=0; k<equ&&col<var; k++,col++){
		max_r=k;
		for(i=k+1; i<equ; i++)
			if(fabs(a[i][col])>fabs(a[max_r][col]))
				max_r=i;
		if(fabs(a[max_r][col])<eps)
			return 0;
		if(k!=max_r){
			for(j=col; j<var; j++)
				swap(a[k][j],a[max_r][j]);
			swap(x[k],x[max_r]);
		}
		x[k]/=a[k][col];
		for(j=col+1; j<var; j++)
			a[k][j]/=a[k][col];
		a[k][col]=1;
		for(i=0; i<equ; i++)
			if(i!=k){
				x[i]-=x[k]*a[i][k];
				for(j=col+1;j<var;j++)
					a[i][j]-=a[k][j]*a[i][col];
				a[i][col]=0;
			}
	}
	return 1;
}



//一类开关问题，对2取模的01方程组
 
//有equ个方程，var个变元。增广矩阵行数为equ,列数为var+1,分别为0到var
int equ,var;
int a[maxn][maxn],x[maxn];//增广矩阵 解集 
int free_num,free_x[maxn];//自由变元的个数 用来存储自由变元（多解枚举自由变元可以使用）

//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss(){
	int max_r,col,k;
	free_num=0;
	for(k=0,col=0; k<equ&&col<var; k++,col++){
		max_r=k;
		for(int i=k+1; i<equ; i++)
			if(abs(a[i][col])>abs(a[max_r][col]))
				max_r=i;
		if(a[max_r][col]==0){
			k--;
			free_x[free_num++]=col;//这个是自由变元 
			continue;
		}
		if(max_r!=k){
			for(int j=col; j<var+1; j++)
				swap(a[k][j],a[max_r][j]);
		}
		for(int i=k+1; i<equ; i++)
			if(a[i][col]!=0){
				for(int j=col; j<var+1; j++)
					a[i][j]^=a[k][j];
			}
	}
	for(int i=k; i<equ; i++)
		if(a[i][col]!=0)
			return -1;//无解 
	if(k<var)
		return var-k;//自由变元个数
	/*	
	int stat=1<<(var-k);//自由变元有 var-k 个
    int res=INF;
    for(i=0;i<stat;i++){//枚举所有变元
        int cnt=0;
        int index=i;
        for(j=0;j<var-k;j++){
            x[free_x[j]]=(index&1);
            if(x[free_x[j]])
				cnt++;
            index>>=1;
        }
        for(j=k-1;j>=0;j--){
            int tmp=a[j][var];
            for(int l=j+1;l<var;l++)
            	if(a[j][l])
					tmp^=x[l];
            x[j]=tmp;
            if(x[j])
				cnt++;
        }
        if(cnt<res)
			res=cnt;
    }	
	*/
	//唯一解，回代 
	for(int i=var-1; i>=0; i--){
		x[i]=a[i][var];
		for(int j=i+1; j<var; j++)
			x[i]^=(a[i][j] && x[j]);
	}
	return 0;
}


//求解对MOD取模的方程组 
const int MOD = 1;
int a[maxn][maxn],x[maxn];//增广矩阵 解集 

int gcd(int a,int b){
	while(b!=0){
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
ll inv(ll a,ll m){
	if(a==1)
		return 1;
	else
		return inv(m%a,m)*(m-m/a)%m;
}
int Gauss(int equ,int var){
	int max_r,col,k;
	for(k=0,col=0; k<equ&&col<var; k++,col++){
		max_r=k;
		for(int i=k+1; i<equ; i++)
			if(abs(a[i][col])>abs(a[max_r][col]))
				max_r=i;
		if(a[max_r][col]==0){
			k--;
			continue;
		}
		if(max_r!=k)
			for(int j=col; j<var+1; j++)
				swap(a[k][j],a[max_r][j]);
		for(int i=k+1; i<equ; i++){
			if(a[i][col]!=0){
				int LCM=lcm(abs(a[i][col]),abs(a[k][col]));
				int ta=LCM/abs(a[i][col]);
				int tb=LCM/abs(a[k][col]);
				if(a[i][col]*a[k][col]<0)
					tb=-tb;
				for(int j=col; j<var+1; j++)
					a[i][j]=((a[i][j]*ta-a[k][j]*tb)%MOD+MOD)%MOD;
			}
		}
	}
	for(int i=k; i<equ; i++)
		if(a[i][col]!=0)
			return -1;//无解 
	if(k<var)
		return var-k;//多解 
	for(int i=var-1; i>=0; i--){
		int temp=a[i][var];
		for(int j=i+1; j<var; j++){
			if(a[i][j]!=0){
				temp-=a[i][j]*x[j];
				temp=(temp%MOD+MOD)%MOD;
			}
		}
		x[i]=(temp*inv(a[i][i],MOD))%MOD;
	}
	return 0;
}
