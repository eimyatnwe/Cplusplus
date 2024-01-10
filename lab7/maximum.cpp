#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;

int findLargest(array<int,10> num,int index){
   
    if(index == 0){
        return num[0];
    }else{
        int remainBit = findLargest(num, index - 1);
        if(num[index] > remainBit){
            return num[index];
        }else{
            return remainBit;
        }
    }
   
}

int main(){
    array<int, 10> number;
    srand(static_cast<int>(time(NULL)));
    cout << "Generated 10 random integers between 1 and 100: \n";

    for(int i = 0; i < 10; i++){
        number[i] = (rand() % 100) + 1;
        cout << number[i] << " ";
    }
    cout << "\nThe largest element in the array is: " << findLargest(number, number.size() - 1);
    
    return 0;

}