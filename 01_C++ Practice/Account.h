#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Bank
{
public:
    Bank();
    void createAccount();
    void deposit();
    void withdraw();
    void displayAccount();

private:
    string name;
    int acno;
    string actype;
    float balance;
};