#include<cstdio>
#include<algorithm>
#define gi gI()

using namespace std;

inline ll gI() {
    long long p = 0, flag = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

int first[maxn], nex[maxm], to[maxm], W[maxn];

void addEdge(int u, int v) {
    nex[++cnt] = first[u];
    first[u] = cnt;
    to[cnt] = v;
}

int main() {
    return 0;
}

