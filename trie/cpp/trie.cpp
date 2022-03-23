#include <iostream>

using namespace std;
constexpr int LEN = 8E4;
uint8_t trie[LEN][26];
bool isEnd[LEN];
uint32_t top = 1;

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

bool search(const string& s) {
    uint32_t currNode = 1;
    for (char c : s) {
        if (!(currNode = trie[currNode][c - 'a'])) {
            return false;
        }
    }
    return isEnd[currNode];
}

bool perfix(const string& s) {
    uint32_t currNode = 1;
    for (char c : s) {
        if (!(currNode = trie[currNode][c - 'a'])) {
            return false;
        }
    }
    return true;
}