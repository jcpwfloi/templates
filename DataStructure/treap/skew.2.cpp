#include<cstdio>
#include<algorithm>

using namespace std;

struct Node {
    Node* ch[2];
    int r, v, s;
    inline int cmp(int x) {return x < v ? 0 : 1;}
    void maintain() {s = 1 + ch[0] ? ch[0] -> s : 0 + ch[1] ? ch[1] -> s : 0;}
    Node(int v) : v(v), r(rand()), s(1) {ch[0] = ch[1] = NULL;}
};

Node* merge(Node* &a, Node* &b) {
    if (!a) return b;
    if (!b) return a;
    if (a -> r < b -> r) swap(a, b);
    int d = a -> cmp(b -> v);
    a -> ch[d] = merge(a -> ch[d], b);
    return a;
}

/*pair<Node*, Node*> split(Node* &a, int k) {
    if (k == 0) {
	Node* null = NULL;
	return mp(NULL, a);
    }
    if (!a -> ch[0]) {
	pair<Node*, Node*> ans = split(a -> ch[1], k - 1);
	a -> ch[1] = NULL;
	a -> maintain();
	return mp(merge(a, ans.first), ans.second);
    } else {
	if (k <= a -> ch[0] -> s) {
	    pair<Node*, Node*> ans = split(a -> ch[0], k);
	    a -> ch[0] = NULL;
	    a -> maintain();
	    return mp(ans.first, merge(ans.second, a));
	} else if (k == a -> ch[0] -> s + 1) {
	    Node* tmp = a -> ch[1];
	    a -> ch[1] = NULL;
	    a -> maintain();
	    return mp(a, tmp);
	} else {
	    int orsize = a -> s;
	    Node* tmp = a -> ch[1];
	    a -> ch[1] = NULL;
	    a -> maintain();
	    pair<Node*, Node*> ans = split(tmp, orsize - a -> s);
	    return mp(merge(a, ans.first), ans.second);
	}
    }
}*/

int main() {
    return 0;
}
