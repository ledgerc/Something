int GetMin(int s[],int len){//数组开两倍 
	int i=0,j=1,k=0;
	while(i<len&&j<len){
		k=0;
		while(s[i+k]==s[j+k]&&k<len)
			k++;
		if(k==len)
			return min(i,j);
		//改成   <   就是最大表示法啦 
		if(s[i+k]>s[j+k])//即s1[i->i+k]不会是该循环字符串的“最小表示”的前缀 
			if(i+k+1>j)
				i=i+k+1;
			else
				i=j+1;
		else if(j+k+1>i)
			j=j+k+1;
		else
			j=i+1;
	}
	if(i<len)
		return i;
	return j;
}
