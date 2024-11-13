#include "iostream"
#include "string"
#include "cstring"

using namespace std;

bool isValid(const std::string& s) {
    Stack<char> stack;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();


            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    string input;

    cout << "Enter: ";
    getline(std::cin, input);

    if (isValid(input)) {
        cout << "All is okay." << std::endl;
    }
    else {
        cout << "Not okay" << std::endl;
    }

    return 0;
}