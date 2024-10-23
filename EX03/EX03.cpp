#include <iostream>
#include <vector>

using namespace std;

void foo (int* bar) {
    delete bar;
    bar = nullptr;
}

void test() {
    int* array = new int[100000];
}

int main(int argc, char const *argv[]) {
    int x = 5; //puts a int on the stack
    int y = x; //y is now 5
    x = 3; //x is now 3. y is still 5
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl; //prints x and y

    int* pointer1 = &x; //pointer1 points to the adrees of x
    cout<<"x: "<<x<<endl;
    cout<<"pointer1: "<<pointer1<<endl;
    cout<<"pointer 1 points to "<<*pointer1<<endl; //prints the value of x
    //The * is called the dereference operator
    //Its job is to get the value that the pointer is pointing to
    *pointer1 = 10;
    cout<<"x: "<<x<<endl;
    cout<<"pointer1 points to "<<*pointer1<<endl; //pointer1 is 10
    int* pointer2 = pointer1; //pointer2 points to the same address as pointer1
    cout<<"x: "<<x<<"\t pointer1: "<<*pointer1<<"\t pointer2: "<<*pointer2<<endl; //All the values
    *pointer1 = 20;
    cout<<"x: "<<x<<"\t pointer1: "<<*pointer1<<"\t pointer2: "<<*pointer2<<endl; //All the values
    pointer1 = &y; //pointer1 now points to y
    cout<<"x: "<<x<<"\t pointer1: "<<*pointer1<<"\t pointer2: "<<*pointer2<<endl; //All the values


    int arraySize; //creates a variable to store the size of the array
    cout<<"Enter the size of the array: "; //asks the user for the size of the array
    cin>>arraySize; //gets the size of the array
    int *arr = new int[arraySize]; //The pointer is on the stack
    //While the actual arrau is on the heap
    for(int i = 0; i < arraySize; i++) {
        arr[i] = i; //sets the value of the array at the index to i
    }
    cout<<"3rd element of the array "<<arr[4]<< " OR "<<*(arr+4)<<endl; //prints the 3rd element of the array
    delete[] arr; //deletes the array from the heap
    arr = nullptr; //sets the pointer to NULL
    //cout<<arr[0]<<endl; //prints the first element of the array
    //This will cause a segmentation fault
    if(arr) {
        //this would pass if the pointer is not set to NULL
        //Two reasons you want to set your pointer to NULL
        //1) prevent double delete
        //2) prevent editing unkown value
    }
    int* pointer3 = new int(3); //You put the int on the heap. THe pointer on the stack
    delete pointer3;
    pointer3 = nullptr; //use nullptr

    int* pointer4 = new int(4);
    int* pointer5 = pointer4;
    delete pointer4;
    pointer4 = nullptr;
    //delete pointer5;
    pointer5 = nullptr;
    
    int* pointer6 = new int(10);
    foo(pointer6);
    cout<<*pointer6<<endl;

    return 0;
}


