#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> Solve(std::vector<int> &data, std::vector<char> &data_char) {

    std::vector<int> result;

    std::stack<int> leftStack;
    std::stack<int> rightStack;
    std::stack<int> maxLeftStack;
    std::stack<int> maxRightStack;

    size_t index;
    index = 1;

    rightStack.push(data[0]);
    maxRightStack.push(data[0]);

    for (char swift: data_char) {
        if (swift == 'R') {
            rightStack.push(data[index]);

            if (maxRightStack.empty()) {
                maxRightStack.push(data[index]);
            } else {

                if (data[index] > maxRightStack.top())
                    maxRightStack.push(data[index]);
                else
                    maxRightStack.push(maxRightStack.top());
            }
            ++index;
        } else {
            if (leftStack.empty()) {

                leftStack.push(rightStack.top());
                maxLeftStack.push(rightStack.top());

                rightStack.pop();
                maxRightStack.pop();

                while (!rightStack.empty()) {
                    leftStack.push(rightStack.top());

                    if (rightStack.top() > maxLeftStack.top())
                        maxLeftStack.push(rightStack.top());
                    else
                        maxLeftStack.push(maxLeftStack.top());

                    rightStack.pop();
                    maxRightStack.pop();
                }
            }
            leftStack.pop();
            maxLeftStack.pop();
        }

        if (maxLeftStack.empty())
            result.push_back(maxRightStack.top());
        else if (maxRightStack.empty())
            result.push_back(maxLeftStack.top());
        else
            result.push_back(std::max(maxRightStack.top(), maxLeftStack.top()));
    }

    return result;
}

std::vector<char> ReadCharVector(size_t count) {
    std::vector<char> data;
    data.reserve(count);
    for (size_t index = 0; index < count; ++index) {
        char var;
        std::cin >> var;
        data.push_back(var);
    }
    return data;
}

std::vector<int> ReadIntVector(size_t count) {
    std::vector<int> data;
    data.reserve(count);
    for (size_t index = 0; index < count; ++index) {
        int var;
        std::cin >> var;
        data.push_back(var);
    }
    return data;
}

size_t ReadNum() {
    size_t number;
    std::cin >> number;
    return number;
}

int main() {

    size_t data_size = ReadNum();
    std::vector<int> data = ReadIntVector(data_size);
    size_t count = ReadNum();
    std::vector<char> data_char = ReadCharVector(count);
    std::vector<int> result = Solve(data, data_char);
    for (int &cur : result)
        std::cout << cur << " ";
    return 0;
}

