int GetMin(int s[],int len){//���鿪���� 
	int i=0,j=1,k=0;
	while(i<len&&j<len){
		k=0;
		while(s[i+k]==s[j+k]&&k<len)
			k++;
		if(k==len)
			return min(i,j);
		//�ĳ�   <   ��������ʾ���� 
		if(s[i+k]>s[j+k])//��s1[i->i+k]�����Ǹ�ѭ���ַ����ġ���С��ʾ����ǰ׺ 
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
