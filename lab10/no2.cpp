#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Polynomial {
private:
    vector<pair<int, int>> terms; 

   
    void simplify(vector<pair<int, int>>& terms) const {
        for (auto it = terms.begin(); it != terms.end(); ) {
            if (it->first == 0) {
                it = terms.erase(it); 
            } else {
                ++it;
            }
        }
        sort(terms.begin(), terms.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        });
    }


public:
   
    Polynomial() {}
    Polynomial(const vector<pair<int, int>>& terms) : terms(terms) {}

    
    ~Polynomial() {}

    
    vector<pair<int, int>> getTerms() const {
        return terms;
    }

    void setTerms(const vector<pair<int, int>>& newTerms) {
        terms = newTerms;
    }

    
    void setPoly(int coefficient, int exponent) {
        terms.push_back(make_pair(coefficient, exponent));
    }

    
    Polynomial operator+(const Polynomial& other) const {
        vector<pair<int, int>> resultTerms = terms;
        resultTerms.insert(resultTerms.end(), other.terms.begin(), other.terms.end());
        sort(resultTerms.begin(), resultTerms.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        });
        return Polynomial(resultTerms);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<pair<int, int>> resultTerms = terms;
        for (const auto& term : other.terms) {
            auto it = find_if(resultTerms.begin(), resultTerms.end(),
                [&term](const pair<int, int>& t) { return t.second == term.second; });
            if (it != resultTerms.end())
                it->first -= term.first;
            else
                resultTerms.push_back(make_pair(-term.first, term.second));
        }
        simplify(resultTerms); // Simplify the resulting terms
        return Polynomial(resultTerms);
    }
    
    Polynomial operator*(const Polynomial& other) const {
        vector<pair<int, int>> resultTerms;
        for (const auto& term1 : terms) {
            for (const auto& term2 : other.terms) {
                int coefficient = term1.first * term2.first;
                int exponent = term1.second + term2.second;
                auto it = find_if(resultTerms.begin(), resultTerms.end(),
                    [exponent](const pair<int, int>& t) { return t.second == exponent; });
                if (it != resultTerms.end())
                    it->first += coefficient;  // Combine terms with the same exponent
                else
                    resultTerms.push_back(make_pair(coefficient, exponent));
            }
        }
        simplify(resultTerms); // Simplify the resulting terms
        return Polynomial(resultTerms);
    }

    // Output operator for Polynomial
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        bool firstTerm = true;
        for (const auto& term : poly.terms) {
            if (!firstTerm && term.first >= 0)
                out << "+";
            out << term.first << "x^" << term.second;
            firstTerm = false;
        }
        return out;
    }
};

int main() {
    Polynomial p1;
    p1.setPoly(2, 3);
    p1.setPoly(4, 1);

    Polynomial p2;
    p2.setPoly(3, 2);
    p2.setPoly(5, 0);

    Polynomial p3 = p1 + p2;
    Polynomial p4 = p1 - p2;
    Polynomial p5 = p1 * p2;

    cout << "Polynomial p1: " << p1 << endl;
    cout << "Polynomial p2: " << p2 << endl;
    cout << "Polynomial p3 (p1 + p2): " << p3 << endl;
    cout << "Polynomial p4 (p1 - p2): " << p4 << endl;
    cout << "Polynomial p5 (p1 * p2): " << p5 << endl;

    return 0;
}
