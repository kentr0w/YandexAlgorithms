#include <iostream>
#include <vector>
#include <algorithm>

size_t Partition(std::vector<int> &data, std::vector<int> &data_index,
                 int left_range, int right_range) {
    int pivot = data[left_range];
    int left = left_range - 1;
    int right = right_range + 1;
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

void Qsort(std::vector<int> &data, std::vector<int> &data_index,
           size_t left_range, size_t right_range) {
    if (left_range < right_range) {
        int index = Partition(data, data_index, left_range, right_range);
        Qsort(data, data_index, left_range, index);
        Qsort(data, data_index, index + 1, right_range);
    }
}


int ChooseBetweenTreePoint(int x_left, int x_current, int x_right, int t_left,
                           int t_right, int current_time) {

    if ((current_time + (x_current - x_left)) > t_left)
        return -1;
    if ((current_time + (x_right - x_current)) > t_right)
        return -1;

    if ((x_right - x_current) < (x_current - x_left)) {
        if ((current_time + (x_right - x_current) + (x_right - x_left)) <= t_left)
            return x_right;
        else
            return x_left;
    } else {
        if ((current_time + (x_current - x_left) + (x_right - x_left)) <= t_right)
            return x_left;
        else
            return x_right;
    }
}

void Solve(std::vector<int> &coordinate, std::vector<int> &time, int count) {

    int left, right, timer, current;

    bool isOk, isChange = false;

    int minTime = INT32_MAX;

    for (int index = 0; index < count; ++index) {

        isOk = true;
        timer = 0;
        current = index;
        left = index - 1;
        right = index + 1;
        do {
            if (left < 0) {
                if (right >= count) {
                    break;
                }
                if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
                    isOk = false;
                    break;
                }
                timer += (coordinate[right] - coordinate[current]);
                current = right;
                ++right;
            } else if (right >= count) {
                if (left < 0) {
                    break;
                }
                if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
                    isOk = false;
                    break;
                }
                timer += (coordinate[current] - coordinate[left]);
                current = left;
                --left;
            } else {
                int betweenTreePoint = ChooseBetweenTreePoint(coordinate[left],
                                                              coordinate[current],
                                                              coordinate[right],
                                                              time[left],
                                                              time[right],
                                                              timer);
                if (betweenTreePoint == -1) {
                    isOk = false;
                    break;
                }
                if (betweenTreePoint == coordinate[left]) {
                    timer += (coordinate[current] - coordinate[left]);
                    current = left;
                    --left;
                } else {
                    timer += (coordinate[right] - coordinate[current]);
                    current = right;
                    ++right;
                }
            }
        } while (left >= 0 || right < count);

        if (isOk && minTime > timer) {
            minTime = timer;
            isChange = true;
        }
    }
    isChange ? std::cout << minTime : std::cout << "No solution";
}

int main() {
    int count;
    std::cin >> count;
    std::vector<int> coordinate;
    std::vector<int> times;
    coordinate.resize(count);
    times.resize(count);

    for (size_t index = 0; index < coordinate.size(); ++index) {

        std::cin >> coordinate[index];
        std::cin >> times[index];
    }

    Qsort(coordinate, times, 0, coordinate.size() - 1);

    Solve(coordinate, times, count);

    return 0;
}