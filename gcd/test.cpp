#undef NDEBUG
#include <cassert>
#include <iostream>
#include "./gcd.cpp"
int main() {
    assert(gcd(0, 0) == 0);
    assert(gcd(0, 1) == 1);
    assert(gcd(0, 2) == 2);
    assert(gcd(1, 1) == 1);
    assert(gcd(1, 2) == 1);
    assert(gcd(2, 2) == 2);
    assert(gcd(2, 4) == 2);
    assert(gcd(4, 2) == 2);
    assert(gcd(4, 4) == 4);

    assert(lcm(0, 0) == 0);
    assert(lcm(0, 1) == 0);
    assert(lcm(0, 2) == 0);
    assert(lcm(1, 1) == 1);
    assert(lcm(1, 2) == 2);
    assert(lcm(2, 2) == 2);
    assert(lcm(2, 4) == 4);
    assert(lcm(4, 2) == 4);
    assert(lcm(4, 4) == 4);

    std::cout << "All test passed!" << std::endl;
    return 0;
}