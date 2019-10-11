#include <iostream>
#include <vector>


std::vector<int> Solve(std::vector<int>& data, std::vector<char>& data_char){
    std::vector<int> result;
    result.reserve(data_char.size());
    int maxElement = INT32_MIN;
    size_t maxIndex = 0;
    size_t left, right;
    left = 0; right = 0;
    for (char index : data_char) {
        switch (index){
            case 'R':
                ++right;
                if(data[right] > maxElement){
                    maxElement = data[right];
                    maxIndex = right;
                }
                result.push_back(maxElement);
                break;

            default:
                ++left;
                if(left > maxIndex) {
                    maxElement = INT32_MIN;
                    for (size_t jindex = left; jindex <= right; ++jindex) {
                        if (data[jindex] > maxElement) {
                            maxElement = data[jindex];
                            maxIndex = (jindex);
                        }
                    }
                }
                result.push_back(maxElement);
                break;
        }
    }
    return result;
}


std::vector<char> ReadCharVector(size_t count){
    std::vector<char> data;
    data.reserve(count);
    for(size_t index = 0; index < count; ++index){
        char var;
        std::cin>>var;
        data.push_back(var);
    }
    return data;
}

std::vector<int> ReadIntVector(size_t count){
    std::vector<int> data;
    data.reserve(count);
    for(size_t index = 0; index < count; ++index){
        int var;
        std::cin>>var;
        data.push_back(var);
    }
    return data;
}

size_t ReadNum(){
    size_t number;
    std::cin>>number;
    return number;
}

int main() {

    size_t data_size = ReadNum();
    std::vector<int> data = ReadIntVector(data_size);
    size_t count = ReadNum();
    std::vector<char> data_char = ReadCharVector(count);
    std::vector<int> result = Solve(data, data_char);
    for(int& cur : result)
        std::cout<<cur<<" ";
    std::cout<<"\n";
    return 0;
}

