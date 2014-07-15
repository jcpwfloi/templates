#include<cstdio>
#include<algorithm>
#define rep(i, l, r) for (int i = l; i <= r; i++)

using namespace std;
bool build() {
    int x,y;
    memset(d,-1,sizeof(d));
    memset(G,-1,sizeof(G));
    bg = ed = d[s] = 0; Q[ed++] = s; G[s] = g[s];
    while(bg < ed) {
	x = Q[bg++];
	for (int i = g[x]; i + 1; i = np[i]){
	    y = to[i];
	    if (cap[i] && d[y] == -1) {
		d[y] = d[x] + 1; G[y] = g[y];
		if (y == t) return true;
		Q[ed++] = y;
	    }
	}
    }
    return false;
}
 
int find(int x,int low = inf) {
    if (x == t) return low;
    int ret = 0, y;
    for(int &i = G[x]; i + 1; i = np[i]) {
	y = to[i];
	if(cap[i] && d[y] == d[x]+1 && (ret = find(y, low <? cap[i]))) {
	    cap[i] -= ret; cap[vp[i]] += ret;
	    return ret;
	}
    }
    return 0;
}
 
int dinic() {
    int flow;
    while (build())
	while (flow = find(s))
	    cnt+=flow;
    return 0;
}

int main() {
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    fclose(stdin);
    fclose(stdout);
}

