//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//
//--------------------------------------------------------------------

#include "exprtree.h"

//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
    : dataItem(elem), left(leftPtr), right(rightPtr)
{
}

//--------------------------------------------------------------------

ExprTree::ExprTree()
    : root(nullptr)
{
}

ExprTree::~ExprTree()
{
    clear();
}

//--------------------------------------------------------------------

void ExprTree::build()
{
    buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
    char ch;
    cin >> ch;

    p = new ExprTreeNode(ch, nullptr, nullptr);

    if (!isdigit(ch))
    {
        buildSub(p->left);
        buildSub(p->right);
    }
}

//--------------------------------------------------------------------

void ExprTree::expression() const
{
    exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
    if (p != nullptr)
    {
        if (!isdigit(p->dataItem))
            cout << '(';

        exprSub(p->left);
        cout << p->dataItem;
        exprSub(p->right);

        if (!isdigit(p->dataItem))
            cout << ')';
    }
}

//--------------------------------------------------------------------

float ExprTree::evaluate() const
{
    return evaluateSub(root);
}

float ExprTree::evaluateSub(ExprTreeNode* p) const
{
    float left, right, result = 0.0f;

    if (isdigit(p->dataItem))
        result = static_cast<float>(p->dataItem - '0');
    else
    {
        left = evaluateSub(p->left);
        right = evaluateSub(p->right);

        switch (p->dataItem)
        {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        }
    }

    return result;
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
    clearSub(root);
    root = nullptr;
}

void ExprTree::clearSub(ExprTreeNode* p)
{
    if (p != nullptr)
    {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const
{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

void ExprTree::showSub(ExprTreeNode* p, int level) const
{
    int j;

    if (p != 0)
    {
        showSub(p->right, level + 1);
        for (j = 0; j < level; j++)
            cout << "\t";
        cout << " " << p->dataItem;
        if ((p->left != 0) &&
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);
    }
}

//--------------------------------------------------------------------
ExprTree::ExprTree(const ExprTree& valueTree)
    : root(nullptr)
{
    copySub(root, valueTree.root);
}


void ExprTree::copySub(ExprTreeNode*& dest, ExprTreeNode* source)
{
    if (source == nullptr)
        return;

    dest = new ExprTreeNode(source->dataItem, nullptr, nullptr);
    copySub(dest->left, source->left);
    copySub(dest->right, source->right);
}

//--------------------------------------------------------------------
void ExprTree::commute()
{
    commuteSub(root);
}


void ExprTree::commuteSub(ExprTreeNode*& p)
{
    if (p == nullptr)
        return;

    if (!isdigit(p->dataItem))
    {
        ExprTreeNode* tmp = p->left;
        p->left = p->right;
        p->right = tmp;

        commuteSub(p->left);
        commuteSub(p->right);
    }
}