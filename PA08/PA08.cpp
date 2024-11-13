#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool isValidJavaFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    vector<char> stack;
    char ch;
    while (file.get(ch)) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push_back(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.back();
            stack.pop_back();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Error: Incorrect number of arguments." << endl;
        return 1;
    }

    string filename = argv[1];
    if (isValidJavaFile(filename)) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}