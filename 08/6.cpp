#include <vector>
#include <iostream>
int main() {
    // Вывод типа шаблона из конструктора (Class Template Argument Deduction)
    std::vector v = {1,2,3,4,5};
    for (int i=0; i<5; i++)
        std::cout << v[i] << ' ';
    return 0;
}