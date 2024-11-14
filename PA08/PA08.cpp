#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


bool isValidJavaFile(const string& filename) {
    ifstream file(filename); // Open the file
    if (!file.is_open()) { // Check if the file opened 
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    vector<char> stack; // Stack to keep track of opening characters
    char ch;
    bool inSingleLineComment = false; // Flag for single-line comments
    bool inMultiLineComment = false; // Flag for multi-line comments


    // Read the file character by character
    while (file.get(ch)) {
        if (inSingleLineComment) { // If inside a single-line comment
            if (ch == '\n') { // End of single-line comment
                inSingleLineComment = false;
            }
            continue;
        }

        if (inMultiLineComment) { // If inside a multi-line comment
            if (ch == '*' && file.peek() == '/') { // End of multi-line comment
                file.get(ch); 
                inMultiLineComment = false;
            }
            continue;
        }

        if (ch == '/') { // Possible start of a comment
            if (file.peek() == '/') { // Start of single-line comment
                inSingleLineComment = true;
                file.get(ch); 
                continue;
            } else if (file.peek() == '*') { // Start of multi-line comment
                inMultiLineComment = true;
                file.get(ch); 
                continue;
            }
        }

        

        // Push opening characters onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push_back(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') { // Check closing characters
            if (stack.empty()) { // No matching opening character
                return false;
            }
            char top = stack.back(); // Get the top of the stack
            stack.pop_back(); // Remove the top of the stack
            // Check if the closing character matches the opening character
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty, all opening characters were matched
    return stack.empty();
}

int main(int argc, char* argv[]) {
    if (argc != 2) { // Check if the correct number of arguments is provided
        cerr << "Error: Incorrect number of arguments." << endl;
        return 1;
    }

    string filename = argv[1]; // Get the filename from the command line arguments
    if (isValidJavaFile(filename)) { // Check if the file is valid
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}