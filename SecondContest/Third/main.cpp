#include <iostream>
#include <vector>
#include <algorithm>

void swap(int *firstvar, int *secondvar) {
    int temp = *firstvar;
    *firstvar = *secondvar;
    *secondvar = temp;
}

class MinHeap {
    int *array;
    int heap_size;
public:
    MinHeap(std::vector<int> data, int count);

    int parent(int index) { return (index - 1) / 2; }

    int left(int index) { return (2 * index + 1); }

    int right(int index) { return (2 * index + 2); }

    void insertKey(int key);

    void swiftDown(int current);

    int extract_min();

    ~MinHeap() {
        delete[] array;
    }
};

MinHeap::MinHeap(std::vector<int> data, int count) {
    heap_size = data.size();
    array = new int[data.size() * count + 1];
    for (int index = 0; index < heap_size; ++index) {
        array[index] = data[index];
    }

    int element = parent(heap_size - 1);
    for (int i = element; i >= 0; --i) {
        swiftDown(i);
    }
}

void MinHeap::insertKey(int key) {

    array[heap_size] = key;
    int element = heap_size;
    while (element != 0 && array[parent(element)] > array[element]) {
        swap(&array[parent(element)], &array[element]);
        element = parent(element);
    }
    ++heap_size;
}

int MinHeap::extract_min() {
    int result = array[0];
    array[0] = array[heap_size - 1];
    --heap_size;
    swiftDown(0);
    return result;
}

void MinHeap::swiftDown(int current) {
    int left_element = left(current);
    int right_element = right(current);
    int element = current;
    if (left_element < heap_size && array[current] > array[left_element])
        element = left_element;
    if (right_element < heap_size && array[element] > array[right_element])
        element = right_element;
    if (element != current) {
        swap(&array[current], &array[element]);
        swiftDown(element);
    }
}

int ReadNum() {
    int variable;
    std::cin >> variable;
    return variable;
}

int main() {

    int count_array, size_array;
    count_array = ReadNum();
    size_array = ReadNum();

    std::vector<std::vector<int>> data(count_array, std::vector<int>(size_array));
    std::vector<int> vector_first_element(count_array);
    for (int i = 0; i < count_array; ++i) {
        for (int j = 0; j < size_array; ++j) {
            std::cin >> data[i][j];
        }
        vector_first_element[i] = data[i][0];
    }

    MinHeap *pHeap = new MinHeap(vector_first_element, size_array);
    for (int i = 1; i < size_array; ++i) {
        for (int j = 0; j < count_array; ++j) {
            pHeap->insertKey(data[j][i]);
        }
    }

    for (int i = 0; i < size_array * count_array; ++i) {
        std::cout << pHeap->extract_min() << " ";
    }
    delete pHeap;
    return 0;
}

