#include <iostream>
#include <string>
using namespace std;

class TemperatureConverter{
    public:
        double celsius;
        double fahrenheit;
        void toFahrenheit(double celsius){
            fahrenheit = celsius * (9.0/5.0) + 32.0;
        }
        void toCelsius(double fahrenheit){
            celsius =  (5.0/9.0) * (fahrenheit - 32.0);
        }
};

bool isNumber(const string &temp) {
    for (int i = 0; i < temp.length(); i++) {
        if (!(isdigit(temp[i]) || temp[i] == '.')) {
            return false;
        }
    }
    return true;
}

int main(){
    TemperatureConverter tempConverter;
    string temperature;
    char option;
    char choice;
   
    while(true){
        cout << "Enter temperature: ";
        cin >> temperature;
        if(!(isNumber(temperature))){
            cout << "Invalid input"<< endl;
        }
        else {
            cout << "Convert to (C)elsius or (F)ahrenheit? Enter C or F: ";
            cin >> option;
            double temp = stof(temperature);
            if (option == 'C' || option == 'c') {
                tempConverter.toCelsius(temp);
                cout << temp << " Fahrenheit is " << tempConverter.celsius << " Celsius." << endl;
            }
            else if(option == 'F' || option == 'f') {
                tempConverter.toFahrenheit(temp);
                cout << temp << " Celsius is " << tempConverter.fahrenheit << " Fahrenheit ." << endl;
            }
            cout << "Do you want to perform another conversion? (Y/N): ";
            cin >> choice;
            if(choice == 'N' || choice == 'n') {
                break;
            }
            else {
                continue;
            }
        }
    }
}