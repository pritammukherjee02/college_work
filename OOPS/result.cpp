#include <iostream>
using namespace std;

// parent class
class Student {
    protected:
        int roll_number;
    public:
        void set_roll_number(int rn) {
            roll_number = rn;
        }
};

// child class 1
class Test : public Student {
    protected:
        int marks1, marks2;
    public:
        void set_marks(int m1, int m2) {
            marks1 = m1;
            marks2 = m2;
        }
        int get_total_marks() {
            return marks1 + marks2;
        }
};

// child class 2
class Sports : public Student {
    protected:
        int score;
    public:
        void set_score(int s) {
            score = s;
        }
        int get_score() {
            return score;
        }
};

// derived class
class Result : public Test, public Sports {
    public:
        void display_result() {
            cout << "Roll Number: " << Student::roll_number << endl;
            cout << "Marks 1: " << marks1 << endl;
            cout << "Marks 2: " << marks2 << endl;
            cout << "Total Marks: " << get_total_marks() << endl;
            cout << "Sports Score: " << get_score() << endl;
        }
};

int main() {
    Result r;
    r.Student::set_roll_number(1001);
    r.set_marks(85, 90);
    r.set_score(75);
    r.display_result();
    return 0;
}
