#include<cstdio>
#include<algorithm>

using namespace std;

namespace treap {
    struct Node {
	Node* ch[2];
	int val, r, s;
	Node (int v) : val(v), r(rand()), s(1) {ch[0] = ch[1] = NULL;}}
	inline int cmp(int x) {return x < val ? 0 : 1;}
	void maintain() {s = 1;if (ch[0] != NULL) s = s + ch[0] -> s;if (ch[1] != NULL) s = s + ch[1] -> s;}
    };
    Node* merge(Node& *a, Node& *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a -> r < b -> r) swap(a, b);
	int d = a -> cmp(b -> val);
	a -> ch[d] = merge(a -> ch[d], b);
    }
    pair<Node*, Node*> split(Node& *a, int k) {
	if (!a -> ch[0]) {
	    if (k == 1) {
		a -> ch[1] = NULL;
		return make_pair(a, a -> ch[1]);
	    } else {
		a -> ch[1] = NULL;
		pair<Node*, Node*> result = split(a -> ch[1], k - 1);
		return make_pair(merge(a, result.first), result.second);
	    }
	} else {
	    if (k <= a -> ch[0] -> s) {
		pair<Node*, Node*> result = split(a -> ch[0], k);
		a -> ch[0] = NULL;
		return make_pair(result.first, merge(result.second, a));
	    } else {
		Node* pre = a -> ch[0];
		int leftans = a -> ch[0] -> s;
		a -> ch[0] = NULL;
		pair<Node*, Node*> result = split(a, k - leftans);
		return make_pair(merge(pre, result.first), result.second);
	    }
	}
    }
}

int main() {
    return 0;
}
