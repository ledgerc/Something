struct DominatorTree{
	int n,m;
	int tot;
	int dfn[maxn],id[maxn],fa[maxn];
	//支配点 半支配点 
	int idom[maxn],semi[maxn]; 
	int f[maxn],best[maxn];
	vector<int> pre[maxn],nxt[maxn];
	vector<int> dom[maxn];//支配树每个点的儿子
	void dfs(int u){
		dfn[u]=++tot;
		id[tot]=u;
		for(int i=0; i<nxt[u].size(); i++){
			int v=nxt[u][i];
			if(dfn[v]) continue;
			fa[v]=u;
			dfs(v);
		}
	}
	int get(int x){
		if(x==f[x]) return x;
		int y=get(f[x]);
		if(dfn[semi[best[x]]]>dfn[semi[best[f[x]]]])
			best[x]=best[f[x]];
		f[x]=y;
		return y;
	}
	void tarjan(){
		for(int i=tot; i>1; i--){
			int y=id[i]; int x=fa[y];
			for(int j=0; j<pre[y].size(); j++){
				int z=pre[y][j];
				if(dfn[z]==0) continue;
				get(z);
				if(dfn[semi[best[z]]]<dfn[semi[y]])
					semi[y]=semi[best[z]];
			}
			dom[semi[y]].push_back(y);
			f[y]=x;
			for(int j=0; j<dom[x].size(); j++){
				int z=dom[x][j];
				get(z);
				if(dfn[semi[best[z]]]<dfn[x])
					idom[z]=best[z];
				else
					idom[z]=x;
			}
			dom[x].clear();
		}
		for(int i=2; i<tot+1; i++){
			int u=id[i];
			if(idom[u]!=semi[u])
				idom[u]=idom[idom[u]];
			dom[idom[u]].push_back(u);
		}
		idom[id[1]]=0;
	}
	void init(){
		for(int i=1; i<=n; i++){
			f[i]=best[i]=i;
			nxt[i].clear(); pre[i].clear();
			dom[i].clear();
			dfn[i]=id[i]=0;
			idom[i]=semi[i]=i;
		}
	}
	void build(int n){
		tot=0;
		dfs(n);
		tarjan();
	}
}dt;
