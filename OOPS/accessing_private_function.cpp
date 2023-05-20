#include <iostream>

using namespace std;

class SomeClass{
    private:
    int a;
    void doSomething(int num){
        this->a = num;
    }

    public:
    SomeClass(){}
    void printNum(){
        cout << this->a << endl;
    }

    void changeNum(int num){
        doSomething(num);
    }
};

int main()
{
    SomeClass obj;
    obj.changeNum(12);
    obj.printNum();

    return 0;
}