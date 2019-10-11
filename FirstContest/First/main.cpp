#include <iostream>
#include <vector>

bool DFS(std::vector<std::vector<int>> &dataSequence, std::vector<int> &result,
         int prevElement, int column, int delta) {
    if (result.size() == dataSequence.size())
        return true;
    for (size_t index = 0; index < dataSequence[column].size(); ++index) {
        if (delta == 1 && dataSequence[column][index] > prevElement) {
            result.push_back(dataSequence[column][index]);
            if (DFS(dataSequence, result, dataSequence[column][index], column + 1, -1))
                return true;
            else
                result.pop_back();
        }

        if (delta == -1 && dataSequence[column][index] < prevElement) {
            result.push_back(dataSequence[column][index]);
            if (DFS(dataSequence, result, dataSequence[column][index], column + 1, 1))
                return true;
            else
                result.pop_back();
        }
    }
    return false;
}

std::vector<int> Solve(std::vector<int> &data) {

    if (data.size() == 1)
        return data;

    int lastDelta, count, delta;
    lastDelta = count = 0;
    std::vector<std::vector<int>> dataSequence;
    std::vector<int> result;
    dataSequence.emplace_back();

    for (size_t index = 1; index < data.size(); ++index) {

        (data[index] == data[index - 1]) ? delta = 0 :
        (data[index] > data[index - 1]) ? delta = 1 : delta = -1;

        if (delta != 0) {
            if (delta != lastDelta) {

                dataSequence.emplace_back();
                dataSequence[count].push_back(data[index - 1]);
                ++count;
                lastDelta = delta;

            } else {
                dataSequence[count].push_back(data[index - 1]);
            }
        }
    }

    dataSequence[count].push_back(data[data.size() - 1]);

    if (dataSequence.size() == 1)
        return std::vector<int>{dataSequence[0][0]};

    for (size_t index = 0; index < dataSequence[0].size(); ++index) {
        result.push_back(dataSequence[0][index]);
        if (DFS(dataSequence, result, dataSequence[0][index], 1,
                (dataSequence[1][0] > dataSequence[0][0]) ? delta = 1 : delta = -1))
            break;
        else
            result.pop_back();
    }

    return result;
}

size_t ReadNum() {
    size_t count;
    std::cin >> count;
    return count;
}

std::vector<int> ReadData(size_t data_size) {
    std::vector<int> data;
    data.reserve(data_size);
    for (size_t index = 0; index < data_size; ++index) {
        int numb;
        std::cin >> numb;
        data.push_back(numb);
    }
    return data;
}


int main() {

    size_t arrSize;
    arrSize = ReadNum();
    std::vector<int> data = ReadData(arrSize);
    std::vector<int> result;
    result = Solve(data);
    for (int &current: result)
        std::cout << current << " ";
    std::cout << std::endl;

    return 0;
}

