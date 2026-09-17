#include <vector>
#include <iostream>
int main() {
    std::vector<int> v(5);
    // Используем auto
    for (auto x : v)
        std::cout << x << ' ';
    return 0;
}