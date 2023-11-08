#include "Account.h"

Bank::Bank()
    :acno(0), name(""), balance(0)
{
}

void Bank::createAccount()
{
    cout << "New Account" << endl;
    balance = 0;
    cout << "Enter the Name of the depositor : ";
    cin >> name;

    cout << "Enter the Account Number : ";
    cin >> acno;

    cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) ";
    cin >> actype;

    cout << "Enter the Amount to Deposit : ";
    float amount;
    cin >> amount;
    balance += amount;
}

void Bank::deposit()
{
    cout << "Depositing" << endl;
    cout << "Enter the amount to deposit : ";
    float amount;
    cin >> amount;
    balance += amount;
}

void Bank::withdraw()
{
    cout << "Withdrawal" << endl;
    float amount = 0;
    cout << "Enter the amount to withdraw : ";
    cin >> amount;
    balance -= amount;
}

void Bank::displayAccount()
{
    cout << "Account Details" << endl;
    cout << "Name of the depositor : " << this->name << endl;
    cout << "Account Number        : " << this->acno << endl;
    cout << "Account Type          : " << this->actype << endl;
    cout << "Balance               : $" << int(this->balance) << endl;
}