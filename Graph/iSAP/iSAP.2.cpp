#include<cstdio>
#include<algorithm>

using namespace std;

int dfs(int u, int flow) {
    if (u == n) return flow;
    int ret = 0;
    rep(v, 1, n) if (g[u][v] > 0 && d[u] == d[v] + 1) {
	tmp = dfs(v, min(flow - dfs, g[u][v]));
	g[u][v] -= tmp, g[v][u] += tmp;
	if (c[u][v] > 0)
	    f[u][v] += tmp;
	else
	    f[v][u] -= tmp;
	ret += tmp;
	if (ret == flow) return ret;
    }
    if (d[1] >= n) return 0;
    if (!--vd[d[u]]) d[1] = n;
    ++vd[++d[u]];
}

int main() {
}

