#include <iostream>
#include <vector>
using namespace std;

char patternCheck(char ch, vector<vector<char>> charVector) {
    int count = 0;
    int horCount = 0, verCount = 0, diag1Count = 0, diag2Count = 0;
    char pattern = 'n'; // Default pattern is none
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (charVector[i][j] == ch) {
                count++;
                if (i == j) diag1Count++;
                if (i + j == 3) diag2Count++;
                if (i == 0) horCount++;
                if (j == 0) verCount++;
            }
        }
    }
    
    if (count != 4) return 'n'; // If the character appears more than 4 times, return 'n'

    switch (horCount) {
        case 4:
            pattern = '-';
            break;
        default:
            switch (verCount) {
                case 4:
                    pattern = '|';
                    break;
                default:
                    switch (diag1Count) {
                        case 4:
                            pattern = '\\';
                            break;
                        default:
                            switch (diag2Count) {
                                case 4:
                                    pattern = '/';
                                    break;
                            }
                    }
            }
    }
    
    return pattern;
}

int main() {
    vector<vector<char>> charVector(4, vector<char>(4));
    char ch;
    
    // Input the 4x4 vector of characters
    cout << "Enter the 4x4 vector of characters:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> charVector[i][j];
        }
    }
    
    // Input the character to search for
    cout << "Enter a character to search for: ";
    cin >> ch;
    
    char result = patternCheck(ch, charVector);
    cout << result << endl;
    
    return 0;
}
