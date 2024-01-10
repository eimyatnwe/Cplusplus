#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

array<string,5> dishes = {"Pad Thai","Som Tam","Mango Sticky Rice","Tom Yum Goong","Green curry"};
array<array<int,10>,5> responses = {0};

void collectRating(){
    for(int i = 0; i < dishes.size(); ++i){
        cout << "Poll" << i + 1 << " \n";
        for(int j = 0; j < dishes.size(); ++j){
            cout << "Rate " << dishes[j] << " on a scale from 1 to 10: ";
            int rating;
            while(true){
                cin >> rating;
                if( rating >= 1 && rating <= 10){
                    responses[j][rating - 1]++;
                    break;
                }else{
                    cout << "Invalid input for rating. Please enter again: ";
                }
            }
        }
    }
}

void displayResult(){
    cout << "Survey Results" << endl;
    cout << "Dish" << setw(20-4);
    for(int i = 0; i < 10; ++i){
        cout << i + 1 << setw(5);
    }
    int highestTotal = 0, lowestTotal = 5 * 5, highestIndex = 0, lowestIndex = 0;

    cout << setw(10) <<"Average" << endl;
    for(int i = 0; i < 5; ++i){
        cout << dishes[i] << setw(20-dishes[i].length());
        double total = 0.0;
        double avg = 0;
        for(int j = 0; j < 10; ++j){
            avg += (j+1) * responses[i][j];
            cout << responses[i][j] << setw(5);
            total += (j + 1) * responses[i][j];

        }
        cout << setw(10) << avg/5;
        cout << endl;
        if (total > highestTotal) {
            highestTotal = total;
            highestIndex = i;
        }
        if (total < lowestTotal) {
            lowestTotal = total;
            lowestIndex = i;
        }
    }
    cout << "\nHighest rated dish: " << dishes[highestIndex] << " (score: " << highestTotal << ")\n";
    cout << "Lowest rated dish: " << dishes[lowestIndex] << " (score: " << lowestTotal << ")\n";
}
int main(){
    collectRating();
    displayResult();
    // cout << responses[0][0];

    return 0;
}