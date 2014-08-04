/*
Author: arcGravitus

Date: 2014/8/4

Template: Segmentational Tree

Usage: Maintain segmentational information that can be merged and splited

Interface:
    1. define sgt<data, tag> sgt1 in the main program
    2. overload class data and tag
    3. use sgt1.Build(n) to init the segmentational tree with the size n
    4. use sgt1.Query(l, r) to get information of [l, r]
    5. use sgt1.Edit(l, r, C) to tag [l, r] an information
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson u << 1
#define rson u << 1 | 1

const int T_MAX = 400001;
const int INF = 0x7FFFFFFF;

template <class T>
T min(T a, T b) {
    return a < b ? a : b;
}

typedef int tag;

struct data {
    int mn, sm;
    data () : mn(INF), sm(0) {}
    data (int a, int b) : mn(a), sm(b) {}
    data operator + (data x) {
	return data(min(mn, x.mn), sm + x.sm);
    }
    void tagIt(tag x, int len) {
	mn += x;
	sm += x * len;
    }
};

template <class T1, class T2> //T1 for data, T2 for tag

struct sgt {
    struct Node {
	int L, R;
	T1 data;
	T2 tag;
    } T[T_MAX];

    inline void Update(int u) {
	T[u].data = T[lson].data + T[rson].data;
    }

    inline void Cover(int u, T2 C) {
	T[u].tag = T[u].tag + C;
	T[u].data.tagIt(C, T[u].R - T[u].L + 1);
    }

    inline void Push(int u) {
	if (T[u].tag) {
	Cover(lson, T[u].tag);
	Cover(rson, T[u].tag);
	T[u].tag = 0;
	}
    }
    
    inline void Edit(int u, int L, int R, T2 C) {
	if (L <= T[u].L && T[u].R <= R) {
	    Cover(u, C);
	    return;
	}
	Push(u);
	if (L <= T[lson].R) Edit(lson, L, R, C);
	if (R >= T[rson].L) Edit(rson, L, R, C);
	Update(u);
    }

    inline void Edit(int L, int R, T2 C) {
	Edit(1, L, R, C);
    }

    inline T1 Query(int u, int L, int R) {
	if (L <= T[u].L && T[u].R <= R) {
	    return T[u].data;
	}
	T1 ans;
	Push(u);
	if (L <= T[lson].R) ans = ans + Query(lson, L, R);
	if (R >= T[rson].L) ans = ans + Query(rson, L, R);
	return ans;
    }

    inline T1 Query(int L, int R) {
	return Query(1, L, R);
    }

    inline void Build(int u, int L, int R) {
	T[u].L = L;
	T[u].R = R;
	if (L == R) {
	    return;
	}
	int M = (L + R) >> 1;
	Build(lson, L, M);
	Build(rson, M + 1, R);
	Update(u);
    }

    inline void Build(int n) {
	memset(T, 0, sizeof(T));
	Build(1, 1, n);
    }
};

sgt<data, tag> sgt1;

int main() {
    return 0;
}

