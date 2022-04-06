constexpr int n = 5001;
int father[n];

int find(int x) {
    while (x != father[x]) {
        x = father[x] = father[father[x]];
    }
    return x;
}

int findRecurve(int x) {
    if (x != father[x]) {
        int root = findRecurve(father[x]);
        return father[x] = root;
    }
    return x;
}

void merge(int l, int r) {
    int lf = find(l);
    int rf = find(r);
    if (lf != rf) {
        father[lf] = father[rf];
    }
}

void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}
