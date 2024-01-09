#include<iostream>
using namespace std;

int mystery(int, int);

int main() {
    int x = 0; int y = 0;
    cout << "Enter two integers: " << endl; cin >> x >> y;
    cout << "The result is " << mystery(x, y) << endl;
    return 0;
}

int mystery(int a, int b) {
   if (b < 0) {
        cout << "Invalid second integer!!! Please enter a non-negative integer." << endl;
        cout << "Enter two integers: ";
        cin >> a >> b;
        
    }

    int result = 0;
    for (int i = 0; i < b; i++) {
        result += a;
    }

    return result;
}
