#include <iostream>
using namespace std;
string reverse(string inputs,int index){
    if(index == 0){
        return string(1,inputs[index]);
    }else{
        return inputs[index] + reverse(inputs,index - 1);
    }
}
int main(){
    string original;
    cout << "Enter a string: ";
    getline(cin,original);
    
    cout << "Reversed version is: " << reverse(original,original.length() - 1);
}