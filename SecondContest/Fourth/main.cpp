#include <iostream>
#include <vector>
#include <istream>
#include <algorithm>

unsigned int cur = 0;

unsigned int nextRand24(unsigned long long firstElement, unsigned long long secondElement) {
    cur = static_cast<unsigned int>(cur * firstElement + secondElement);
    return cur >> 8;
}

unsigned int nextRand32(unsigned long long firstElement, unsigned long long secondElement) {
    unsigned int firstvar = nextRand24(firstElement, secondElement),
            secondvar = nextRand24(firstElement, secondElement);
    return (firstvar << 8) ^ secondvar;
}

size_t Partition(std::vector<unsigned int> &data, size_t leftSide, size_t rigthSide) {
    std::swap(data[leftSide], data[(data.size() / 2)]);
    size_t pivot = data[leftSide];
    size_t left = leftSide - 1, right = rigthSide + 1;
    while (right >= 0) {
        do {
            ++left;
        } while (data[left] < pivot);

        do {
            --right;
        } while (data[right] > pivot);

        if (left >= right)
            break;
        std::swap(data[left], data[right]);
    }
    return right;
}

void Qselect(std::vector<unsigned int> &data, size_t leftSide, size_t rigthSide) {
    if (rigthSide <= leftSide)
        return;

    size_t order = Partition(data, leftSide, rigthSide);

    if (order >= (data.size() / 2)) {
        Qselect(data, leftSide, order);
    } else {
        Qselect(data, order + 1, rigthSide);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t count;
    unsigned long long firstElement, secondElement;

    std::cin >> count;
    std::cin >> firstElement >> secondElement;

    std::vector<unsigned int> data;
    data.reserve(count);

    for (size_t index = 0; index < count; ++index) {
        data.push_back(nextRand32(firstElement, secondElement));
    }

    Qselect(data, 0, data.size() - 1);
    unsigned int middleElement = data[(data.size() / 2)];

    unsigned long long sum = 0;

    for (size_t index = 0; index < count; ++index) {
        (data[index] > middleElement) ? sum += (data[index] - middleElement) :
                sum += (middleElement - data[index]);
    }
    std::cout << sum << "\n";
    return 0;
}

