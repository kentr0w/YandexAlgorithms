#include <iostream>
<<<<<<< HEAD
using namespace std;

#define N 3

// Partition using Hoare's Partitioning scheme
int Partition(int a[], int low, int high)
{
    int pivot = a[1];
    int i = low - 1;
    int j = high + 1;
    while(1)
    {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if(i >= j)
            return j;

        swap(a[i], a[j]);
    }
=======
#include <vector>
#include <istream>
#include <algorithm>

unsigned int cur = 0;

unsigned int nextRand24(unsigned long long firstElement, unsigned long long secondElement) {
    cur = static_cast<unsigned int>(cur * firstElement + secondElement);
    return cur >> 8;
>>>>>>> aef8dde39bf2607ecd84383321b6b16b22f4552c
}

// Quicksort routine
void QuickSort(int a[], int low, int high)
{
    // base condition
    if(low >= high)
        return;

<<<<<<< HEAD
    // rearrange the elements across pivot
    int pivot = Partition(a, low, high);

    std::cout<<pivot<<"\n";
    // recur on sub-array containing elements that are less than pivot
    QuickSort(a, low, pivot);

    // recur on sub-array containing elements that are more than pivot
    QuickSort(a, pivot + 1, high);
}

int main()
{
    int arr[] = {3,1,2};
    srand(time(NULL));

    // generate random input of integers

    QuickSort(arr, 0, N - 1);

    for (int i = 0 ; i < N; i++)
        cout << arr[i] << " ";

=======
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
>>>>>>> aef8dde39bf2607ecd84383321b6b16b22f4552c
    return 0;
}