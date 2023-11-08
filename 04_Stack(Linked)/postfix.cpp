#include "stacklnk.cpp"
#include <string>

double evaulate(string& postExpression)
{
	Stack<double> stack;

	for (int i = 0; i < postExpression.length(); i++)
	{
		char ch = postExpression[i];
		double op1, op2;

		if (ch == '+')
		{
			op2 = stack.pop();
			op1 = stack.pop();
			stack.push(op1 + op2);
		}
		else if (ch == '-')
		{
			op2 = stack.pop();
			op1 = stack.pop();
			stack.push(op1 - op2);
		}
		else if (ch == '*')
		{
			op2 = stack.pop();
			op1 = stack.pop();
			stack.push(op1 * op2);
		}
		else if (ch == '/')
		{
			op2 = stack.pop();
			op1 = stack.pop();
			stack.push(op1 / op2);
		}
		else
			stack.push(static_cast<double>(ch - '0'));
	}

	return stack.pop();
}

int main(void)
{
	while (cin)
	{
		string postExpression;
		cout << "Input postfix expression: ";
		cin >> postExpression;

		if (!cin)              // Reached EOF: stop processing
			break;

		cout << "result: " << evaulate(postExpression) << endl << endl;
	}

	return 0;
}