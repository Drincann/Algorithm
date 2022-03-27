#include <iostream>
#include <vector>
int binarySearch(std::vector<int> arr, int target) {
    int l = 0, r = arr.size() - 1;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l /* or r */;
}

int main() {
    std::vector<int> arr{1, 2, 6, 7, 22, 44};
    std::cout << binarySearch(arr, 22);
    return 0;
}