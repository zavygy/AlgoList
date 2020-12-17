#include <iostream>
#include <algorithm>

using namespace std;
typedef struct item *pitem;

struct item {
    int prior, value, cnt;
    bool rev;
    pitem l, r;

    item(int prior, int value) : prior(prior), value(value), cnt(1), l(nullptr), r(nullptr), rev(0) {};
};

int cnt(pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap(it->l, it->r);
        if (it->l) it->l->rev ^= true;
        if (it->r) it->r->rev ^= true;
    }
}

void merge(pitem &t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
    if (!t)
        return void(l = r = 0);
    int cur_key = add + cnt(t->l); //implicit key
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    upd_cnt(t);
}

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void output(pitem t) {
    if (!t) return;
    output(t->l);
    printf("%d ", t->value);
    output(t->r);
}

void insert(pitem &root, pitem it, int pos) {
    pitem t1, t2;
    split(root, t1, t2, pos - 1);
    merge(t1, t1, it);
    merge(root, t1, t2);
    upd_cnt(root);
}

int main() {

    return 0;
}