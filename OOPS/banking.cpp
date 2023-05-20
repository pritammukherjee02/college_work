#include <iostream>
#include <string>

using namespace std;

class Account {
    string name;
    string acc_number;

    public:
    string IFSC;
    string bank_name;
    float balance;

    void getDetails(){
        cout << "Account holder name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Account number: ";
        cin >> acc_number;
        cout << "Bank name: ";
        cin.ignore();
        getline(cin, bank_name);
        cout << "IFSC: ";
        cin >> IFSC;
    }
};

class SavingsAccount : public Account {
    int time_elapsed_in_years;

    protected:
    const float interest_rate = 0.04;

    public:
    SavingsAccount(){
        cout << "-----Savings Account-----" << endl;
        this->getDetails();
        cout << "Initial Balance: ";
        cin >> this->balance;
    }

    void calculateBalanceAfterYears(int yrs){
        for(int i = 0; i < yrs; i++)
        {
            balance += balance * interest_rate;
        }
    }

    void credit(float amt){
        // Adding money to the account
        balance += amt;
    }

    float debit(float amt){
        // Taking out money from the bank account
        balance -= amt;
        return amt;
    }

    float getBalance(){ return this->balance; }
};

class CurrentAccount : public Account {
    int time_elapsed_in_years;

    protected:
    const float interest_rate = 0.02;

    public:
    CurrentAccount(){
        cout << "-----Current Account-----" << endl;
        this->getDetails();
        cout << "Initial Balance: ";
        cin >> this->balance;
    }

    void calculateBalanceAfterYears(int yrs){
        for(int i = 0; i < yrs; i++)
        {
            balance += balance * interest_rate;
        }
    }

    void credit(float amt){
        // Adding money to the account
        balance += amt;
    }

    float debit(float amt){
        // Taking out money from the bank account
        balance -= amt;
        return amt;
    }

    float getBalance(){ return this->balance; }
};

class FDAccount : public Account {
    int time_elapsed_in_years;
    int period; // The minimum period for an FD

    public:
    void put(float amt){
        this->balance += amt;
    }

    float getBalance(){ return this->balance; }
};

class ShortTermFDAccount : public FDAccount {
    const float interest_rate = 0.07;
    int period;
    
    public:
    ShortTermFDAccount(int period){
        this->period = period;
    }

    float calculateBalanceAtPeriod(){
        for(int i = 0; i < period; i++){
            this->balance += this->balance * interest_rate;
        }
        return this->balance;
    }
};

class MediumTermFDAccount : public FDAccount {
    const float interest_rate = 0.09;
    int period;
    
    public:
    MediumTermFDAccount(int period){
        this->period = period;
    }

    float calculateBalanceAtPeriod(){
        for(int i = 0; i < period; i++){
            this->balance += this->balance * interest_rate;
        }
        return this->balance;
    }
};

class LongTermFDAccount : public FDAccount {
    const float interest_rate = 0.12;
    int period;

    public:
    LongTermFDAccount(int period){
        this->period = period;
    }

    float calculateBalanceAtPeriod(){
        for(int i = 0; i < period; i++){
            this->balance += this->balance * interest_rate;
        }
        return this->balance;
    }
};

int main(){
    cout << "Savings Account Instance:\n" << endl;
    SavingsAccount sAcc1;
    cout << "How many years later?: ";
    int yrs;
    cin >> yrs;
    sAcc1.calculateBalanceAfterYears(yrs);
    cout << "The money that stays in Savings Account: " << sAcc1.getBalance() << endl << endl;

    cout << "Current Account Instance:\n" << endl;
    CurrentAccount cAcc1;
    cout << "How many years later?: ";
    cin >> yrs;
    cAcc1.calculateBalanceAfterYears(yrs);
    cout << "The money that stays in Savings Account: " << cAcc1.getBalance() << endl << endl;

    cout << "-----Short Term FD Account-----\n" << endl;
    float money;
    cout << "How much money to put?: ";
    cin >> money;
    ShortTermFDAccount sFDAcc1(5);
    sFDAcc1.put(money);
    cout << "At the end of term: " << sFDAcc1.calculateBalanceAtPeriod() << endl << endl;

    cout << "-----Medium Term FD Account-----\n" << endl;
    cout << "How much money to put?: ";
    cin >> money;
    MediumTermFDAccount mFDAcc1(10);
    mFDAcc1.put(money);
    cout << "At the end of term: " << mFDAcc1.calculateBalanceAtPeriod() << endl << endl;

    cout << "-----Long Term FD Account-----\n" << endl;
    cout << "How much money to put?: ";
    cin >> money;
    LongTermFDAccount lFDAcc1(10);
    lFDAcc1.put(money);
    cout << "At the end of term: " << lFDAcc1.calculateBalanceAtPeriod() << endl << endl;

    return 0;
}