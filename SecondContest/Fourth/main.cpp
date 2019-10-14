#include <iostream>
#include <vector>

unsigned int cur = 0;

unsigned int nextRand24(unsigned int firstElement, unsigned int secondElement) {
    cur = cur * firstElement + secondElement;
    return cur >> 8;
}

unsigned int nextRand32(unsigned int firstElement, unsigned int secondElement) {
    unsigned int a = nextRand24(firstElement, secondElement),
            b = nextRand24(firstElement, secondElement);
    return (a << 8) ^ b;
}

int main() {
    size_t count;
    unsigned int firstElement, secondElement;
    std::cin >> count;
    std::cin >> firstElement >> secondElement;
    std::vector<unsigned int> data;
    data.reserve(count);
    unsigned int sum = 0;
    for (size_t index = 0; index < count; ++index) {
        data.push_back(nextRand32(firstElement, secondElement));
        sum += data[index] / count;
    }
    unsigned long long int delta = 0;
    for (size_t index = 0; index < count; ++index) {
        unsigned int diffrent;
        (sum < data[index]) ? diffrent = (data[index] - sum) : diffrent = (sum - data[index]);
        delta += diffrent;
    }
    std::cout << delta << "\n";
    return 0;
}

