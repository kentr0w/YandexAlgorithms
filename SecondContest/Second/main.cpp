#include <iostream>
#include <vector>
#include <algorithm>

size_t Partition(std::vector<size_t> &data, std::vector<size_t> &data_index,
                 size_t left_range, size_t right_range) {
    size_t pivot = data[left_range];
    size_t left = left_range - 1;
    size_t right = right_range + 1;
    while (right >= 0) {
        do {
            ++left;
        } while (data[left] < pivot);

        do {
            --right;
        } while (data[right] > pivot);

        if (left >= right) {
            break;
        }
        std::swap(data[left], data[right]);
        std::swap(data_index[left], data_index[right]);
    }
    return right;
}


void Qsort(std::vector<size_t> &data, std::vector<size_t> &data_index, size_t left_range,
           size_t right_range) {
    if (left_range < right_range) {
        size_t index = Partition(data, data_index, left_range, right_range);
        Qsort(data, data_index, left_range, index);
        Qsort(data, data_index, index + 1, right_range);
    }
}


void Solve(std::vector<size_t> &data, std::vector<size_t> &data_index) {

    size_t left_range = 0, left_change = 0, right_range = 1;
    if (data.size() == 1) {
        std::cout << data[0] << "\n" << 1;
        return;
    }

    int64_t sum_avg = data[0] + data[1], sum_res = data[0] + data[1];

    for (size_t index = 2; index < data.size(); ++index) {

        while (data[left_change] + data[left_change + 1] < data[index] && left_change < index) {
            sum_avg -= data[left_change];
            ++left_change;
        }

        sum_avg += data[index];

        if (sum_avg > sum_res) {
            sum_res = sum_avg;
            left_range = left_change;
            right_range = index;
        }
    }

    Qsort(data_index, data, left_range, right_range);

    std::cout << sum_res << "\n";
    for (size_t index = left_range; index <= right_range; ++index) {
        std::cout << data_index[index] + 1 << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t count;
    std::cin >> count;
    std::vector<size_t> data(count);
    std::vector<size_t> data_index(count);
    for (size_t i = 0; i < count; ++i) {
        std::cin >> data[i];
        data_index[i] = i;
    }

    Qsort(data, data_index, 0, data.size() - 1);

    Solve(data, data_index);

    return 0;
}

