#include <iostream>
#include <vector>

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
    }
}


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

    Solve(data, data_index);

    return 0;
}
