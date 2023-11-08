#include "Account.h"

int main(void)
{
    Bank bank;
    int choice = 1;
    while (choice != 0)
    {
        cout << "Enter 0 to exit\n1. Create a new account\n2. Deposit\n3. Withdraw\n4. See Account Status\n";
        cin >> choice;

        cout << endl;
        switch (choice)
        {
        case 0:
            bank.displayAccount();
            cout << "EXITING PROGRAM" << endl;
            break;
        case 1:
            bank.createAccount();
            cout << endl;
            break;
        case 2:
            bank.deposit();
            cout << endl;
            break;
        case 3:
            bank.withdraw();
            cout << endl;
            break;
        case 4:
            bank.displayAccount();
            cout << endl;
            break;
        default:
            cout << "Illegal Option" << endl;
            cout << endl;
        }
    }
    
    system("PAUSE");

    return 0;
}