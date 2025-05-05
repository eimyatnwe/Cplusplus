#include <iostream>
using namespace std;

class Point {
    private:
        int xCoordinate, yCoordinate;

    public:
        // Constructor
        Point(int x = 0, int y = 0) : xCoordinate(x), yCoordinate(y) {}

        // Getter functions
        int getXCoordinate() const { return xCoordinate; }
        int getYCoordinate() const { return yCoordinate; }

        // Stream insertion operator overload (friend function)
        friend std::ostream& operator<<(std::ostream& out, const Point& point) {
            out << "(" << point.xCoordinate << ", " << point.yCoordinate << ")";
            return out;
        }

        // Stream extraction operator overload (friend function)
        friend std::istream& operator>>(std::istream& inputs, Point& point) {
            int x, y;
            inputs >> x;
            if (inputs.bad()) {
                inputs.clear();
                inputs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return inputs;
            }
            inputs >> y;
            if (!inputs.good()) {
                inputs.clear(); 
                inputs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return inputs;
            }
            point.xCoordinate = x;
            point.yCoordinate = y;
            return inputs;
    }
};

int main() {
    Point point;
    // Input from the user
    std::cout << "Enter the coordinates of the point:" << std::endl;
    std::cin >> point;
    // Output the point
    std::cout << "The point is: " << point << std::endl;
    return 0;
}