#include <iostream>
#include <vector>
using namespace std;

void lshift(vector<int>& vec, int num) {
    vec.erase(vec.begin(), vec.begin() +num);
}

void rshift(vector<int>& vec, int num) {
    vec.insert(vec.begin(), num, 0);
}

int main() {
    vector<int> myvec;
    myvec.push_back(1);
    myvec.push_back(2);
    myvec.push_back(3);
    myvec.push_back(4);

    lshift(myvec, 2);
    cout << "Left shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;

    rshift(myvec, 3);
    cout << "Right shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}