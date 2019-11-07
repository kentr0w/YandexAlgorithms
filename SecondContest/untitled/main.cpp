#include <iostream>
#include <vector>
#include <algorithm>


int DFS_Right(std::vector<int> &coordinate, std::vector<int> &time, int count, int right,
              int left, int timer, int cur);

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

int DFS_Left(std::vector<int> &coordinate, std::vector<int> &time, int count,
             int right, int left, int timer, int cur) {

    if (left == -1 && count == right)
        return timer;

    int current = cur;

    if (right == count) {
        if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
            return -1;
        } else {
            return DFS_Left(coordinate, time, count, right, left - 1,
                            timer + (coordinate[current] - coordinate[left]),
                            left);
        }
    } else if (left == -1) {
        if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
            return -1;
        } else {
            return DFS_Right(coordinate, time, count, right + 1, left,
                             timer + (coordinate[right] - coordinate[current]), right);
        }
    } else if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
        return -1;
    } else {
        int dfsLeft = DFS_Left(coordinate, time, count, right, left - 1,
                               timer + (coordinate[current] - coordinate[left]), left);
        if (dfsLeft == -1) {
            if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
                return -1;
            } else {
                return DFS_Right(coordinate, time, count, right + 1, left,
                                 timer + (coordinate[right] - coordinate[current]), right);
            }
        } else {
            return dfsLeft;
        }
    }
}

int
DFS_Right(std::vector<int> &coordinate, std::vector<int> &time, int count, int right,
          int left, int timer, int cur) {

    if (right == count && left == -1)
        return timer;

    int current = cur;

    if (left == -1) {
        if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
            return -1;
        } else {
            return DFS_Right(coordinate, time, count, right + 1, left,
                             timer + (coordinate[right] - coordinate[current]), right);
        }
    } else if (right == count) {
        if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
            return -1;
        } else {
            return DFS_Left(coordinate, time, count, right, left - 1,
                            timer + (coordinate[current] - coordinate[left]),
                            left);
        }
    } else if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
        return -1;
    } else {
        int dfsRight = DFS_Right(coordinate, time, count, right + 1, left,
                                 timer + (coordinate[right] - coordinate[current]), right);
        if (dfsRight == -1) {
            if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
                return -1;
            } else {
                return DFS_Left(coordinate, time, count, right, left - 1,
                                timer + (coordinate[current] - coordinate[left]), left);
            }
        } else {
            return dfsRight;
        }
    }
}

void Solve(std::vector<int> &coordinate, std::vector<int> &time, int count) {

    bool isChange = false;

    int min_time = INT32_MAX, min_right = 0, min_left = 0;

    for (int index = 0; index < count; ++index) {

        min_right = DFS_Right(coordinate, time, count, index + 1, index - 1, 0, index);

        min_left = DFS_Left(coordinate, time, count, index + 1, index - 1, 0, index);

        if (min_right == -1) {
            if (min_left == -1) {
                continue;
            }
            else if (min_left <= min_time) {
                min_time = min_left;
                isChange = true;
            }
        } else {
            if (min_left == -1) {
                if (min_right <= min_time) {
                    min_time = min_right;
                    isChange = true;
                }
            } else {
                if (min_time >= std::min(min_right, min_left)) {
                    min_time = std::min(min_right, min_left);
                    isChange = true;
                }
            }
        }
    }
    isChange ? std::cout << min_time : std::cout << "No solution";
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