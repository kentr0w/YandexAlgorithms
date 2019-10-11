#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::stack<char> stack;
    std::string str;
    std::cin >> str;
    size_t index = 0;
    bool IsOk = true;
    for (char &i : str) {
        if (IsOk) {
            switch (i) {
                case '(':
                case '{':
                case '[': {
                    stack.push(i);
                    index++;
                    break;
                }
                case '}': {
                    stack.top() == '{' ? index++ : IsOk = false;
                    stack.pop();
                    break;
                }
                case ']': {
                    stack.top() == '[' ? index++ : IsOk = false;
                    stack.pop();
                    break;
                }
                case ')': {
                    stack.top() == '(' ? index++ : IsOk = false;
                    stack.pop();
                    break;
                }
                default:
                    break;
            }
        } else {
            break;
        }
    }
    IsOk && stack.empty() ? std::cout << "CORRECT" << std::endl : std::cout << index << std::endl;
}
