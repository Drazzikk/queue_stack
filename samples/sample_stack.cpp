#include "iostream"
#include "string"
#include "cstring"
#include "stack_queue.h"

using namespace std;

bool isValid(const std::string& s) {
    Stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.Empty()) {
                return false;
            }

            char top = st.top();
            st.pop();


            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.Empty();
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