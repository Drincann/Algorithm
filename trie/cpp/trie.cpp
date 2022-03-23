#include <cstring>
#include <iostream>
using namespace std;

constexpr int MN = 8E4, M = 26;
int top, tree[MN][M];
bool isEnd[MN];

int getNext() {
    isEnd[++top] = 0;
    memset(tree[top], 0, sizeof tree[top]);
    return top;
}

void insert(const string& s) {
    int rt = 1;
    for (char c : s) {
        c -= 'a';
        if (tree[rt][c])
            rt = tree[rt][c];
        else
            rt = tree[rt][c] = getNext();
    }
    isEnd[rt] = 1;
}

int search(const string& s) {
    uint32_t node = 1;
    for (char c : s) {
        if (!(node = tree[node][c - 'a'])) {
            return node;
        }
    }
    return node;
}

void test(int node) {
    if (node != 0) {
        if (isEnd[node])
            cout << "complete" << endl;
        else
            cout << "perfix" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {
    insert("abc");
    insert("abcd");
    test(search("a"));     // perfix
    test(search("abcd"));  // complete
    test(search("acd"));   // no
    test(search("bs"));    // no

    return 0;
}