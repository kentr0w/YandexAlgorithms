#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>

size_t Solve(std::vector<int> &data_incr, std::vector<int> &data_decr) {

    size_t left = 0;
    size_t right = data_decr.size() - 1;
    size_t middle = right / 2;

    while (left < right) {
        if (data_incr[middle] == data_decr[middle])
            return middle;
        if (data_incr[middle] < data_decr[middle]) {
            left = middle;
            middle = (left + right) / 2;
            if (right - left < 2) {
                if (std::max(data_incr[left], data_decr[left])
                    > std::max(data_incr[right], data_decr[right]))
                    return right;
                else
                    return middle;
            }
        } else {
            right = middle;
            middle = (left + right) / 2;
        }
    }
    return middle;
}

std::vector<std::vector<int>> ReadArray(size_t quantity, size_t array_size) {
    std::vector<std::vector<int>> data;
    data.resize(quantity);
    for (std::vector<int> &cur: data) {
        cur.resize(array_size);
        for (int &current: cur)
            std::cin >> current;
    }
    return data;
}

size_t ReadNum() {
    size_t count;
    std::cin >> count;
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t count_increasing_data, count_decreasing_data, size_data, count_request;
    count_increasing_data = ReadNum();
    count_decreasing_data = ReadNum();
    size_data = ReadNum();
    std::vector<std::vector<int>> data_inc = ReadArray(count_increasing_data, size_data);
    std::vector<std::vector<int>> data_dec = ReadArray(count_decreasing_data, size_data);
    count_request = ReadNum();
    std::vector<std::pair<int, int>> request_data;
    request_data.reserve(count_request);
    for (size_t k = 0; k < count_request; ++k) {
        size_t num_inc = ReadNum();
        size_t num_dec = ReadNum();
        request_data.emplace_back(num_inc, num_dec);
    }
    for (size_t index = 0; index < count_request; ++index) {
        std::cout << Solve(data_inc[request_data[index].first - 1],
                           data_dec[request_data[index].second - 1]) + 1 << "\n";
    }
    return 0;
}
