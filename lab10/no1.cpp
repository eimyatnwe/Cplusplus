#include <iostream>
#include <stdexcept>
using namespace std;
class Fraction{
    private:
        int numerator, denominator;
    public:
        Fraction(int num = 0, int deno = 1): numerator(num), denominator(deno){
            if(denominator == 0){
                throw invalid_argument("Denominator cannot be zero");
            simplify();
            }
           
        }

        void simplify(){
            int gcd = findGcd(numerator,denominator);
            numerator = numerator / gcd;
            denominator = denominator / gcd;
            if(denominator < 0){
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        int findGcd(int a, int b){
            if(b == 0){
                return a;
            }else{
                return findGcd(b,a % b);
            }
        }

         friend istream& operator>>(istream& in, Fraction& f){
            char slash;
            f.simplify();
            return in >> f.numerator >> slash >> f.denominator;
        }

        friend ostream& operator<<(ostream& out, const Fraction& f){
            
             out << f.numerator;
             if(f.denominator != 1)
                out << '/' << f.denominator;
            return out;

        }

        Fraction operator+(const Fraction& other) const{
            int nume = numerator * other.denominator + other.numerator * denominator;
            int deno = denominator * other.denominator;
            Fraction add(nume,deno);
            add.simplify();
            return add;
        }

        Fraction operator-(const Fraction& other) const{
            int nume = numerator * other.denominator - other.numerator * denominator;
            int deno = denominator * other.denominator;
            Fraction subtract(nume,deno);
            subtract.simplify();
            return subtract;
        }

        Fraction operator*(const Fraction& other) const{
            int nume = numerator * other.numerator;
            int deno = denominator * other.denominator;
            Fraction multiply(nume,deno);
            multiply.simplify();
            return Fraction(nume,deno);
        }

        Fraction operator/(const Fraction& other) const{
            if(other.numerator == 0){
                throw invalid_argument("Divide by zero");
            }
            int nume = numerator * other.denominator;
            int deno = denominator * other.numerator;
            Fraction divide(nume,deno);

            divide.simplify();
            return divide;
        }

        bool operator==(const Fraction& other) const{
            return numerator == other.numerator && denominator == other.denominator;
        }

        bool operator>(const Fraction& other) const{
            return numerator * other.denominator > denominator * other.numerator;
        }

        bool operator<(const Fraction& other) const{
            return numerator * other.denominator < denominator * other.numerator;
        }

};

int main(){
    Fraction f1,f2;
    cout << "Enter first fraction (a/b): ";
    cin >> f1;
    cout << "Enter second fraction (a/b): ";
    cin >> f2;

    f1.simplify();
    f2.simplify();

    Fraction sum = f1 + f2;
    Fraction subtract = f1 - f2;
    Fraction multiply = f1 * f2;
    Fraction divide = f1 / f2;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << subtract << endl;
    cout << "Multiply: " << multiply << endl;
    cout << "Division: " << divide << endl;

    if(f1 == f2) cout << "f1 is equal to f2" << endl;
    if(f1 > f2) cout << "f1 is greater than f2" << endl;
    if(f1 < f2) cout << "f1 is less than f2" << endl;

    return 0;
}