#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct Result{
    int length;
    int vowelcount;
};

Result mystery3(const char*);
void reverseString(char*,int,int);
void copier(char*,const char*);

int main(){
    char string1[80];
    cout << "Enter a string: ";
    cin.getline(string1,80);
    // cin >> string1;
    cout << "Length of the string " << mystery3(string1).length << endl;
    cout << "Vowel count of the string: " << mystery3(string1).vowelcount << endl;

    char destination[20];
    copier(destination, string1);
    cout << "Copied string: " << destination << endl;

    string numericPart;
    while(true){
        cout << "String: ";
        string inputs;
        cin >> inputs;
        for(char ch: inputs){
            if(isdigit(ch)){
                numericPart += ch;
                
            }else{
                break;
            }
            
        }
        cout << "Converted to Int: " << stoi(numericPart) <<  endl;
        break;
    }
    
    reverseString(string1,0,strlen(string1) - 1);
    cout << "Reverse string: " << string1 << endl;
    return 0;
}

Result mystery3(const char* s){
    Result res;
    res.length = 0; 
    res.vowelcount = 0;
    for (res.length = 0; *s != '\0'; ++s){
        // char tolower = tolower(*s);
        char toLowerChar = tolower(static_cast<unsigned char>(*s));
        if(toLowerChar == 'a' || toLowerChar == 'e' || toLowerChar == 'i' || toLowerChar == 'o' || toLowerChar == 'u'){
            ++res.vowelcount;
        }
        
        ++res.length;
    }
    return res;
}

void reverseString(char* s,int start,int end){
    if(start < end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        reverseString(s,start + 1, end - 1);
    }
}

void copier(char* destination, const char* original) {
    
    while (*original != '\0') {
        *destination = *original;
        ++destination;
        ++original;
    }
    *destination = '\0';
} 

