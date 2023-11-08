//--------------------------------------------------------------------
//		Lab 12									exprtree.h
//
//  Class declarations for the linked implementation of the
//  Expression Tree ADT -- including the recursive partners of the
//  public member functions
//
//--------------------------------------------------------------------
#include <iostream>

using namespace std;

class ExprTree;			   // Forward declaration of the ExprTree class

class ExprTreeNode         // Facilitator class for the ExprTree class
{
private:

	// Constructor
	ExprTreeNode(char elem,
		ExprTreeNode* leftPtr, ExprTreeNode* rightPtr);

	// Data members
	char dataItem;          // Expression tree data item
	ExprTreeNode* left,     // Pointer to the left child
		* right;    // Pointer to the right child

	friend class ExprTree;
};

//--------------------------------------------------------------------

class ExprTree
{
public:

	// Constructor
	ExprTree();
	// Destructor
	~ExprTree();

	// Expression tree manipulation operations
	void build();              // Build tree from prefix expression
	void expression() const;   // Output expression in infix form
	float evaluate() const;    // Evaluate expression
	void clear();              // Clear tree

	// Output the tree structure -- used in testing/debugging
	void showStructure() const;

	// In-lab operations
	ExprTree(const ExprTree& valueTree);   // Copy constructor
	void commute();                       // Commute all subexpr.

private:

	// Recursive partners of the public member functions -- insert
	// prototypes of these functions here.
	void buildSub(ExprTreeNode*& p);
	void exprSub(ExprTreeNode* p) const;
	float evaluateSub(ExprTreeNode* p) const;
	void clearSub(ExprTreeNode* p);
	void showSub(ExprTreeNode* p, int level) const;

	// In-lab operations
	void copySub(ExprTreeNode*& dest, ExprTreeNode* source);
	void commuteSub(ExprTreeNode*& p);

	// Data member
	ExprTreeNode* root;   // Pointer to the root node
};