// Online C++ compiler to run C++ program online
#include <iostream>
#include<string.h>

class Employee{
    public:
    char *name;
    int age;
    long salary;
    
    Employee(char *name, int age, long salary){
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
    
    static Employee** takeInputs(int count){
        Employee* emps[count];
        std::cout << "Enter details for Employees:" << std::endl;
        
        for(int i = 0; i < count; i++){
            char empName[50];
            int empAge;
            long empSalary;
            
            std::cout << "--Employee " << i+1 << std::endl;
            std::cout << "\tName: ";
            // std::cin >> empName;
            std::cin.getline(empName, 50);
            std::cout << "\tAge: ";
            std::cin >> empAge;
            std::cout << "\tSalary: ";
            std::cin >> empSalary;
            
            emps[i] = new Employee(empName, empAge, empSalary);
        }
        
        return emps;
    }
    
    static void printEmployees(Employee** emps){
        int size = sizeof(emps)/sizeof(Employee*);
        std::cout << "Name\tAge\tSalary" << std::endl;
        for(int i = 0; i < size; i++){
            std::cout << emps[i]->name << "\t" << emps[i]->age << "\t" << emps[i]->salary << std::endl;
        }
    }
};



int main() {
    // Write C++ code here
    Employee* emps;
    emps = *Employee::takeInputs(3);

    return 0;
}