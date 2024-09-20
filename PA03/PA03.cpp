#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void getData(ifstream& inputFile, vector<string>& lines) {
    string line; 
    
     while (getline(inputFile, line)) {
        lines.push_back(line);
    }
}
string calculateGrade(int score) {
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}
void split(const string& str, const string& delim, vector<string>& parts) {
  size_t start, end = 0;
  while (end < str.size()) {
    start = end;
    while (start < str.size() && (delim.find(str[start]) != string::npos)) {
      start++;  // skip initial whitespace
    }
    end = start;
    while (end < str.size() && (delim.find(str[end]) == string::npos)) {
      end++; // skip to end of word
    }
    if (end-start != 0) {  // just ignore zero-length strings.
      parts.push_back(string(str, start, end-start));
    }
  }
}  
void highestScore (vector<int> grades) {
    int highestScore = grades[0];
    for (unsigned int i = 0; i< grades.size(); i++) {
        if (grades[i]>highestScore) {
            highestScore = grades[i];
        }
    }
    cout<<highestScore<<endl;
}
void writeData(vector<string> lines, vector<string> grade, ofstream& outputFile) {
    for (unsigned int i = 0; i < lines.size(); i++) {
        outputFile<<lines[i]<<" "<<grade[i]<<endl;
    }
}
int main(int argc, char const *argv[]) {


if(argc != 2){
        cerr <<"Not enough arguments"<<endl;
        exit(1);
    };
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







