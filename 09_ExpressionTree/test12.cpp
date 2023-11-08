//--------------------------------------------------------------------
//		Lab 12									test.cpp
//
//  Test program for the operations in the Expression Tree ADT
//
//--------------------------------------------------------------------

#include "exprtree.h"

void dummy(ExprTree copyTree);   // copyTree is passed by value

int main(void)
{
	ExprTree testExpression;  // Test expression

	cout << endl << "Enter an expression in prefix form : ";

	testExpression.build();
	testExpression.showStructure();
	testExpression.expression();
	cout << " = " << testExpression.evaluate() << endl;

//  Test the copy constructor.   (In-lab Exercise 2)
	/*dummy(testExpression);
	cout << endl << "Original tree:" << endl;
	testExpression.showStructure();*/

//  Test the commute operation.  (In-lab Exercise 3)
	testExpression.commute();
	cout << endl << "Fully commuted tree: " << endl;
	testExpression.showStructure();
	testExpression.expression();
	cout << " = " << testExpression.evaluate() << endl;

	cout << endl << "Clear the tree" << endl;
	testExpression.clear();
	testExpression.showStructure();

	system("pause");

	return 0;
}

//--------------------------------------------------------------------

void dummy(ExprTree copyTree)

// Dummy routine that is passed an expression tree using call by
// value. Outputs copyTree and clears it.
 
{
	cout << endl << "Copy of tree:  " << endl;
	copyTree.showStructure();
	copyTree.clear();
	cout << "Copy cleared:   " << endl;
	copyTree.showStructure();
}