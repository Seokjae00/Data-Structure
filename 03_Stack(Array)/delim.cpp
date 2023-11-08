//--------------------------------------------------------------------
//
//  Laboratory 5 (In-lab 3 shell)                          delim.cs
//
//  Program validates delimiter pairing.
//
//--------------------------------------------------------------------

#include <iostream>
#include "stackarr.cpp"

//--------------------------------------------------------------------
//
//  Function prototype

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main(void)
{
    system("cls");
    string inputLine;            // Input line
    char ch;                     // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : ";
             //<< endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }
    
        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl << endl;
        else
            cout << "Invalid" << endl << endl;
    }

    return 0;
}


bool delimitersOk(const string& expression)
{
    Stack<char> stack(1024);

    for (size_t i = 0; i < expression.length(); i++)
    {
        switch (expression[i])
        {
        case '(':
        case '[':
            if (stack.isFull())
                return false;
            else
                stack.push(expression[i]);

            break;

        case ')':
        case ']':
            if (stack.isEmpty())
                return false;
            else
            {
                char delim = stack.pop();

                if ((delim == '(' && expression[i] != ')') || (delim == '[' && expression[i] != ']'))
                    return false;
            }

            break;
        }
    }

    if (!stack.isEmpty())
        return false;
    else
        return true;
}