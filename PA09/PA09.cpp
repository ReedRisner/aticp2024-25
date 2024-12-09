#include <json.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace json;

void printUsage() {
    cout << "Usage: ./PA09 <filename> <command> [<args>]" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printUsage();
        return 1;
    }

    string filename = argv[1];
    string command = argv[2];

    // Read the JSON data from the file
    ifstream inputFile(filename);
    string fileContent;
    if (inputFile.is_open()) {
        fileContent.assign((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        inputFile.close();
    }

    JSON queue;
    if (!fileContent.empty()) {
        try {
            queue = JSON::Load(fileContent);
        } catch (const std::exception& e) {
            cerr << "Error parsing JSON data: " << e.what() << endl;
            return 1;
        }
    } else {
        queue = JSON::Make(JSON::Class::Array);
    }

    if (command == "add") {
        if (argc != 6) {
            printUsage();
            return 1;
        }

        string firstName = argv[3];
        string lastName = argv[4];
        string email = argv[5];

        // Check if the email already exists in the queue
        bool emailExists = false;
        for (int i = 0; i < queue.length(); ++i) {
            if (queue[i]["email"].ToString() == email) {
                emailExists = true;
                break;
            }
        }

        if (emailExists) {
            cout << "Person already in queue" << endl;
        } else {
            JSON newPerson = JSON::Make(JSON::Class::Object);
            newPerson["firstName"] = firstName;
            newPerson["lastName"] = lastName;
            newPerson["email"] = email;
            queue.append(newPerson);
        }
    } else if (command == "remove") {
        if (queue.length() > 0) {
            if (queue.length() == 1) {
                queue = JSON::Make(JSON::Class::Null);
            } else {
                JSON newQueue = JSON::Make(JSON::Class::Array);
                for (int i = 1; i < queue.length(); ++i) {
                    newQueue.append(queue[i]);
                }
                queue = newQueue;
            }
        }
    } else if (command == "clear") {
        queue = JSON::Make(JSON::Class::Null);
    } else {
        printUsage();
        return 1;
    }

    // Write the updated JSON data back to the file
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return 1;
    }

    outputFile << queue.dump();
    outputFile.close();

    return 0;
}


