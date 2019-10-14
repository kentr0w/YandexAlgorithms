#include <iostream>
#include <vector>

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


size_t Partition(std::vector<unsigned int>& data, size_t leftSide, size_t rigthSide) {
    size_t middle = (data.size() / 2);
    std::swap(data[middle], data[rigthSide]);
    size_t left = leftSide, right = rigthSide;
    while (left <= right) {
        while (data[left] < data[middle] && left <= right) {
            ++left;
        }

        while (data[right] > data[middle] && left <= right) {
            --right;
        }
        if(left <= right) {
            std::swap(data[left], data[right]);
            ++left;
            --right;
        }
    }
    return right;
}

int Qselect(std::vector<unsigned int> &data, size_t leftSide, size_t rigthSide){
    if(rigthSide - leftSide == 0)
        return data[rigthSide];
    size_t order = Partition(data, leftSide, rigthSide);
    if( order < data.size()/2){
        return Qselect(data, order, rigthSide);
    }
    else if(order > data.size()/2){
        return Qselect(data, leftSide, order);
    }
    else
        return data[order];
}




int main() {
    /*std::ios_base::sync_with_stdio(false);
    size_t count;
    unsigned long long firstElement, secondElement;
    std::cin >> count;
    std::cin >> firstElement >> secondElement;
    std::vector<unsigned int> data;
    data.reserve(count);
    for (size_t index = 0; index < count; ++index) {
        data.push_back(nextRand32(firstElement, secondElement));
    }*/
    //{2,1,7,3,3};
    //{1,1,1,1};
    std::vector<unsigned int> data = {1,1,1,1};
    std::cout<<Qselect(data, 0, data.size()-1);
    return 0;
}

