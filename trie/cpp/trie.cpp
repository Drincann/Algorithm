#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
constexpr int LEN = 8E4;
uint8_t trie[LEN][26];
bool isEnd[LEN];
uint32_t top = 0;

void insert(const string& s) {
    uint32_t currNode = 1;
    for (char c : s) {
        if (!(trie[currNode][c - 'a'])) {
            currNode = trie[currNode][c - 'a'] = ++top;
        } else {
            currNode = trie[currNode][c - 'a'];
        }
    }
    isEnd[currNode] = true;
}

void del(const string& s) {
    uint32_t currNode = 1;

    for (char c : s) {
        if (!(currNode = trie[currNode][c - 'a'])) {
            return;
        }
    }
    isEnd[currNode] = false;
}

uint32_t search(const string& s) {
    uint32_t currNode = 1;
    for (char c : s) {
        if (!(currNode = trie[currNode][c - 'a'])) {
            return 0;
        }
    }
    return currNode;
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
    test(search("abc"));   // complete
    test(search("abcd"));  // complete
    test(search("acd"));   // no
    test(search("bs"));    // no

    del("abc");
    test(search("abc"));   // perfix
    test(search("abcd"));  // complete

    return 0;
}