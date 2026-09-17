#include <vector>
#include <iostream>
int main() {
    std::vector<int> v(5);
    // Новый цикл
    for (int x : v)
        std::cout << x << ' ';
    return 0;
}