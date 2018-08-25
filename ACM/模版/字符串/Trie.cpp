const int MAX = 26;
const int maxnode = 2e6+7;
const int sigma_size = 2;
struct Trie{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	void clear(){
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
	}
	int idx(char c){
		return c-'a';
	}
	void insert(char *s){
		int u=0,n=strlen(s);
		for(int i=0; i<n; i++){
			int id=idx(s[i]);
			if(ch[u][id]==0){
				ch[u][id]=sz;
				memset(ch[sz],0,sizeof ch[sz]);
				val[sz++]=0;
			}
			u=ch[u][id];
			val[u]++;
		}
	}
	int search(char *s){
		int n=strlen(s),u=0;
		for(int i=0; i<n; i++){
			int id=idx(s[i]);
			if(ch[u][id]==0)
				return 0;
			u=ch[u][id];
		}
		return val[u];
	}
}trie;



const int MAX = 26;
const int maxnode = 4000*1000+100;
const int sigma_size = 26;
ll ans;
struct Trie{
	int head[maxnode];
	int next[maxnode];
	char ch[maxnode];
	int tot[maxnode];
	int flag[maxnode];
	int sz;
	void clear(){
		sz=1; tot[0]=head[0]=next[0]=0;
		memset(flag,0,sizeof flag);
	}
	void insert(const char *s){
		int u=0,v,n=strlen(s);
		ans+=tot[0];
		tot[0]++;
		for(int i=0; i<n; i++){
			bool found=false;
			for(v=head[u]; v!=0; v=next[v])
				if(ch[v]==s[i]){
					found=true;
					break;
				}
			if(!found){
				v=sz++;
				tot[v]=flag[v]=head[v]=0;
				next[v]=head[u];
				ch[v]=s[i];
				head[u]=v;
			}
			u=v;
			ans+=tot[u]*2;
			tot[u]++;
		}
		if(flag[v])
			ans+=flag[v];
		flag[v]++;
	}
};
char s[1010];
Trie trie;
int main(){
	int n,kase=1;
	while(scanf("%d",&n)!=EOF&&n){
		trie.clear();
		ans=0;
		for(int i=0; i<n; i++){
			scanf("%s",s);
			trie.insert(s);
		}
		printf("Case %d: %lld\n",kase++,ans);
	}
	return 0;
}
