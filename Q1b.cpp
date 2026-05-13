#include<iostream>

using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount()  { balance = 0.0; }
    void Deposit(double amount){
        balance += amount;
    } 
    void Withdraw(double amount){
        if(amount > balance){
            cout << "Insufficient funds." << endl;
        }else{
            balance -= amount;
        }
    }
    double GetBalance()const {
        return balance;
    }
};

void PrintBalance(const BankAccount account);

int main(){
    BankAccount account;
    account.Deposit(1000);
    PrintBalance(account);
    account.Withdraw(500);
    PrintBalance(account);
    account.Withdraw(600);
    PrintBalance(account);

    return 0;
}

void PrintBalance(const BankAccount account){
    cout << "Current balance: " << account.GetBalance() << endl;
}