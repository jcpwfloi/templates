#include<cstdio>
#include<algorithm>
#include<cstring>

#define gi gI()
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define repD(i, r, l) for(int i = r; i >= l; i--)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define lowbit(x) (x & (-x))

#define maxn 1001

using namespace std;

typedef long long ll;

inline ll gI() {
    ll flag = 1, p = 0;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

char s[100001];
char s2[200001];
int L[200001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("Manacher.in", "r", stdin);
    freopen("Manacher.out", "w", stdout);
#endif
    gets(s);
    int len = strlen(s);
    s2[0] = s[0];
    for (int i = 0; i < len; i++) {
	s2[i * 2] = s[i];
	s2[i * 2 - 1] = '$';
    }
    len = strlen(s2);
    k = 0;
    L[k] = 1;
    for (int i = 0; i < len; i++) {
	L[i] = (L[k] + k > i) ? min(L[2 * k - i], k + L[k] - i) : 1;
	while (0 <= i - L[i] && i + L[i] < len &&
	       s2[i - L[i]] == s2[i + L[i]]) ++L[i];
	if (i + L[i] > k + L[k]) k = i;
    }
    for (int i = 0; i < len; i++) printf("%d%c", L[i], i == len - 1 ? '\n' : ' ');
    return 0;
}

