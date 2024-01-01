#include <iostream>
#include <string>

using namespace std;


class HeartRates {
public:
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
    int maxRate;
    int minRange;
    int maxRange;

    HeartRates(string firstN, string lastN, int birthM, int birthD, int birthY) {
        firstName = firstN;
        lastName = lastN;
        birthMonth = birthM;
        birthDay = birthD;
        birthYear = birthY;
    }

    int calcPersonage() const {
        int fixedYear = 2023;
        int fixedMonth = 12;
        int fixedDay = 28;

        int age = fixedYear - birthYear;
    
        if (fixedMonth < birthMonth || (fixedMonth == birthMonth && fixedDay < birthDay)) {
            age--;
        }

        return age;
    }

    void calcMaxrate() {
        maxRate = 220 - calcPersonage();
        minRange = static_cast<int>(maxRate * 0.50);
        maxRange = static_cast<int>(maxRate * 0.85);
    }


    void displayInformation(){
        cout << "Hello, " << calcPersonage() << " years old " << firstName << " " << lastName << "." << endl;
        cout << "Your maximum heart rate should be " << maxRate << " beats per minute." << endl;
        
        cout << "Your target heart rate range is " << minRange << " - " << maxRange<< " beats per minute";
        }
};

int main() {
    string firstName, lastName;
    int year, month, day;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your birth year (YYYY): ";
    cin >> year;
    cout << "Enter your birth month (MM): ";
    cin >> month;
    cout << "Enter your birth day (DD): ";
    cin >> day;

    HeartRates Hearts(firstName, lastName, month, day, year);
    Hearts.calcMaxrate();
    Hearts.displayInformation();
   return 0;
}
