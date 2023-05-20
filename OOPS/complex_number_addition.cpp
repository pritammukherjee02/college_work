#include <iostream>

using namespace std;

class Complex{
    float a, b;

    public:
    Complex();
    Complex(float real, float complex){
        this->a = real;
        this->b = complex;
    }

    void print(){
        if(this->b > 0){
            cout << this->a << " + " << this->b << "i" << endl;

        } else if (this->b < 0){
            cout << this->a << " - " << -1*(this->b) << "i" << endl;
        } else cout << this->a << endl;
    }

    friend Complex operator + (Complex const &num1, Complex const &num2);
};

Complex operator + (Complex const &num1, Complex const &num2){
    Complex result(num1.a + num2.a, num1.b + num2.b);
    return result;
}

int main()
{
    Complex c1(12, 3), c2(10, 5);
    cout << "Complex number 1: ";
    c1.print();

    cout << "Complex number 2: ";
    c2.print();

    cout << "Adding the numbers:" << endl;

    Complex res = c1 + c2;
    res.print();
    
    return 0;
}