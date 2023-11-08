#include "bstree.h"

template < class DT, class KF >
BSTreeNode<DT, KF>::BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
    : dataItem(nodeDataItem), left(leftPtr), right(rightPtr)
{
}

template < class DT, class KF >
BSTree<DT, KF>::BSTree()
    : root(nullptr)
{
}

template < class DT, class KF >
BSTree<DT, KF>::~BSTree()
{
    clear();
}

//--------------------------------------------------------------------

// Insert

template < class DT, class KF >
void BSTree<DT, KF>::insert(const DT& newDataItem)
{
    if (isFull())
        cout << "Element cannot be inserted" << endl;
    else
        insertSub(root, newDataItem);
}

template < class DT, class KF >
void BSTree<DT, KF>::insertSub(BSTreeNode<DT, KF>*& p, const DT& newDataItem)
{
    if (p == nullptr)
        p = new BSTreeNode<DT, KF>(newDataItem, nullptr, nullptr);
    else if (p->dataItem.getKey() < newDataItem.getKey())
        insertSub(p->right, newDataItem);
    else if (p->dataItem.getKey() > newDataItem.getKey())
        insertSub(p->left, newDataItem);
    else
        p->dataItem = newDataItem;
}

//--------------------------------------------------------------------

// Retrieve

template < class DT, class KF >
bool BSTree<DT, KF>::retrieve(KF searchKey, DT& searchDataItem) const
{
    return retrieveSub(root, searchKey, searchDataItem);
}

template < class DT, class KF >
bool BSTree<DT, KF>::retrieveSub(BSTreeNode<DT, KF>* p, KF searchKey, DT& searchDataItem) const
{
    if (p == nullptr)
        return false;
    else if (p->dataItem.getKey() < searchKey)
        return retrieveSub(p->right, searchKey, searchDataItem);
    else if (p->dataItem.getKey() > searchKey)
        return retrieveSub(p->left, searchKey, searchDataItem);
    else
    {
        searchDataItem = p->dataItem;
        return true;
    }
}

//--------------------------------------------------------------------

// Remove

template < class DT, class KF >
bool BSTree<DT, KF>::remove(KF deleteKey)
{
    return removeSub(root, deleteKey);
}

template < class DT, class KF >
bool BSTree<DT, KF>::removeSub(BSTreeNode<DT, KF>*& p, KF deleteKey)
{
    if (p == nullptr)
        return false;
    else if (p->dataItem.getKey() < deleteKey)
        return removeSub(p->right, deleteKey);
    else if (p->dataItem.getKey() > deleteKey)
        return removeSub(p->left, deleteKey);
    else
    {
        BSTreeNode<DT, KF>* tempPtr = p;

        if (p->left == nullptr)
            p = p->right;
        else if (p->right == nullptr)
            p = p->left;
        else
            cutRightmost(p->left, tempPtr);

        delete tempPtr;
        return true;
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr)
{
    if (r->right != nullptr)
        cutRightmost(r->right, delPtr);
    else
    {
        delPtr->dataItem = r->dataItem;
        delPtr = r;
        r = r->left;
    }
}

//--------------------------------------------------------------------

// Write Keys

template < class DT, class KF >
void BSTree<DT, KF>::writeKeys() const
{
    if (!isEmpty())
        writeKeysSub(root);
}

template < class DT, class KF >
void BSTree<DT, KF>::writeKeysSub(BSTreeNode<DT, KF>* p) const
{
    if (p != nullptr)
    {
        writeKeysSub(p->left);
        cout << p->dataItem.getKey() << " ";
        writeKeysSub(p->right);
    }
}

//--------------------------------------------------------------------

// Clear

template < class DT, class KF >
void BSTree<DT, KF>::clear()
{
    clearSub(root);
    root = nullptr;
}

template < class DT, class KF >
void BSTree<DT, KF>::clearSub(BSTreeNode<DT, KF>* p)
{
    if (p != nullptr)
    {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

// Empty / Full

template < class DT, class KF >
bool BSTree<DT, KF>::isEmpty() const
{
    return (root == nullptr);
}

template < class DT, class KF >
bool BSTree<DT, KF>::isFull() const
{
    BSTreeNode<DT, KF>* location = new BSTreeNode<DT, KF>(DT(), nullptr, nullptr);

    if (location == nullptr)
        return true;
    else
    {
        delete location;
        return false;
    }
}

//--------------------------------------------------------------------

// Show Structure

template < class DT, class KF >
void BSTree<DT, KF>::showStructure() const
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

template < class DT, class KF >
void BSTree<DT, KF>::showSub(BSTreeNode<DT, KF>* p, int level) const
{
    int j;   // Loop counter

    if (p != 0)
    {
        showSub(p->right, level + 1);         // Output right subtree
        for (j = 0; j < level; j++)    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.getKey();  // Output key
        if ((p->left != 0) &&           // Output "connector"
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);          // Output left subtree
    }
}

//--------------------------------------------------------------------

// In-lab 2
template < class DT, class KF >
int BSTree<DT, KF>::getHeight() const
{
    return getHeightSub(root);
}

template < class DT, class KF >
int BSTree<DT, KF>::getHeightSub(BSTreeNode<DT, KF>* p) const
{
    if (p != nullptr)
    {
        int leftLevel = getHeightSub(p->left);
        int rightLevel = getHeightSub(p->right);
        return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
    }
    else
        return 0;
}

//--------------------------------------------------------------------

// In-lab 3
template < class DT, class KF >
void BSTree<DT, KF>::writeLessThan(KF searchKey) const
{
    writeLTSub(root, searchKey);
}

template < class DT, class KF >
void BSTree<DT, KF>::writeLTSub(BSTreeNode <DT, KF>* p, const KF searchKey) const
{
    if (p == nullptr)
        return;

    KF key = p->dataItem.getKey();
    writeLTSub(p->left, searchKey);
    if (key < searchKey)
    {
        cout << key << " ";
        writeLTSub(p->right, searchKey);
    }
}