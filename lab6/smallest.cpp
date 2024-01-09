#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int num;
    int smallest;
    
    do {
        cout << "Enter the number of integers: ";
        cin >> n;

        if (n <= 0) {
            cout << "Please enter a positive number.\n";
        }
    } while (n <= 0);
   
    cout << "Enter integers: ";
    for (int i = 0; i < n; i++){
        cin >> num;
        if(num < smallest){
            smallest = num;
        }
    }

    cout << "Smallest integer is: " << smallest;
    return 0;
}