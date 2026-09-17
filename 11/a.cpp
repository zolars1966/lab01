#include <iostream>

int factorial(int n){
    if (n < 0) return -1;
    if (n == 0) return 1;

    return n * factorial(n - 1);
}

int main() {
    int s = 0;
    
    for (int i = 1; i <= 100; i++) {
        s += i;
    }
    
    std::cout << s << std::endl;

    return 0;
}