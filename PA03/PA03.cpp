#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {

    if(argc == 1){
        cerr <<"Only One Argument"<<endl;
        exit(1);
    } 

    string fileName = argv[1];
    ifstream infile (fileName);
    string line;
    
    if (infile.good() == false) {
        cerr << "Unable to open the file named " << fileName;
        exit (1);
    }

}