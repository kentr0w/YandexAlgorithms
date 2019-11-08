#include <iostream>
#include <vector>
<<<<<<< HEAD

size_t partiotion(std::vector<int>& data, std::vector<int>& data_index, size_t l, size_t r){
    int pivot = data[l];
    size_t i = l - 1;
    size_t j = r + 1;
    while (j>=0){
        do{
            ++i;
        }while(data[i] < pivot);

        do{
            --j;
        }while(data[j] > pivot);

        if(i >= j)
            break;
        std::swap(data[i], data[j]);
        std::swap(data_index[i], data_index[j]);
    }
    return j;
}


void Qsort(std::vector<int>& data, std::vector<int>& data_index, size_t l, size_t r){
    if(l<r){
        size_t pi = partiotion(data, data_index, l, r);
        Qsort(data, data_index, l ,pi);
        Qsort(data, data_index, pi+1, r);
=======
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
>>>>>>> e62235464ec47ebaef57218bdf9a1b6dfb0a48ba
    }
}


<<<<<<< HEAD
void Solve(std::vector<int>& data, std::vector<int>& data_index){
    std::vector<int> result;
    std::vector<int> result_index;

    size_t L = 0,l = 0;
    int max=0, MAX = 0;
    int count = 0;

    result.push_back(data[0]);
    result_index.push_back(data_index[0]);

    if(data.size()==1){
        for(size_t i=0; i < result_index.size(); ++i) {
            max+=result[i];
        }
        std::cout<<max;
        return;
    }

    result.push_back(data[1]);
    result_index.push_back(data_index[1]);

    MAX = data[0] + data[1];
    max = MAX;

    for(int i=2; i< data.size(); ++i){

        while (result[l] + result[l + 1] < data[i] && l < result.size() - 1) {
            max -= result[l];
            ++l;
        }

        if ((max + data[i]) >= MAX) {
            MAX = max + data[i];
            L = l;
            for(int j=i - count; j<=i; ++j) {
                result.push_back(data[j]);
            }
            count = 0;
        }
        else
            ++count;
        max+=data[i];
    }

    //Qsort(result_index, result, L, result_index.size()-1);

    int q= 0;
    for(size_t i = L; i < result.size() ; ++i) {
        q+=result[i];
        //std::cout << result[i] << " ";
    }
    std::cout<<q;
}


int main() {
    size_t n;
    std::cin>>n;
    if(n==0)
        return 0;
    std::vector<int> data(n);
    std::vector<int>data_index(n);
    for(int i=0; i<n; ++i) {
        std::cin >> data[i];
        data_index[i] =i;
    }

    Qsort(data, data_index, 0, data.size()-1);
=======
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
>>>>>>> e62235464ec47ebaef57218bdf9a1b6dfb0a48ba

    Solve(data, data_index);

    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> e62235464ec47ebaef57218bdf9a1b6dfb0a48ba
