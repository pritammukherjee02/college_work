#include <iostream>

using namespace std;

class CalculateArea{
    public:
    static double area(double base, double height){
        // Triangle
        return (0.5)*base*height;
    }

    static double area(double length, double breadth, char identifier){
        // Rectangle, identifier is necessary to distinguish between this and prev function
        return length*breadth;
    }

    static double area(double side){
        // Square
        return side*side;
    }

    static double area(double topLength, double bottomLength, double height){
        // Trapezium
        return ((topLength + bottomLength)/2)*height;
    }
};

int main()
{
    CalculateArea calc;

    cout << "Area of a triangle with height 12 and base 43: " << calc.area(12, 43) << endl;
    cout << "Area of a rectangle with sides 32 and 10: " << calc.area(32, 10, 'r') << endl;
    cout << "Area of a square with side 13: " << calc.area(13, 13) << endl;
    cout << "Area of a trapezium with top of 10, bottom of 23, and height 5: " << calc.area(10, 23, 5.0) << endl;

    return 0;
}