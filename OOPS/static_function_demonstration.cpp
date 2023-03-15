#include <iostream>

using namespace std;

class StaticDemonstration {
    public:
    static int var1;
    static void setA(int val){
        StaticDemonstration::var1 = val;
        // var1 = val;
    }

    static int getA(){
        // return var1;
        return StaticDemonstration::var1;
    }
};

int main()
{
    StaticDemonstration obj1, obj2, obj3;
    obj1.setA(12);
    cout << "var1's value is " << obj1.getA() << " after setting a using obj1" << endl;
    cout << "var1's value in obj2 is " << obj2.getA() << endl;

    obj2.setA(15);
    cout << "var1's value in obj1 is " << obj1.getA() << " after setting a using obj2" << endl;
    cout << "var1's value in obj3 is " << obj3.getA() << endl;

    return 0;
}