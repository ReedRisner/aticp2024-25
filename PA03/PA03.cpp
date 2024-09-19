#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

int main(int argc, char const *argv[]) {

struct Student {
    string firstname;
    string lastname;
    int score;
    char grade;
};

vector<student>;

    if(argc != 3){
        cerr <<"Not enough arguments"<<endl;
        exit(1);
    } 

    string inputName = argv[1];
    string outputName = argv[2];
    ifstream infile (inputName);
    ofstream outfile (outputName);
    string line;
    
    if (infile.good() == false || outfile.good() == false) {
        cerr << "Unable to open the file named " << inputName;
        exit (1);
    }





}