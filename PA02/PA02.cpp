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

 int zero = 0;
 int one = 0;
 int two = 0;
 int three = 0;
 int four = 0;
 int five = 0;
 int six = 0;
 int seven = 0;
 int eight = 0;
 int nine = 0;


 while (true) {
   getline (infile, line);
   int x = stoi(line);
  
   for(int i = 0; i < 10; i++) { 
    if (x == i) {
      if (i == 0){
        zero++;
      }
        else if (i == 1) {
        one++;
       }
          else if (i == 2) {
        two++;
      }
          else if (i == 3) {
        three++;
      }
           else if (i == 4) {
        four++;
      }
            else if (i == 5) {
        five++;
      }
              else if (i == 6) {
        six++;
      }
                else if (i == 7) {
        seven++;
      }
                  else if (i == 8) {
        eight++;
      }
                    else if (i == 9) {
        nine++;
      }
    }
     
}
if (infile.eof()) {
     break;
   } 
}
cout<<"0 "<<zero<<endl;
cout<<"1 "<<one<<endl;
cout<<"2 "<<two<<endl;
cout<<"3 "<<three<<endl;
cout<<"4 "<<four<<endl;
cout<<"5 "<<five<<endl;
cout<<"6 "<<six<<endl;
cout<<"7 "<<seven<<endl;
cout<<"8 "<<eight<<endl;
cout<<"9 "<<nine<<endl;


}

