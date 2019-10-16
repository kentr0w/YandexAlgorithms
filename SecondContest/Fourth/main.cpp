#include <iostream>
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
}

// Quicksort routine
void QuickSort(int a[], int low, int high)
{
    // base condition
    if(low >= high)
        return;

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

    return 0;
}