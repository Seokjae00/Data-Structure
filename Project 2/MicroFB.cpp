#include "MFB.h"

void print_help()
{
    cout << "P <Name> - Create a person record of the specified name." << endl;
    cout << "F <Name1> <Name2> - Record that the two specified people are friends." << endl;
    cout << "U <Name1> <Name2> - Record that the two specified people are no longer friends." << endl;
    cout << "L <Name> - Print out the friends of the specified person." << endl;
    cout << "Q <Name1> <Name2> - Check whether the two people are friends." << endl;
    cout << "X - terminate the program." << endl;
    cout << endl;
}


int main(void)
{
    MFB mfb;
    string name1, name2;
    char cmd;

    print_help();

    do
    {
        cin >> cmd;
        if (cmd == 'P' || cmd == 'p' || cmd == 'L' || cmd == 'l')
            cin >> name1;
        else if (cmd == 'F' || cmd == 'f' || cmd == 'U' || cmd == 'u' || cmd == 'Q' || cmd == 'q')
            cin >> name1 >> name2;

        switch (cmd)
        {
        case 'H': case 'h':
            print_help();
            break;

        case 'P': case 'p':
            mfb.createPerson(name1);
            break;

        case 'F': case 'f':
            mfb.beFriend(name1, name2);
            break;

        case 'U': case 'u':
            mfb.unFriend(name1, name2);
            break;

        case 'L': case 'l':
            mfb.printFriend(name1);
            break;

        case 'Q': case 'q':
            if (mfb.isFriend(name1, name2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;

        case 'X': case 'x':
            break;

        default:
            cout << "Inactive or invalid command" << endl;
        }
    } while (cmd != 'X' && cmd != 'x');

    return 0;
}