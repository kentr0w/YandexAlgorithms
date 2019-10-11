#include <iostream>
#include <vector>
#include <algorithm>


int a;
int b;

unsigned int cur = 0; // беззнаковое 32-битное число
unsigned int nextRand24() {
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8; // число от 0 до 2**24-1.
}
unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8)^b; // число от 0 до 2**32-1.
}



int main() {
    std::vector<unsigned int> data(6);
    a = 239;
    b = 13;
    long int sum = 0;
    long int res = 0;
    for (int i = 0; i < 6; ++i) {
        data[i] = nextRand32();
        sum+=data[i]/6;
        std::cout<<data[i]<<" ========== " << sum<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    for (int i = 0; i < 6; ++i) {
        res += std::abs(data[i] - sum);
        std::cout<<data[i]<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<sum<<std::endl;
    return 0;
}