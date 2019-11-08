#include <iostream>
#include <vector>
#include <algorithm>


int DFS_Right(std::vector<int>& coordinate, std::vector<int>& time, int count,  int right, int left,  int timer);

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

int DFS_Left(std::vector<int>& coordinate, std::vector<int>& time, int count,  int right, int left,  int timer) {

    if(left == -1 && count == right)
        return timer;

    int current = left + 1;

    if(left == -1){
        if((timer + (coordinate[right] - coordinate[current])) > time[right]) {
            return -1;
        }
        else{
            //timer += (coordinate[right] - coordinate[current]);
            return DFS_Right(coordinate, time, count, right + 1, left, timer + (coordinate[right] - coordinate[current]));
        }
    }
    else if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
        return -1;
    }
    else{
        //timer+=(coordinate[current] - coordinate[left]);
        int x = DFS_Left(coordinate, time, count, right, left - 1, timer + (coordinate[right] - coordinate[current]));
        if(x == -1) {
            //timer -= (coordinate[current] - coordinate[left]);
            return DFS_Right(coordinate, time, count, right, left, timer);
        }
        else
            return x;
    }

}

int DFS_Right(std::vector<int>& coordinate, std::vector<int>& time, int count,  int right, int left,  int timer){

    if(right == count && left == -1)
        return timer;

    int current = right - 1;

    if(right == count) {
        if((timer + (coordinate[current] - coordinate[left])) > time[left]) {
            return -1;
        }
        else{#include <iostream>
#include <vector>
#include <algorithm>


            int DFS_Right(std::vector<int>& coordinate, std::vector<int>& time, int count,  int right, int left,  int timer);

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

            int DFS_Left(std::vector<int>& coordinate, std::vector<int>& time, int count,  int right, int left,  int timer) {

                if(left == -1 && count == right)
                    return timer;

                int current = left + 1;

                if(left == -1){
                    if((timer + (coordinate[right] - coordinate[current])) > time[right]) {
                        return -1;
                    }
                    else{
                        //timer += (coordinate[right] - coordinate[current]);
                        return DFS_Right(coordinate, time, count, right + 1, left, timer + (coordinate[right] - coordinate[current]));
                    }
                }
                else if ((timer + (coordinate[current] - coordinate[left])) > time[left]) {
                    return -1;
                }
                else{
                    //timer+=(coordinate[current] - coordinate[left]);
                    int x = DFS_Left(coordinate, time, count, right, left - 1, timer + (coordinate[right] - coordinate[current]));
                    if(x == -1) {
                        //timer -= (coordinate[current] - coordinate[left]);
                        return DFS_Right(coordinate, time, count, right, left, timer);
                    }
                    else
                        return x;
                }

            }

            int DFS_Right(std::vector<int>& coordinate, std::vector<int>& time, int count,  int right, int left,  int timer){

                if(right == count && left == -1)
                    return timer;

                int current = right - 1;

                if(right == count) {
                    if((timer + (coordinate[current] - coordinate[left])) > time[left]) {
                        return -1;
                    }
                    else{
                        //timer += (coordinate[current] - coordinate[left]);
                        return DFS_Left(coordinate, time, count, right, left - 1, timer + (coordinate[current] - coordinate[left]));
                    }
                }
                else if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
                    return -1;
                }
                else{
                    //timer+=(coordinate[right] - coordinate[current]);
                    int x =DFS_Right(coordinate, time, count, right + 1, left, timer + (coordinate[right] - coordinate[current]));
                    if(x == -1) {
                        //timer -= (coordinate[right] - coordinate[current]);
                        return DFS_Left(coordinate, time, count, right, left, timer);
                    }
                    else
                        return x;
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

            int couny_by_distance(std::vector<int> &coordinate, std::vector<int> &time, int count, int cur) {

                int left = cur - 1;
                int right = cur + 1;
                int current = cur;
                int timer = 0;
                bool isOk = true;
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
                } while (current <= count);

                if (isOk)
                    return timer;
                else
                    return -1;
            }


            int count_by_time(std::vector<int> coordinate, std::vector<int> &time, int count, int cur) {

                int left = cur - 1;
                int right = cur + 1;
                int current = cur;
                bool isOk = true;
                int timer = 0;

                do {
                    if (left < 0) {
                        if (right >= count) {
                            break;
                        } else {
                            if ((time[right] - timer) < (coordinate[right] - coordinate[current])) {
                                isOk = false;
                                break;
                            } else {
                                timer += (coordinate[right] - coordinate[current]);
                                current = right;
                                ++right;
                            }
                        }
                    } else if (right >= count) {
                        if (left < 0) {
                            break;
                        } else {
                            if ((time[left] - timer) < (coordinate[current] - coordinate[left])) {
                                isOk = false;
                                break;
                            } else {
                                timer += (coordinate[current] - coordinate[left]);
                                current = left;
                                --left;
                            }
                        }
                    } else if (time[left] < time[right]) {
                        if ((time[left] - timer) < (coordinate[current] - coordinate[left])) {
                            isOk = false;
                            break;
                        } else {
                            timer += (coordinate[current] - coordinate[left]);
                            current = left;
                            --left;
                        }
                    } else {
                        if ((time[right] - timer) < (coordinate[right] - coordinate[current])) {
                            isOk = false;
                            break;
                        } else {
                            timer += (coordinate[right] - coordinate[current]);
                            current = right;
                            ++right;
                        }
                    }
                } while (current <= count);

                if (isOk)
                    return timer;
                else
                    return -1;
            }


            void Solve(std::vector<int> &coordinate, std::vector<int> &time, int count) {

                bool isChange = false;

                int min_time = INT32_MAX, min_1 = 0, min_2 = 0;

                int timer;

                for (int index = 0; index < count; ++index) {

                    timer = 0;

                    min_1 = DFS_Right(coordinate, time, count, index + 1, index - 1, 0);

                    timer = 0;

                    min_2 = DFS_Left(coordinate, time, count, index + 1, index - 1, 0);


                    std::cout<<index<<" min1 = "<< min_1<<" min2 = " << min_2<<"\n";

                    if (min_1 == -1) {
                        if (min_2 == -1)
                            continue;
                        else if (min_2 <= min_time) {
                            min_time = min_2;
                            isChange = true;
                        }
                    } else {
                        if (min_2 == -1) {
                            if (min_1 <= min_time) {
                                min_time = min_1;
                                isChange = true;
                            }
                        } else {
                            if (min_time >= std::min(min_1, min_2)) {
                                min_time = std::min(min_1, min_2);
                                isChange = true;
                            }
                        }
                    }

                    /*min_time_by_distance = couny_by_distance(coordinate, time, count, index);
                    min_time_by_time = count_by_time(coordinate, time, count, index);

                    if (min_time_by_distance == -1) {
                        if (min_time_by_time == -1)
                            continue;
                        else if (min_time_by_time <= min_time) {
                            min_time = min_time_by_time;
                            isChange = true;
                        }
                    } else {
                        if (min_time_by_time == -1) {
                            if (min_time_by_distance <= min_time) {
                                min_time = min_time_by_distance;
                                isChange = true;
                            }
                        } else {
                            if (min_time >= std::min(min_time_by_distance, min_time_by_time)) {
                                min_time = std::min(min_time_by_distance, min_time_by_time);
                                isChange = true;
                            }
                        }
                    }*/
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



            //timer += (coordinate[current] - coordinate[left]);
            return DFS_Left(coordinate, time, count, right, left - 1, timer + (coordinate[current] - coordinate[left]));
        }
    }
    else if ((timer + (coordinate[right] - coordinate[current])) > time[right]) {
        return -1;
    }
    else{
        //timer+=(coordinate[right] - coordinate[current]);
        int x =DFS_Right(coordinate, time, count, right + 1, left, timer + (coordinate[right] - coordinate[current]));
        if(x == -1) {
            //timer -= (coordinate[right] - coordinate[current]);
            return DFS_Left(coordinate, time, count, right, left, timer);
        }
        else
            return x;
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

int couny_by_distance(std::vector<int> &coordinate, std::vector<int> &time, int count, int cur) {

    int left = cur - 1;
    int right = cur + 1;
    int current = cur;
    int timer = 0;
    bool isOk = true;
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
    } while (current <= count);

    if (isOk)
        return timer;
    else
        return -1;
}


int count_by_time(std::vector<int> coordinate, std::vector<int> &time, int count, int cur) {

    int left = cur - 1;
    int right = cur + 1;
    int current = cur;
    bool isOk = true;
    int timer = 0;

    do {
        if (left < 0) {
            if (right >= count) {
                break;
            } else {
                if ((time[right] - timer) < (coordinate[right] - coordinate[current])) {
                    isOk = false;
                    break;
                } else {
                    timer += (coordinate[right] - coordinate[current]);
                    current = right;
                    ++right;
                }
            }
        } else if (right >= count) {
            if (left < 0) {
                break;
            } else {
                if ((time[left] - timer) < (coordinate[current] - coordinate[left])) {
                    isOk = false;
                    break;
                } else {
                    timer += (coordinate[current] - coordinate[left]);
                    current = left;
                    --left;
                }
            }
        } else if (time[left] < time[right]) {
            if ((time[left] - timer) < (coordinate[current] - coordinate[left])) {
                isOk = false;
                break;
            } else {
                timer += (coordinate[current] - coordinate[left]);
                current = left;
                --left;
            }
        } else {
            if ((time[right] - timer) < (coordinate[right] - coordinate[current])) {
                isOk = false;
                break;
            } else {
                timer += (coordinate[right] - coordinate[current]);
                current = right;
                ++right;
            }
        }
    } while (current <= count);

    if (isOk)
        return timer;
    else
        return -1;
}


void Solve(std::vector<int> &coordinate, std::vector<int> &time, int count) {

    bool isChange = false;

    int min_time = INT32_MAX, min_1 = 0, min_2 = 0;

    int timer;

    for (int index = 0; index < count; ++index) {

        timer = 0;

        min_1 = DFS_Right(coordinate, time, count, index + 1, index - 1, 0);

        timer = 0;

        min_2 = DFS_Left(coordinate, time, count, index + 1, index - 1, 0);


        std::cout<<index<<" min1 = "<< min_1<<" min2 = " << min_2<<"\n";

        if (min_1 == -1) {
            if (min_2 == -1)
                continue;
            else if (min_2 <= min_time) {
                min_time = min_2;
                isChange = true;
            }
        } else {
            if (min_2 == -1) {
                if (min_1 <= min_time) {
                    min_time = min_1;
                    isChange = true;
                }
            } else {
                if (min_time >= std::min(min_1, min_2)) {
                    min_time = std::min(min_1, min_2);
                    isChange = true;
                }
            }
        }

        /*min_time_by_distance = couny_by_distance(coordinate, time, count, index);
        min_time_by_time = count_by_time(coordinate, time, count, index);

        if (min_time_by_distance == -1) {
            if (min_time_by_time == -1)
                continue;
            else if (min_time_by_time <= min_time) {
                min_time = min_time_by_time;
                isChange = true;
            }
        } else {
            if (min_time_by_time == -1) {
                if (min_time_by_distance <= min_time) {
                    min_time = min_time_by_distance;
                    isChange = true;
                }
            } else {
                if (min_time >= std::min(min_time_by_distance, min_time_by_time)) {
                    min_time = std::min(min_time_by_distance, min_time_by_time);
                    isChange = true;
                }
            }
        }*/
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


