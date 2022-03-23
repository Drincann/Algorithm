#include <cassert>
#include "./trie.cpp"

int main() {
    insert("abc");
    insert("abcd");
    assert(perfix("a") && !search("a"));       // perfix
    assert(search("abc"));                     // complete
    assert(search("abcd"));                    // complete
    assert(!search("acd") && !perfix("acd"));  // notfound
    assert(!search("bs") && !perfix("bs"));    // nofound

    insert("aaaa");
    assert(perfix("aaa") && !search("aaa"));  // perfix
    assert(search("aaaa"));                   // complete

    del("abc");
    assert(perfix("abc") && !search("abc"));  // perfix
    assert(search("abcd"));                   // complete

    cout << "All test passed!" << endl;
    return 0;
}