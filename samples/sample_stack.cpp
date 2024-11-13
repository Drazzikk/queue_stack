#include "stack_queue.h"
#include <iostream>
#include <string>
#include "cstring"
using namespace std;
using std::cin;
using std::cout;
using std::string;

char invertBrackets(char ch)
{
	if (ch == '(') return ')';
	else if (ch == '[') return ']';
	else if (ch == '{') return '}';
	return ' ';
}

bool isValid(const std::string& s) {
    Stack<char> stack;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.Empty()) {
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

    return stack.Empty();
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