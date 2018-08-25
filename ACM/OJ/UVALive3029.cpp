#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
int g[N][N], up[N][N], left[N][N], right[N][N];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) {
				int ch = getchar();
				while(ch != 'F' && ch != 'R') 
					ch = getchar();
				g[i][j] = ch == 'F' ? 0 : 1;
			}
		int ans = 0;
		for(int i = 0; i < m; i++) {
			int l = -1, r = n;
			for(int j = 0; j < n; j++)
				if(g[i][j] == 1) { up[i][j] = left[i][j] = 0; l = j; }
				else {
					up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
					left[i][j] = i == 0 ? l + 1 : max(left[i - 1][j], l + 1);
				}
			for(int j = n-1; j >= 0; j--)
				if(g[i][j] == 1) { right[i][j] = n; r = j; }
				else {
					right[i][j] = i == 0 ? r-1 : min(right[i-1][j], r - 1);
					ans = max(ans, up[i][j]*(right[i][j]-left[i][j]+1));
				}
		}
		printf("%d\n", ans*3);
	}
	return 0;
}
